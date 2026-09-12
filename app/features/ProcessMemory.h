#pragma once
#include "../Header.h"
class process
{

public:
	HANDLE handleToProcess = nullptr;
	DWORD pID = 0;
    process() = default;
    ~process();
    process(const process&) = delete;
    process& operator=(const process&) = delete;
    bool Attach(LPCWSTR pName, DWORD rights);

	template <class T>
	void RPM(DWORD addr, T* ptr, DWORD size)
	{
		ReadProcessMemory(handleToProcess, (LPVOID)addr, ptr, size, NULL);
	}
	template <class T>
	T Read(DWORD addr) {
		T _read{};
		ReadProcessMemory(handleToProcess, (LPVOID)addr, &_read, sizeof(T), NULL);
		return _read;
	}
	template <class T>
	void Write(DWORD addr, T val) {
		WriteProcessMemory(handleToProcess, (LPVOID)addr, &val, sizeof(T), NULL);
	}

};
extern process memory;
struct PModule
{
	DWORD dwBase;
	DWORD dwSize;
};
extern PModule clientDLL, engineDLL;

DWORD getEnginedll(const wchar_t* str);
DWORD GetClientModule(const wchar_t* str);
