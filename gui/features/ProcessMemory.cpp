#include "ProcessMemory.h"
process memory;
PModule clientDLL{}, engineDLL{};

process::~process()
{
    if (handleToProcess) CloseHandle(handleToProcess);
}

bool process::Attach(LPCWSTR name, DWORD rights)
{
    HWND window = FindWindow(nullptr, name);
    if (!window) return false;
    DWORD id = 0;
    GetWindowThreadProcessId(window, &id);
    HANDLE handle = OpenProcess(rights, FALSE, id);
    if (!handle) return false;
    if (handleToProcess) CloseHandle(handleToProcess);
    handleToProcess = handle;
    pID = id;
    return true;
}

namespace {
DWORD FindModule(const wchar_t* name, PModule& cache)
{
    if (cache.dwBase) return cache.dwBase;
    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, memory.pID);
    if (snapshot == INVALID_HANDLE_VALUE) return 0;
    MODULEENTRY32 entry{};
    entry.dwSize = sizeof(entry);
    if (Module32First(snapshot, &entry)) {
        do {
            if (wcscmp(entry.szModule, name) == 0) {
                cache.dwBase = static_cast<DWORD>(reinterpret_cast<ULONG_PTR>(entry.modBaseAddr));
                cache.dwSize = entry.modBaseSize;
                break;
            }
        } while (Module32Next(snapshot, &entry));
    }
    CloseHandle(snapshot);
    return cache.dwBase;
}
}

DWORD getEnginedll(const wchar_t* name) { return FindModule(name, engineDLL); }
DWORD GetClientModule(const wchar_t* name) { return FindModule(name, clientDLL); }
