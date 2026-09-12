#include "TrainerFunctions.h"
#include "SkinSettings.h"
void noFlash(bool on)
{
	if (!on)
	{
		return;
	}
	static bool status;
	static DWORD localPlayer, engineClient = memory.Read<DWORD>(getEnginedll(L"engine.dll") + dwClientState);
	{
		status = (memory.Read<DWORD>(engineClient + dwClientState_State)) == 6;
		if (!status)
		{
			return;
		}
		localPlayer = memory.Read<DWORD>(GetClientModule(L"client_panorama.dll") + dwLocalPlayer);
		if (memory.Read<float>(localPlayer + m_flFlashMaxAlpha) > 0.f)
		{
			memory.Write<float>(localPlayer + m_flFlashMaxAlpha, 0.f);
		}
	}
}

void bunnyHop()
{

	bool status, toggle = true;
	char fFlag;
	DWORD engineClient = memory.Read<DWORD>(getEnginedll(L"engine.dll") + dwClientState), localPlayer;
	while(true)
	{
		status = (memory.Read<DWORD>(engineClient + dwClientState_State)) == 6;
		if (!status )
		{
			continue ;
		}
		localPlayer = memory.Read<DWORD>(GetClientModule(L"client_panorama.dll") + dwLocalPlayer);
		fFlag = memory.Read<char>(localPlayer + m_fFlags);
		if (GetAsyncKeyState(VK_SPACE))
		{
			if (fFlag == 1 || fFlag == 3)
			{
				memory.Write<BYTE>(GetClientModule(L"client_panorama.dll") + dwForceJump, 6);
				if (toggle)
				{
					keybd_event(0x44, MapVirtualKey('D', MAPVK_VK_TO_VSC), 1, 0); // d down
					Sleep(1);
					for (int i = 0; i < 300; i++)
					{
						mouse_event(1, 3, 0, 0, 0); // move mouse right
						Sleep(1);
					}
					keybd_event(0x44, MapVirtualKey('D', MAPVK_VK_TO_VSC), 2, 0); // d up
				}
				else
				{
					keybd_event(0x41, MapVirtualKey('A', MAPVK_VK_TO_VSC), 1, 0); // d down
					Sleep(1);
					for (int i = 0; i < 300; i++)
					{
						mouse_event(1, -3, 0, 0, 0); // move mouse right
						Sleep(1);
					}
					keybd_event(0x41, MapVirtualKey('A', MAPVK_VK_TO_VSC), 2, 0); // d up
				}
				toggle = !toggle;
			}
		}
		else
		{
			toggle = true;
		}
		Sleep(1);
	}
}
bool bCompare(const BYTE* Data, const BYTE* Mask, const char* szMask)
{
	for (; *szMask; ++szMask, ++Mask, ++Data)
	{
		if (*szMask == 'x' && *Mask != *Data)
		{
			return false;
		}
	}
	return (*szMask) == 0;
}

DWORD FindPattern(BYTE* Mask, char* szMask)
{
	DWORD Address = GetClientModule(L"client_panorama.dll");
	DWORD Length = clientDLL.dwSize;
	BYTE *bulk = new BYTE[Length];
	memory.RPM(Address, bulk, Length);
	for (DWORD c = 0; c < Length; c += 1)
	{
		if (bCompare((BYTE*)(bulk + c), Mask, szMask))
		{
			return (DWORD)(Address + c);
		}
	}
	return 0;
}
void autoAcceptMatch()
{

	HWND Hwnd;
	bool inGame;
	const char *t = "";
	DWORD dw_CLobbyScreen = FindPattern((PBYTE)"\xA1\x00\x00\x00\x00\x85\xC0\x74\x0F\x6A\x00", (char*)"x????xxxxxx") + 0x1;
	DWORD dw_MatchFound = FindPattern((PBYTE)"\x89\x87\x00\x00\x00\x00\x8B\x87\x00\x00\x00\x00\x3B\xF0 ", (char*)"xx????xx????xx") + 0x2;
	DWORD engineClient = memory.Read<DWORD>(getEnginedll(L"engine.dll") + dwClientState);
	DWORD inLobbyScreen, matchFound;
	static auto SetLocalPlayerReadyFn = reinterpret_cast<bool(__stdcall*)(const char*)>(FindPattern((PBYTE)"\x55\x8B\xEC\x83\xE4\xF8\x8B\x4D\x08\xBA\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x85\xC0\x75\x12", (char*)"xxxxxxxxxx????x????xxxx"));
	while (true)
	{
		Hwnd = FindWindow(NULL, L"Counter-Strike: Global Offensive");
		inGame = (memory.Read<DWORD>(engineClient + dwClientState_State)) == 6;
		if (inGame && GetForegroundWindow() != Hwnd)
		{
			FLASHWINFO fi;
			fi.cbSize = sizeof(FLASHWINFO);
			fi.hwnd = Hwnd;
			fi.dwFlags = FLASHW_ALL | FLASHW_TIMERNOFG;
			fi.uCount = 0;
			fi.dwTimeout = 0;
			FlashWindowEx(&fi);
		}
		else if (Hwnd && !inGame) // Gets the csgo window and checks if the active window is csgos window // EDIT: Changed from Valve001 to Counter-Strike: Global Offensive.
		{
			inLobbyScreen = memory.Read<DWORD>(GetClientModule(L"client_panorama.dll") + dw_CLobbyScreen);
			matchFound = memory.Read<DWORD>(GetClientModule(L"client_panorama.dll") + dw_MatchFound);
			if (inLobbyScreen != 0 && matchFound != 0 && SetLocalPlayerReadyFn)
			{
				//SetLocalPlayerReadyFn("");
				HANDLE h = CreateRemoteThread(memory.handleToProcess, NULL, 0, (LPTHREAD_START_ROUTINE)SetLocalPlayerReadyFn, &t, 0, NULL);
				WaitForSingleObject(h, 0xFFFFFFFF);
				CloseHandle(h);
			}

		}
		Sleep(10000);
	}
}


void radarHack(bool on)
{
	if (!on)
	{
		return ;
	}
	static DWORD localPlayer, engineClient, localTeam, entity, entityTeam, entityHealth;
	static bool status, isDormant, isSpotted;
	engineClient = memory.Read<DWORD>(getEnginedll(L"engine.dll") + dwClientState);

	{
		status = (memory.Read<DWORD>(engineClient + dwClientState_State)) == 6;
		if (!status)
		{
			return ;
		}
		for (int i = 1; i < 33; i++)
		{
			entity = memory.Read<DWORD>(GetClientModule(L"client_panorama.dll") + dwEntityList + ((i - 1) * 0x10));
			isDormant = memory.Read<bool>(entity + m_bDormant);

			entityTeam = memory.Read<DWORD>(entity + dwTeam);
			entityHealth = memory.Read<DWORD>(entity + dwHealth);
			localPlayer = memory.Read<DWORD>(GetClientModule(L"client_panorama.dll") + dwLocalPlayer);
			localTeam = memory.Read<DWORD>(localPlayer + dwTeam);
			if (!isDormant && entityHealth >= 1 && entityTeam != localTeam)
			{
				memory.Write<bool>(entity + m_bSpotted, true);
			}
		}
	}
}

void triggerbot(bool on, bool autoFire, int key, int delay)
{
	static DWORD localPlayer, engineClient, localTeam, crosshairId, enemyInCrosshair, enemyTeam, myTeam, enemyHealth;
	static bool status, isDormant, isSpotted;
	engineClient = memory.Read<DWORD>(getEnginedll(L"engine.dll") + dwClientState);
	//oyvhgyy *junk = new oyvhgyy();

	{
		status = (memory.Read<DWORD>(engineClient + dwClientState_State)) == 6;
		if (!status || (!on))
		{
			return;
		}
		localPlayer = memory.Read<DWORD>(GetClientModule(L"client_panorama.dll") + dwLocalPlayer);
		crosshairId = memory.Read<DWORD>(localPlayer + dwCrosshairId);
		enemyInCrosshair = memory.Read<DWORD>(GetClientModule(L"client_panorama.dll") + dwEntityList + (crosshairId - 1) * 0x10);
		enemyTeam = memory.Read<DWORD>(enemyInCrosshair + dwTeam);
		myTeam = memory.Read<DWORD>(localPlayer + dwTeam);
		enemyHealth = memory.Read<DWORD>(enemyInCrosshair + dwHealth);
		if (crosshairId >= 0 && crosshairId <= 64 && enemyTeam != myTeam && enemyHealth >= 1)
		{
			if (GetAsyncKeyState(key) || autoFire)
			{
				Sleep(delay);
				memory.Write<DWORD>(GetClientModule(L"client_panorama.dll") + dwForceAttack, 1);
				Sleep(2);
				memory.Write<DWORD>(GetClientModule(L"client_panorama.dll") + dwForceAttack, 0);
			}
		}

	}
}

void afk(bool on)
{
	if (!on)
	{
		return;
	}
	{
		mouse_event(1, 1, 0, 0, 0);
		mouse_event(1, -1, 0, 0, 0);
	}
}

void fakeLag(System::Object^ delay)
{
	bool status;
	DWORD engineClient = memory.Read<DWORD>(getEnginedll(L"engine.dll") + dwClientState);
	while (true)
	{
		status = (memory.Read<DWORD>(engineClient + dwClientState_State)) == 6;
		if (!status)
		{
			Sleep(200);
			continue;
		}
		memory.Write<BYTE>(getEnginedll(L"engine.dll") + dwbSendPackets, 0);
		Sleep(System::Convert::ToInt32(delay));
		memory.Write<BYTE>(getEnginedll(L"engine.dll") + dwbSendPackets, 1);
		Sleep(System::Convert::ToInt32(delay));
	}
}
