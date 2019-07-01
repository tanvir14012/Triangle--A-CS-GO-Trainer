#pragma once
#include "Header.h"
#include "Offsets.h"
#include "ItemDefinition.h"
#include "SkinId.h"
class process
{

public:
	HANDLE handleToProcess;
	DWORD pID;
	bool Attach(LPCWSTR pName, DWORD rights)
	{
		HWND hWnd = FindWindow(NULL, pName);
		if (hWnd != NULL)
		{
			GetWindowThreadProcessId(hWnd, &pID);
			handleToProcess = OpenProcess(rights, false, pID);
			//printf("Successfully attatched the window\n");
			return true;
		}
		return false;

	}
	template <class T>
	void RPM(DWORD addr, T* ptr, DWORD size)
	{
		ReadProcessMemory(handleToProcess, (LPVOID)addr, ptr, size, NULL);
	}
	template <class T>
	T Read(DWORD addr) {
		T _read;
		ReadProcessMemory(handleToProcess, (LPVOID)addr, &_read, sizeof(T), NULL);
		return _read;
	}
	template <class T>
	void Write(DWORD addr, T val) {
		WriteProcessMemory(handleToProcess, (LPVOID)addr, &val, sizeof(T), NULL);
	}

};
process memory;
struct PModule
{
	DWORD dwBase;
	DWORD dwSize;
}clientDLL{ 0,0 }, engineDLL{ 0,0 };
DWORD getEnginedll(const wchar_t* str)
{
	if (engineDLL.dwBase == 0) {
		HANDLE module = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, memory.pID);
		MODULEENTRY32 mEntry;
		mEntry.dwSize = sizeof(mEntry);

		do
		{
			if (!wcscmp(mEntry.szModule, str))
			{
				//printf("engine.dll module found\n");
				engineDLL.dwBase = (DWORD)mEntry.hModule;
				engineDLL.dwSize = mEntry.modBaseSize;
				CloseHandle(module);
			}

			//wprintf(mEntry.szModule);
			//wprintf(L"\n");

		} while (Module32Next(module, &mEntry));
	}
	return engineDLL.dwBase;

}
DWORD GetClientModule(const wchar_t* str)
{
	if (clientDLL.dwBase == 0) {
		HANDLE module = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, memory.pID);
		MODULEENTRY32 mEntry;
		mEntry.dwSize = sizeof(mEntry);

		do
		{
			if (!wcscmp(mEntry.szModule, str))
			{
				//printf("engine.dll module found\n");
				clientDLL.dwBase = (DWORD)mEntry.hModule;
				clientDLL.dwSize = mEntry.modBaseSize;
				CloseHandle(module);
			}

			//wprintf(mEntry.szModule);
			//wprintf(L"\n");

		} while (Module32Next(module, &mEntry));
	}
	return clientDLL.dwBase;

}
typedef struct my_color
{
	double r = 0;
	double g = 0;
	double b = 0;
}myColor;
class virtualesp //: public oyvhgyy
{
private:
	
	//oyvhgyy *junk;
	static void glow_player(DWORD mObj, float r, float g, float b, float alpha)
	{
		memory.Write<float>(mObj + 0x4, r);
		memory.Write<float>(mObj + 0x8, g);
		memory.Write<float>(mObj + 0xC, b);
		memory.Write<float>(mObj + 0x10, alpha);
		memory.Write<BOOL>(mObj + 0x24, true);
		memory.Write<BOOL>(mObj + 0x25, false);
	}


public:

	void esp_thread(bool on, bool glow_friendly, myColor friendly_color, bool glow_enemy, myColor enemy_color, bool visibility_check, myColor visibility_color, float alpha)
	{
		if (!on)
		{
			return;
		}
		static DWORD pointerToGlow, entity, entityTeam, vTable, fN, ptr, classID, localPlayer, localTeam, mObj, localPlayerIndex;
		static bool spotted = false, toggle = false, isDormant;
		static DWORD enginePointer = memory.Read<DWORD>(getEnginedll(L"engine.dll") + dwClientState);
		{

			localPlayer = memory.Read<DWORD>(GetClientModule(L"client_panorama.dll") + dwLocalPlayer);
			for (int i = 1; i < 65; i++)
			{
				entity = memory.Read<DWORD>(GetClientModule(L"client_panorama.dll") + dwEntityList + ((i - 1) * 0x10));
				isDormant = memory.Read<bool>(entity + m_bDormant);

				vTable = memory.Read<DWORD>(entity + 0x8);
				fN = memory.Read<DWORD>(vTable + 0x8);
				ptr = memory.Read<DWORD>(fN + 0x1);
				classID = memory.Read<DWORD>(ptr + 0x14);
				if (!isDormant && classID == 38)
				{
					mObj = memory.Read<DWORD>(GetClientModule(L"client_panorama.dll") + dwGlow) + memory.Read<DWORD>(entity + m_iGlowIndex) * 0x38;
					entityTeam = memory.Read<DWORD>(entity + dwTeam);
					localPlayerIndex = memory.Read<DWORD>(enginePointer + dwClientState_GetLocalPlayer) + 1;
					//localTeam = memory.Read<DWORD>((memory.Read<DWORD>(GetClientModule(L"client_panorama.dll")+ dwEntityList + localPlayerIndex-1)) + dwTeam);
					localPlayer = memory.Read<DWORD>(GetClientModule(L"client_panorama.dll") + dwLocalPlayer);
					localTeam = memory.Read<DWORD>(localPlayer + dwTeam);
					spotted = (memory.Read<long>(entity + m_bSpottedByMask) & (0x1 << (localPlayerIndex - 1))) != 0;
					//printf("%d\n", localTeam);
					if (glow_friendly && (entityTeam == localTeam))
					{
						glow_player(mObj, friendly_color.r, friendly_color.g, friendly_color.b, alpha);
					}
					else if (glow_enemy &&  (entityTeam != localTeam))
					{
						glow_player(mObj, enemy_color.r, enemy_color.g, enemy_color.b, alpha);
					}
					if (visibility_check && (entityTeam != localTeam) && spotted )
					{
						glow_player(mObj, visibility_color.r, visibility_color.g, visibility_color.b, alpha);
					}
				}
			}
		}
	}
};

class Aimbot 
{
private:
	//oyvhgyy *junk;
	struct vector3 {
		float x = 0;
		float y = 0;
		float z = 0;
	};
	vector3 subtract(vector3 src, vector3 des)
	{
		vector3 ret;
		ret.x = des.x - src.x;
		ret.y = des.y - src.y;
		ret.z = des.z - src.z;
		return ret;
	}
	float vectorDistance(vector3 src, vector3 des)
	{
		return sqrt(pow(des.x - src.x, 2) + pow(des.y - src.y, 2) + pow(des.z - src.z, 2));
	}
	vector3 GetBonePosition(DWORD dwEntity, int iTargetBone)
	{

		DWORD BoneMatrix = memory.Read<DWORD>(dwEntity + m_dwBoneMatrix);

		//and this makes a vector with bone position
		vector3 Bone
		{
			memory.Read<float>(BoneMatrix + (0x30 * iTargetBone) + 0x0c),//x coordinate of the bone
			memory.Read<float>(BoneMatrix + (0x30 * iTargetBone) + 0x1c),		//y
			memory.Read<float>(BoneMatrix + (0x30 * iTargetBone) + 0x2c) 		//z
		};
		return Bone;
	}
	float vectorMagnitude(vector3 vector)
	{
		return sqrt(vector.x*vector.x + vector.y*vector.y);
	}
	vector3 addVectors(vector3 a, vector3 b)
	{
		return vector3{ a.x + b.x, a.y + b.y, a.z + b.z };
	}
	bool isAngleValid(vector3 angle)
	{
		if ((angle.x >= -89.0 && angle.x <= 89.0) && (angle.y >= -180.0f && angle.y <= 180.0f) && angle.z == 0)
		{
			return true;
		}
		return false;
	}
	void normalizeAngles(vector3 &angles)
	{
		if (angles.x > 89.0f && angles.x <= 180.0f)
			angles.x = 89.0f;
		while (angles.x > 180)
			angles.x -= 360;
		while (angles.x < -89.0f)
			angles.x = -89.0f;
		while (angles.y > 180)
			angles.y -= 360;
		while (angles.y < -180)
			angles.y += 360;
	}
	int getRandomBone()
	{

		srand(time(NULL));
		int var = rand() % 10 + 1;
		switch (var)
		{
		case 1: return BONE_HEAD;
		case 2: return BONE_NECK;
		case 3: return BONE_CHEST;
		case 4: return BONE_BELLY;
		case 5: return BONE_LOWERBELLY;
		case 6: return BONE_PELVIS;
		case 7: return BONE_LARM;
		case 8: return BONE_RARM;
		case 9: return BONE_WAIST;
		case 10: return BONE_WAIST2;
		}
	}
	int getLock(int index)
	{
		if (index == 3)
		{
			return getRandomBone();
		}
		else if (index == 2)
		{
			return BONE_BELLY;
		}
		else if (index == 1)
		{
			return BONE_CHEST;
		}
		else if (index == 0)
		{
			return BONE_HEAD;
		}
		else
		{
			return BONE_LARM;
		}
	}
	vector3 calculateAngles(DWORD enemyEntity, int lock)
	{

		float yaw, pitch;
		DWORD localPlayer = memory.Read<DWORD>(GetClientModule(L"client_panorama.dll") + dwLocalPlayer);
		vector3 localPlayerEye = addVectors(memory.Read<vector3>(localPlayer + m_vecOrigin),
			memory.Read<vector3>(localPlayer + m_vecViewOffset));
		vector3 enemyBone = GetBonePosition(enemyEntity, lock);

		vector3 vectorBetween = subtract(localPlayerEye, enemyBone);
		float r = vectorMagnitude(vectorBetween);
		pitch = atan2(vectorBetween.y, vectorBetween.x)* 57.2958; //y-axis
		yaw = atan2((-vectorBetween.z), r)* 57.2958;

		vector3 newViewangles = { yaw, pitch, 0 };
		normalizeAngles(newViewangles);

		vector3 punchAngle = memory.Read<vector3>(localPlayer + m_viewPunchAngle);
		punchAngle.x *= 2;
		punchAngle.y *= 2;
		newViewangles.x -= punchAngle.x;
		newViewangles.y -= punchAngle.y;

		return newViewangles;

	}
	void smooth(vector3 oldAngles, vector3 &newAngles, float smooth)
	{
		if (smooth < 1 || smooth > 50)
		{
			smooth = 5.0f;
		}
		newAngles.x = ((newAngles.x - oldAngles.x) / smooth) + oldAngles.x;
		newAngles.y = ((newAngles.y - oldAngles.y) / smooth) + oldAngles.y;
		newAngles.z = ((newAngles.z - oldAngles.z) / smooth) + oldAngles.z;
	}
	float maxAngleDifference(vector3 a, vector3 b)
	{
		return max(fabs(a.x - b.x), fabs(a.y - b.y));
	}
	float angleDifference(vector3 a, vector3 b)
	{
		return (fabs(a.x - b.x) + fabs(a.y - b.y));
	}
public:
	//Aimbot():oyvhgyy() 

	void startAimbot(bool on, bool autoFire, int aimKey, int fov, int smoother, int aimlock)
	{
		static DWORD localPlayer, localTeam, isInGame, entityHealth, entity, targetEntity, entityTeam, crosshairId, enemyInCrosshair, shotsFired;
		static DWORD localPlayerIndex, punchAngle, vTable, fN, ptr, classID;
		static bool spotted, lockedSpotted, toggle = false;
		static DWORD enginePointer = memory.Read<DWORD>(getEnginedll(L"engine.dll") + dwClientState);
		static bool status, isDormant = false, lockedIsDormant;
		static vector3 enemyAngle, aimAngle, currentAngle;
		static float distance, temp;
		//junk = new oyvhgyy();
		if (!on)
		{
			return;
		}

		{
			localPlayer = memory.Read<DWORD>(GetClientModule(L"client_panorama.dll") + dwLocalPlayer);
			localTeam = memory.Read<DWORD>(localPlayer + dwTeam);
			status = (memory.Read<DWORD>(enginePointer + dwClientState_State)) == 6;
			localPlayerIndex = memory.Read<DWORD>(enginePointer + dwClientState_GetLocalPlayer) + 1;
			isDormant = memory.Read<bool>(localPlayer + m_bDormant);
			if (!status || isDormant)
			{
				return;
			}
			//printf("local index = %d\n", localPlayerIndex);
			//shotsFired = memory.Read<DWORD>(localPlayer + m_iShotsFired);
			if (GetAsyncKeyState(aimKey) || autoFire)
			{
				targetEntity = -1;
				distance = INT_MAX;
				for (int i = 1; i <= 33; i++)
				{
					//Sleep(100);

					entity = memory.Read<DWORD>(GetClientModule(L"client_panorama.dll") + dwEntityList + ((i - 1) * 0x10));
					entityTeam = memory.Read<DWORD>(entity + dwTeam);
					entityHealth = memory.Read<DWORD>(entity + dwHealth);
					spotted = (memory.Read<long>(entity + m_bSpottedByMask) & (0x1 << (localPlayerIndex - 1))) != 0;

					isDormant = memory.Read<bool>(entity + m_bDormant);

					vTable = memory.Read<DWORD>(entity + 0x8);
					fN = memory.Read<DWORD>(vTable + 0x8);
					ptr = memory.Read<DWORD>(fN + 0x1);
					classID = memory.Read<DWORD>(ptr + 0x14);
					isDormant = memory.Read<bool>(entity + m_bDormant);
					//printf("class = %d\n", classID);
					if (!isDormant  && classID == 38 && entityHealth > 0 && entityTeam != localTeam && spotted)
					{
						currentAngle = memory.Read<vector3>(enginePointer + dwClientState_ViewAngles);
						aimAngle = calculateAngles(entity, getLock(aimlock));
						temp = maxAngleDifference(aimAngle, currentAngle);
						if (temp < distance)
						{
							targetEntity = entity;
							distance = temp;
						}
					}
				}
				if (targetEntity != -1)
				{
					aimAngle = calculateAngles(targetEntity, getLock(aimlock));
				}
				
				currentAngle = memory.Read<vector3>(enginePointer + dwClientState_ViewAngles);
				if (maxAngleDifference(currentAngle, aimAngle) <= fov)
				{
					//Warning : must normalize/clamp angles before writing, else untrusted ban.
					if (isAngleValid(aimAngle) && distance != INT_MAX && targetEntity != -1)
					{
						smooth(currentAngle, aimAngle, smoother);
						{
							memory.Write<vector3>(enginePointer + dwClientState_ViewAngles, aimAngle);
							if (autoFire)
							{
								crosshairId = memory.Read<DWORD>(localPlayer + dwCrosshairId);
								enemyInCrosshair = memory.Read<DWORD>(GetClientModule(L"client_panorama.dll") + dwEntityList + (crosshairId - 1) * 0x10);
								if (enemyInCrosshair == targetEntity)
								{
									memory.Write<DWORD>(GetClientModule(L"client_panorama.dll") + dwForceAttack, 1);
									Sleep(5);
									memory.Write<DWORD>(GetClientModule(L"client_panorama.dll") + dwForceAttack, 0);
								}
							}
						}
					}

				}
			}
		}

	}

	void rcs(bool on)
	{
		if (!on)
		{
			return;
		}
		static DWORD localPlayer, engineClient, shotsFired = 0;
		static bool status, isDormant;
		static vector3 punchAngle, currViewAngle, outputPunchAngle;
		static vector3 oldPunch = { 0,0,0 };
		engineClient = memory.Read<DWORD>(getEnginedll(L"engine.dll") + dwClientState);
		//oyvhgyy *junk = new oyvhgyy();
		//while (true)
		{
			status = (memory.Read<DWORD>(engineClient + dwClientState_State)) == 6;
			if (!status)
			{
				return;
			}
			localPlayer = memory.Read<DWORD>(GetClientModule(L"client_panorama.dll") + dwLocalPlayer);
			isDormant = memory.Read<bool>(localPlayer + m_bDormant);
			if (isDormant)
			{
				oldPunch = { 0,0,0 };
				//continue;
			}
			shotsFired = memory.Read<DWORD>(localPlayer + m_iShotsFired);

			// Or you could do "if (mem.Read<int>(PlayerBase + m_iShotsFired) >= 1)
			if (shotsFired > 1)
			{
				punchAngle = memory.Read<vector3>(localPlayer + m_aimPunchAngle);
				currViewAngle = memory.Read<vector3>(engineClient + dwClientState_ViewAngles);

				outputPunchAngle.x = currViewAngle.x + oldPunch.x - punchAngle.x*2.0;
				outputPunchAngle.y = currViewAngle.y + oldPunch.y - punchAngle.y*2.0;
				normalizeAngles(outputPunchAngle);
				//Warning : must normalize/clamp angles before writing, elst untrusted ban.
				if (isAngleValid(outputPunchAngle))
				{
					memory.Write<vector3>(engineClient + dwClientState_ViewAngles, outputPunchAngle);
				}
				oldPunch = vector3{ punchAngle.x*2.0f,punchAngle.y*2.0f,0 };
			}
			
			else
			{
				oldPunch = { 0,0,0 };
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
			keybd_event(VK_CONTROL, NULL, NULL, NULL);
			Sleep(50);
			keybd_event(VK_CONTROL, NULL, KEYEVENTF_KEYUP, NULL);
			
		}
	}
};

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

class DrawingESP
{
private:
	RECT windowRect;
	HDC h_Desktop;
	HBRUSH hbrush;
	HFONT font;
	HANDLE handlE;
	HPEN hpen;
	HWND hwnd;
	struct vector3 {
		float x = 0;
		float y = 0;
		float z = 0;
	};
	typedef struct
	{
		float flMatrix[4][4];
	}WorldToScreenMatrix;
	WorldToScreenMatrix worldToScreenMatrix;
	bool WorldToScreen(vector3 from, float * to)
	{
		float w = 0.0f;

		to[0] = worldToScreenMatrix.flMatrix[0][0] * from.x + worldToScreenMatrix.flMatrix[0][1] * from.y + worldToScreenMatrix.flMatrix[0][2] * from.z + worldToScreenMatrix.flMatrix[0][3];
		to[1] = worldToScreenMatrix.flMatrix[1][0] * from.x + worldToScreenMatrix.flMatrix[1][1] * from.y + worldToScreenMatrix.flMatrix[1][2] * from.z + worldToScreenMatrix.flMatrix[1][3];
		w = worldToScreenMatrix.flMatrix[3][0] * from.x + worldToScreenMatrix.flMatrix[3][1] * from.y + worldToScreenMatrix.flMatrix[3][2] * from.z + worldToScreenMatrix.flMatrix[3][3];

		if (w < 0.01f)
			return false;

		float invw = 1.0f / w;
		to[0] *= invw;
		to[1] *= invw;
		GetWindowRect(hwnd, &windowRect);
		int width = (int)(windowRect.right - windowRect.left);
		int height = (int)(windowRect.bottom - windowRect.top);

		float x = width / 2;
		float y = height / 2;

		x += 0.5 * to[0] * width + 0.5;
		y -= 0.5 * to[1] * height + 0.5;

		to[0] = x + windowRect.left;
		to[1] = y + windowRect.top;

		return true;
	}
	float vectorDistance(vector3 src, vector3 des)
	{
		return sqrt(pow(des.x - src.x, 2) + pow(des.y - src.y, 2) + pow(des.z - src.z, 2));
	}
	void DrawFilledRect(int x, int y, int w, int h)
	{
		//We create our rectangle to draw on screen
		RECT rect = { x, y, x + w, y + h };
		//We clear that portion of the screen and display our rectangle
		FillRect(h_Desktop, &rect, hbrush);
	}
	void DrawBorderBox(int x, int y, int w, int h, int thickness)
	{
		//Top horiz line
		DrawFilledRect(x, y, w, thickness);
		//Left vertical line
		DrawFilledRect(x, y, thickness, h);
		//right vertical line
		DrawFilledRect((x + w), y, thickness, h);
		//bottom horiz line
		DrawFilledRect(x, y + h, w + thickness, thickness);
	}
	void DrawLine(float StartX, float StartY, float EndX, float EndY, COLORREF Pen)
	{
		int a, b = 0;
		HPEN hOPen;
		// penstyle, width, color
		HPEN hNPen = CreatePen(PS_SOLID, 2, Pen);
		hOPen = (HPEN)SelectObject(h_Desktop, hNPen);
		// starting point of line
		MoveToEx(h_Desktop, StartX, StartY, NULL);
		// ending point of line
		a = LineTo(h_Desktop, EndX, EndY);
		DeleteObject(SelectObject(h_Desktop, hOPen));
	}
	void DrawString(int x, int y, COLORREF color, const char* text)
	{
		SetTextAlign(h_Desktop, TA_CENTER | TA_NOUPDATECP);

		SetBkColor(h_Desktop, RGB(0, 0, 0));
		SetBkMode(h_Desktop, TRANSPARENT);

		SetTextColor(h_Desktop, color);

		SelectObject(h_Desktop, font);

		TextOutA(h_Desktop, x, y, text, strlen(text));

		DeleteObject(font);
	}

	void drawESP(int x, int y, float distance, bool line, COLORREF color, bool boxESP, bool itemESP)
	{
		//ESP RECTANGLE
		if (boxESP)
		{
			int width = 18100 / distance;
			int height = 36000 / distance;
			DrawBorderBox(x - (width / 2) - 2.5, y - height - 10, width, height, 1);
		}
		//Sandwich ++
		if (line)
		{
			DrawLine((windowRect.right - windowRect.left) / 2, windowRect.bottom - windowRect.top, x, y, color);
		}
		if (itemESP)
		{
			int width = 28100 / distance;
			int height = 36000 / distance;
			DrawBorderBox(x - (width / 2) - 2.5, y - height/8 - 8, width - width*.25, height/8, 2);
		}
	}

public:

	DrawingESP()
	{
		hbrush = CreateSolidBrush(RGB(0, 255, 255));
		hwnd = FindWindow(NULL, L"Counter-Strike: Global Offensive");
		h_Desktop = GetDC(hwnd);
		hpen = CreatePen(PS_SOLID, 2, RGB(0, 255, 255));
		GetWindowRect(hwnd, &windowRect);
		font = CreateFont(15, 0, 0, 0, FW_REGULAR, 0, 0, 0, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS,
			CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY, FF_MODERN, L"Times New Roman");
	}

	void drawBox(bool boxESP,bool friendly, bool enemy, myColor boxEspColor, bool lineESP, bool nameESP, bool healthESP, bool itemESP)
	{
		if (!boxESP && !nameESP && !healthESP && !itemESP && !lineESP)
		{
			return ;
		}
		static DWORD entity, entityTeam, entityHealth, vTable, fN, ptr, classID, localPlayer, localTeam, pointerToGlow, objCount;
		static float screenXY[2];
		static vector3 entityPosition, localPosition;
		std::string health;
		char *name;
		DeleteObject(hbrush);
		COLORREF ESPcolour = RGB((BYTE)boxEspColor.r, (BYTE)boxEspColor.g, (BYTE)boxEspColor.b);
		hbrush = CreateSolidBrush(ESPcolour);
	
		{
			worldToScreenMatrix = memory.Read<WorldToScreenMatrix>(GetClientModule(L"client_panorama.dll") + dwViewMatrix);
			for (int i = 1; i < 33; i++)
			{
				entity = memory.Read<DWORD>(GetClientModule(L"client_panorama.dll") + dwEntityList + ((i - 1) * 0x10));

				vTable = memory.Read<DWORD>(entity + 0x8);
				fN = memory.Read<DWORD>(vTable + 0x8);
				ptr = memory.Read<DWORD>(fN + 0x1);
				classID = memory.Read<DWORD>(ptr + 0x14);

				entityTeam = memory.Read<DWORD>(entity + dwTeam);
				entityHealth = memory.Read<DWORD>(entity + dwHealth);
				localPlayer = memory.Read<DWORD>(GetClientModule(L"client_panorama.dll") + dwLocalPlayer);
				localTeam = memory.Read<DWORD>(localPlayer + dwTeam);

				if (classID == 38  && entityHealth >= 1)
				{
					entityPosition = memory.Read<vector3>(entity + m_vecOrigin);
					localPosition = memory.Read<vector3>(localPlayer + m_vecOrigin);
					if (WorldToScreen(entityPosition, screenXY))
					{
						if ((enemy && entityTeam != localTeam) || (friendly && entityTeam == localTeam))
						{
							if (boxESP || lineESP)
							{
								drawESP(screenXY[0] - windowRect.left, screenXY[1] - windowRect.top, vectorDistance(entityPosition, localPosition), lineESP, ESPcolour, boxESP, false);
							}
							if (healthESP)
							{
								health = std::to_string(entityHealth) + " hp";
								DrawString(screenXY[0] - windowRect.left, screenXY[1] - windowRect.top, RGB(0, 255, 255), health.c_str());
							}
							if (nameESP)
							{
								name = getName(i);
								DrawString(screenXY[0] - windowRect.left, screenXY[1] - windowRect.top + 12, RGB(0, 255, 255), (const char*)name);
							}
						}
						
						
					}
				}
			}
			if (itemESP)
			{
				pointerToGlow = memory.Read<DWORD>(GetClientModule(L"client_panorama.dll") + dwGlow);
				objCount = memory.Read<DWORD>(GetClientModule(L"client_panorama.dll") + dwGlow + 0x4);
				if (pointerToGlow != 0 && objCount > 0)
				{
					for (int i = 0; i < objCount; i++)
					{
						entity = memory.Read<DWORD>(pointerToGlow + i * 56);
						vTable = memory.Read<DWORD>(entity + 0x8);
						fN = memory.Read<DWORD>(vTable + 0x8);
						ptr = memory.Read<DWORD>(fN + 0x1);
						classID = memory.Read<DWORD>(ptr + 0x14);
						//printf("%d\n", classID);
						if ((classID >= 225 && classID <= 265) || classID == 1 || classID == 212 || classID == 204 || classID == 152 || classID == 126 || classID == 110 || classID == 94 || classID == 211 || classID == 32)
						{
							localPlayer = memory.Read<DWORD>(GetClientModule(L"client_panorama.dll") + dwLocalPlayer);
							entityPosition = memory.Read<vector3>(entity + m_vecOrigin);
							localPosition = memory.Read<vector3>(localPlayer + m_vecOrigin);
							if (WorldToScreen(entityPosition, screenXY))
							{
								drawESP(screenXY[0] - windowRect.left, screenXY[1] - windowRect.top, vectorDistance(entityPosition, localPosition), false, ESPcolour, false, true);
							}
						}
					}
				}
			}
		}
		
	}
	char* getName(int index)//Entity index
	{
		struct player_info
		{
			__int64         unknown;            //0x0000 
			union
			{
				__int64       steamID64;          //0x0008 - SteamID64
				struct
				{
					__int32     xuid_low;
					__int32     xuid_high;
				};
			};
			char            szName[128];        //0x0010 - Player Name
			int             userId;             //0x0090 - Unique Server Identifier
			char            szSteamID[20];      //0x0094 - STEAM_X:Y:Z
			char            pad_0x00A8[0x10];   //0x00A8
			unsigned long   iSteamID;           //0x00B8 - SteamID 
			char            szFriendsName[128];
			bool            fakeplayer;
			bool            ishltv;
			unsigned int    customfiles[4];
			unsigned char   filesdownloaded;
		} var;

		//memset(&var, 0, sizeof(var));
		DWORD clientState = memory.Read<DWORD>(getEnginedll(L"engine.dll") + dwClientState);
		DWORD userInfoTable = memory.Read<DWORD>(clientState + dwClientState_PlayerInfo);
		DWORD items = memory.Read<DWORD>(memory.Read<DWORD>(userInfoTable + 0x40) + 0xC);
		var = memory.Read<player_info>(memory.Read<DWORD>(items + 0x28 + ((index - 1) * 0x34)));
		//cout << var.szName << endl;
		return var.szName;
	}
};
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
struct weaponSkin
{
	int Ak47 = -1;
	int AWP = -1;
	int SSG08 = -1;
	int M4A4 = -1;
	int M4A1_S = -1;
	int FAMAS = -1;
	int GalilAR = -1;
	int AUG = -1;
	int SG553 = -1;
	int SCAR20 = -1;
	int G3SG1 = -1;
	int DesertEagle = -1;
	int USP_S = -1;
	int Glock18 = -1;
	int P2000 = -1;
	int P250 = -1;
	int FiveSeveN = -1;
	int Tec9 = -1;
	int CZ75Auto = -1;
	int DualBerettas = -1;
	int R8Revolver = -1;
	int MP9 = -1;
	int MAC10 = -1;
	int PPBizon = -1;
	int MP7 = -1;
	int UMP45 = -1;
	int P90 = -1;
	int MP5SD = -1;
	int XM1014 = -1;
	int Nova = -1;
	int MAG7 = -1;
	int SawedOff = -1;
	int M249 = -1;
	int Negev = -1;
}weapon_skin;
DWORD FindPattern2(BYTE* Mask, char* szMask)
{
	DWORD Address = getEnginedll(L"engine.dll");
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
struct Param {
	DWORD this_;
	std::string name_;
}parameter;
struct Param2 {
	int a=0;
	int b=1;
}parameter2;
DWORD FindHudElement(std::string name)
{

	static auto _this = FindPattern((PBYTE)"\B9\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x8B\x5D\x08", (char*)"x????x????xxx") + 1;
	static auto _hud_element = reinterpret_cast<DWORD(__thiscall*)(void*, const char*)>(FindPattern((PBYTE)"\x55\x8B\xEC\x53\x8B\x5D\x08\x56\x57\x8B\xF9\x33\xF6\x39\x77\x28", (char*)"xxxxxxxxxxxxxxxx"));
	parameter.this_ = memory.Read<int>(GetClientModule(L"client_panorama.dll") + _this);
	parameter.name_ = name.c_str();
	DWORD a = 0;
	DWORD* ptr = &a;
	HANDLE h = CreateRemoteThread(memory.handleToProcess, NULL, 0, (LPTHREAD_START_ROUTINE)_hud_element, NULL, 0, NULL);
	if(WaitForSingleObject(h, 0xFFFFFFFF) == WAIT_OBJECT_0)
	{
		//GetExitCodeThread(h, ptr);
		//CloseHandle(h);
		//return ptr ? *ptr : 0;
	}
	
	return 0;
}
static signed int updateHUD()
{
	DWORD dwHudWeaponSelection = memory.Read<int>(GetClientModule(L"client_panorama.dll") + FindHudElement("CCSGO_HudWeaponSelection"));
	if (dwHudWeaponSelection) {
		int pHudWeapons = memory.Read<int>(GetClientModule(L"client_panorama.dll") + dwHudWeaponSelection - 0x20);
		if (pHudWeapons ) {
			typedef int(__thiscall *ClearHudWeaponIcon_t)(void*, int);
			static ClearHudWeaponIcon_t ClearHudWeaponIcon = 0;
			if (!ClearHudWeaponIcon)
			{
				ClearHudWeaponIcon = (ClearHudWeaponIcon_t)(FindPattern((PBYTE)"\x55\x8B\xEC\x51\x53\x56\x8B\x75\x08\x8B\xD9\x57\x6B\xFE\x2C\x89\x5D\xFC", (char*)"xxxxxxxxxxxxxxxxxx"));
			}
			if (!ClearHudWeaponIcon)
			{
				return 0;
			}
			//for (int i = 0; i < memory.Read<int>(GetClientModule(L"client_panorama.dll")+pHudWeapons); i++)
			{
				//parameter2.a = memory.Read<int>(GetClientModule(L"client_panorama.dll")+ dwHudWeaponSelection - 0xA0);
				//parameter2.b = i;
				//CreateRemoteThread(memory.handleToProcess, NULL, 0, (LPTHREAD_START_ROUTINE)ClearHudWeaponIcon, &parameter2, 0, NULL);
			}
			
		}
	}

}

void changeWeaponSkin()
{
	DWORD localPlayer, weaponIndex, weaponEntity, weaponid, activeWeaponIndex, activeWeaponEntity, activeWeaponId, ViewModelEntityIndex, ViewModel;
	localPlayer = memory.Read<DWORD>(GetClientModule(L"client_panorama.dll") + dwLocalPlayer);
	for (int i = 1; i <= 8; i++)
	{
		weaponIndex = memory.Read<DWORD>(localPlayer + m_hMyWeapons + ((i - 1) * 0x4)) & 0xFFF;
		weaponEntity = memory.Read<DWORD>(GetClientModule(L"client_panorama.dll") + dwEntityList + (weaponIndex - 1) * 0x10);
		weaponid = memory.Read<short>(weaponEntity + m_iItemDefinitionIndex);
		if (!weaponEntity)
		{
			continue;
		}
		//System::Diagnostics::Debug::WriteLine(weaponid);
		//cout << weaponid << endl;
		//memory.Write<bool>(memory.Read<int>(memory.Read<int>(weaponEntity + m_AttributeManager) + m_Item) + m_bInitialized, false);
		//memory.Write<bool>(weaponEntity + m_AttributeManager + m_Item +  m_bInitialized, false);
		if ( weaponid == WEAPON_AK47 && weapon_skin.Ak47 != -1)
		{
			memory.Write<DWORD>(weaponEntity + m_nFallbackPaintKit, weapon_skin.Ak47);
			memory.Write<float>(weaponEntity + m_flFallbackWear, 0.00001f);
			memory.Write<int>(weaponEntity + m_iItemIDHigh, -1);
			//memory.Write<int>(weaponEntity + 0x2FC8, memory.Read<int>(weaponEntity + m_OriginalOwnerXuidLow));
			//memory.Write<DWORD>(weaponEntity + m_OriginalOwnerXuidLow, 0);
			//memory.Write<DWORD>(weaponEntity + m_OriginalOwnerXuidHigh, 0);

		}
		else if (weaponid == WEAPON_AWP && weapon_skin.AWP != -1)
		{

			memory.Write<DWORD>(weaponEntity + m_nFallbackPaintKit, weapon_skin.AWP);
			memory.Write<float>(weaponEntity + m_flFallbackWear, 0.00001f);
			memory.Write<int>(weaponEntity + m_iItemIDHigh, -1);

		}
		else if (weaponid == WEAPON_SSG08 && weapon_skin.SSG08 != -1)
		{

			memory.Write<DWORD>(weaponEntity + m_nFallbackPaintKit, weapon_skin.SSG08);
			memory.Write<float>(weaponEntity + m_flFallbackWear, 0.00001f);
			memory.Write<int>(weaponEntity + m_iItemIDHigh, -1);

		}
		else if (weaponid == WEAPON_M4A1 && weapon_skin.M4A4 != -1)
		{

			memory.Write<DWORD>(weaponEntity + m_nFallbackPaintKit, weapon_skin.M4A4);
			memory.Write<float>(weaponEntity + m_flFallbackWear, 0.00001f);
			memory.Write<int>(weaponEntity + m_iItemIDHigh, -1);

		}
		else if (weaponid == 262204 && weapon_skin.M4A1_S != -1)
		{
			memory.Write<DWORD>(weaponEntity + m_nFallbackPaintKit, weapon_skin.M4A1_S);
			memory.Write<float>(weaponEntity + m_flFallbackWear, 0.00001f);
			memory.Write<int>(weaponEntity + m_iItemIDHigh, -1);
		}
		else if (weaponid == WEAPON_FAMAS && weapon_skin.FAMAS != -1)
		{

			memory.Write<DWORD>(weaponEntity + m_nFallbackPaintKit, weapon_skin.FAMAS);
			memory.Write<float>(weaponEntity + m_flFallbackWear, 0.00001f);
			memory.Write<int>(weaponEntity + m_iItemIDHigh, -1);

		}
		else if (weaponid == WEAPON_GALILAR && weapon_skin.GalilAR != -1)
		{

			memory.Write<DWORD>(weaponEntity + m_nFallbackPaintKit, weapon_skin.GalilAR);
			memory.Write<float>(weaponEntity + m_flFallbackWear, 0.00001f);
			memory.Write<int>(weaponEntity + m_iItemIDHigh, -1);

		}
		else if (weaponid == WEAPON_AUG && weapon_skin.AUG != -1)
		{

			memory.Write<DWORD>(weaponEntity + m_nFallbackPaintKit, weapon_skin.AUG);
			memory.Write<float>(weaponEntity + m_flFallbackWear, 0.00001f);
			memory.Write<int>(weaponEntity + m_iItemIDHigh, -1);

		}
		else if (weaponid == WEAPON_SG553 && weapon_skin.SG553 != -1)
		{

			memory.Write<DWORD>(weaponEntity + m_nFallbackPaintKit, weapon_skin.SG553);
			memory.Write<float>(weaponEntity + m_flFallbackWear, 0.00001f);
			memory.Write<int>(weaponEntity + m_iItemIDHigh, -1);

		}
		//SMG
		else if (weaponid == WEAPON_MP7 && weapon_skin.MP7 != -1)
		{

			memory.Write<DWORD>(weaponEntity + m_nFallbackPaintKit, weapon_skin.MP7);
			memory.Write<float>(weaponEntity + m_flFallbackWear, 0.00001f);
			memory.Write<int>(weaponEntity + m_iItemIDHigh, -1);

		}
		else if (weaponid == WEAPON_MP9 && weapon_skin.MP9 != -1)
		{

			memory.Write<DWORD>(weaponEntity + m_nFallbackPaintKit, weapon_skin.MP9);
			memory.Write<float>(weaponEntity + m_flFallbackWear, 0.00001f);
			memory.Write<int>(weaponEntity + m_iItemIDHigh, -1);

		}
		else if (weaponid == WEAPON_UMP45 && weapon_skin.UMP45 != -1)
		{

			memory.Write<DWORD>(weaponEntity + m_nFallbackPaintKit, weapon_skin.UMP45);
			memory.Write<float>(weaponEntity + m_flFallbackWear, 0.00001f);
			memory.Write<int>(weaponEntity + m_iItemIDHigh, -1);

		}
		else if (weaponid == 262167 && weapon_skin.MP5SD != -1)
		{

			memory.Write<DWORD>(weaponEntity + m_nFallbackPaintKit, weapon_skin.MP5SD);
			memory.Write<float>(weaponEntity + m_flFallbackWear, 0.00001f);
			memory.Write<int>(weaponEntity + m_iItemIDHigh, -1);

		}
		else if (weaponid == WEAPON_MAC10 && weapon_skin.MAC10 != -1)
		{

			memory.Write<DWORD>(weaponEntity + m_nFallbackPaintKit, weapon_skin.MAC10);
			memory.Write<float>(weaponEntity + m_flFallbackWear, 0.00001f);
			memory.Write<int>(weaponEntity + m_iItemIDHigh, -1);

		}
		else if (weaponid == WEAPON_P90 && weapon_skin.P90 != -1)
		{

		memory.Write<DWORD>(weaponEntity + m_nFallbackPaintKit, weapon_skin.P90);
		memory.Write<float>(weaponEntity + m_flFallbackWear, 0.00001f);
		memory.Write<int>(weaponEntity + m_iItemIDHigh, -1);

		}
		else if (weaponid == WEAPON_BIZON && weapon_skin.PPBizon != -1)
		{

		memory.Write<DWORD>(weaponEntity + m_nFallbackPaintKit, weapon_skin.PPBizon);
		memory.Write<float>(weaponEntity + m_flFallbackWear, 0.00001f);
		memory.Write<int>(weaponEntity + m_iItemIDHigh, -1);

		}
		//Heavy
		else if (weaponid == WEAPON_XM1014 && weapon_skin.XM1014 != -1)
		{

		memory.Write<DWORD>(weaponEntity + m_nFallbackPaintKit, weapon_skin.XM1014);
		memory.Write<float>(weaponEntity + m_flFallbackWear, 0.00001f);
		memory.Write<int>(weaponEntity + m_iItemIDHigh, -1);

		}
		else if (weaponid == WEAPON_NOVA && weapon_skin.Nova != -1)
		{

		memory.Write<DWORD>(weaponEntity + m_nFallbackPaintKit, weapon_skin.Nova);
		memory.Write<float>(weaponEntity + m_flFallbackWear, 0.00001f);
		memory.Write<int>(weaponEntity + m_iItemIDHigh, -1);

		}
		else if (weaponid == WEAPON_MAG7 && weapon_skin.MAG7 != -1)
		{

		memory.Write<DWORD>(weaponEntity + m_nFallbackPaintKit, weapon_skin.MAG7);
		memory.Write<float>(weaponEntity + m_flFallbackWear, 0.00001f);
		memory.Write<int>(weaponEntity + m_iItemIDHigh, -1);

		}
		else if (weaponid == WEAPON_SAWEDOFF && weapon_skin.SawedOff != -1)
		{

		memory.Write<DWORD>(weaponEntity + m_nFallbackPaintKit, weapon_skin.SawedOff);
		memory.Write<float>(weaponEntity + m_flFallbackWear, 0.00001f);
		memory.Write<int>(weaponEntity + m_iItemIDHigh, -1);

		}
		else if (weaponid == WEAPON_M249 && weapon_skin.M249 != -1)
		{

		memory.Write<DWORD>(weaponEntity + m_nFallbackPaintKit, weapon_skin.M249);
		memory.Write<float>(weaponEntity + m_flFallbackWear, 0.00001f);
		memory.Write<int>(weaponEntity + m_iItemIDHigh, -1);

		}
		else if (weaponid == WEAPON_NEGEV && weapon_skin.Negev != -1)
		{

		memory.Write<DWORD>(weaponEntity + m_nFallbackPaintKit, weapon_skin.Negev);
		memory.Write<float>(weaponEntity + m_flFallbackWear, 0.00001f);
		memory.Write<int>(weaponEntity + m_iItemIDHigh, -1);

		}

		//Pistol
		if (weaponid == WEAPON_DEAGLE && weapon_skin.DesertEagle != -1)
		{

			memory.Write<DWORD>(weaponEntity + m_nFallbackPaintKit, weapon_skin.DesertEagle);
			memory.Write<float>(weaponEntity + m_flFallbackWear, 0.00001f);
			memory.Write<int>(weaponEntity + m_iItemIDHigh, -1);

		}
		else if (weaponid == WEAPON_USP_SILENCER && weapon_skin.USP_S != -1)
		{

			memory.Write<DWORD>(weaponEntity + m_nFallbackPaintKit, weapon_skin.USP_S);
			memory.Write<float>(weaponEntity + m_flFallbackWear, 0.00001f);
			memory.Write<int>(weaponEntity + m_iItemIDHigh, -1);

		}
		else if (weaponid == WEAPON_GLOCK && weapon_skin.Glock18 != -1)
		{

			memory.Write<DWORD>(weaponEntity + m_nFallbackPaintKit, weapon_skin.Glock18);
			memory.Write<float>(weaponEntity + m_flFallbackWear, 0.00001f);
			memory.Write<int>(weaponEntity + m_iItemIDHigh, -1);

		}
		else if (weaponid == WEAPON_FIVESEVEN && weapon_skin.FiveSeveN != -1)
		{

			memory.Write<DWORD>(weaponEntity + m_nFallbackPaintKit, weapon_skin.FiveSeveN);
			memory.Write<float>(weaponEntity + m_flFallbackWear, 0.00001f);
			memory.Write<int>(weaponEntity + m_iItemIDHigh, -1);

		}
		else if (weaponid == WEAPON_TEC9 && weapon_skin.Tec9 != -1)
		{

			memory.Write<DWORD>(weaponEntity + m_nFallbackPaintKit, weapon_skin.Tec9);
			memory.Write<float>(weaponEntity + m_flFallbackWear, 0.00001f);
			memory.Write<int>(weaponEntity + m_iItemIDHigh, -1);

		}
		else if (weaponid == 262207 && weapon_skin.CZ75Auto != -1)
		{

			memory.Write<DWORD>(weaponEntity + m_nFallbackPaintKit, weapon_skin.CZ75Auto);
			memory.Write<float>(weaponEntity + m_flFallbackWear, 0.00001f);
			memory.Write<int>(weaponEntity + m_iItemIDHigh, -1);

		}
		else if (weaponid == WEAPON_P250 && weapon_skin.P250 != -1)
		{

			memory.Write<DWORD>(weaponEntity + m_nFallbackPaintKit, weapon_skin.P250);
			memory.Write<float>(weaponEntity + m_flFallbackWear, 0.00001f);
			memory.Write<int>(weaponEntity + m_iItemIDHigh, -1);

		}
		else if (weaponid == WEAPON_HKP2000 && weapon_skin.P2000 != -1)
		{

			memory.Write<DWORD>(weaponEntity + m_nFallbackPaintKit, weapon_skin.P2000);
			memory.Write<float>(weaponEntity + m_flFallbackWear, 0.00001f);
			memory.Write<int>(weaponEntity + m_iItemIDHigh, -1);

		}
		else if (weaponid == WEAPON_ELITE && weapon_skin.DualBerettas != -1)
		{

			memory.Write<DWORD>(weaponEntity + m_nFallbackPaintKit, weapon_skin.DualBerettas);
			memory.Write<float>(weaponEntity + m_flFallbackWear, 0.00001f);
			memory.Write<int>(weaponEntity + m_iItemIDHigh, -1);

		}
		else if (weaponid == 262208 && weapon_skin.R8Revolver != -1)
		{

			memory.Write<DWORD>(weaponEntity + m_nFallbackPaintKit, weapon_skin.R8Revolver);
			memory.Write<float>(weaponEntity + m_flFallbackWear, 0.00001f);
			memory.Write<int>(weaponEntity + m_iItemIDHigh, -1);

		}
		
		//memory.Write<bool>(weaponEntity + m_AttributeManager + m_Item + m_bInitialized, true);
		//memory.Write<bool>(memory.Read<int>(memory.Read<int>(weaponEntity + m_AttributeManager) +  m_Item) + m_bInitialized, true);
	}
}
struct knifeInfo
{
	int knifeType = -1;
	int knifeSkin = -1;
}knife_info;
struct WeaponCFG
{
	int ViewModelIndex = 0;
	int WorldModelIndex = 0;
	int WorldDropedModel = 0;
}cfg;
int getPosition(int id)
{
	switch (id)
	{
	case WEAPON_KNIFE_BAYONET: return 0;
	case WEAPON_KNIFE_FLIP: return 1;
	case WEAPON_KNIFE_GUT: return 2;
	case WEAPON_KNIFE_KARAMBIT: return 3;
	case WEAPON_KNIFE_M9_BAYONET: return 4;
	case WEAPON_KNIFE_TACTICAL: return 5;
	case WEAPON_KNIFE_FALCHION: return 6;
	case WEAPON_KNIFE_SURVIVAL_BOWIE: return 7;
	case WEAPON_KNIFE_BUTTERFLY: return 8;
	case WEAPON_KNIFE_PUSH: return 9;
	case WEAPON_KNIFE_URSUS: return 10;
	case WEAPON_KNIFE_GYPSY_JACKKNIFE: return 11;
	case WEAPON_KNIFE_STILETTO: return 12;
	case WEAPON_KNIFE_WIDOWMAKER: return 13;

	}
}
int getNewKnifeException(int id)
{
	switch (id)
	{
	case WEAPON_KNIFE_URSUS: return 1;
	case WEAPON_KNIFE_GYPSY_JACKKNIFE: return 1;
	case WEAPON_KNIFE_STILETTO: return 1;
	case WEAPON_KNIFE_WIDOWMAKER: return 1;
	default:return 0;
	}
}
void changeKnife()
{
	if (knife_info.knifeSkin == -1 || knife_info.knifeType == -1)
	{
		return;
	}
	DWORD localPlayer, localTeam, weaponIndex, weaponEntity, weaponid, activeWeaponIndex, activeWeaponEntity, activeWeaponId, ViewModelEntityIndex, ViewModel, weaponViewModelID, accountId;
	localPlayer = memory.Read<DWORD>(GetClientModule(L"client_panorama.dll") + dwLocalPlayer);
	localTeam = memory.Read<DWORD>(localPlayer + dwTeam);
	//System::Diagnostics::Debug::WriteLine("team = " + localTeam);
	int precache_bayonet_ct = 87; // = v_knife_bayonet.mdl - v_knife_default_ct.mdl
	int precache_bayonet_t = 63; // = v_knife_bayonet.mdl - v_knife_default_t.mdl

	for (int i = 1; i <= 8; i++)
	{
		weaponIndex = memory.Read<DWORD>(localPlayer + m_hMyWeapons + ((i - 1) * 0x4)) & 0xFFF;
		weaponEntity = memory.Read<DWORD>(GetClientModule(L"client_panorama.dll") + dwEntityList + (weaponIndex - 1) * 0x10);
		weaponid = memory.Read<DWORD>(weaponEntity + m_iItemDefinitionIndex);
		//System::Diagnostics::Debug::WriteLine("weaponId = "+ weaponid);
		if (!weaponEntity)
		{
			continue;
		}
		accountId = memory.Read<int>(weaponEntity + m_OriginalOwnerXuidLow);
		if (accountId == 0 || accountId > 64)
		{
			//continue;
		}
		//cout << weaponid << endl;
		//Knife
		activeWeaponIndex = memory.Read<DWORD>(localPlayer + m_hActiveWeapon) & 0xFFF;
		activeWeaponEntity = memory.Read<DWORD>(GetClientModule(L"client_panorama.dll") + dwEntityList + (activeWeaponIndex - 1) * 0x10);
		activeWeaponId = memory.Read<DWORD>(activeWeaponEntity + m_iItemDefinitionIndex);

		ViewModelEntityIndex = memory.Read<DWORD>(localPlayer + m_hViewModel) & 0xFFF;
		ViewModel = memory.Read<DWORD>(GetClientModule(L"client_panorama.dll") + dwEntityList + ((ViewModelEntityIndex - 1) * 0x10));
		
		//System::Diagnostics::Debug::WriteLine(weaponViewModelID);
		
		if (weaponid == WEAPON_KNIFE_T || weaponid == WEAPON_KNIFE ||
			weaponid == WEAPON_KNIFE_BAYONET || weaponid == WEAPON_KNIFE_FLIP ||
			weaponid == WEAPON_KNIFE_GUT || weaponid == WEAPON_KNIFE_KARAMBIT ||
			weaponid == WEAPON_KNIFE_M9_BAYONET || weaponid == WEAPON_KNIFE_TACTICAL
			|| weaponid == WEAPON_KNIFE_FALCHION || weaponid == WEAPON_KNIFE_SURVIVAL_BOWIE || 
			weaponid == WEAPON_KNIFE_BUTTERFLY || weaponid == WEAPON_KNIFE_PUSH
			|| weaponid == WEAPON_KNIFE_URSUS || weaponid == WEAPON_KNIFE_GYPSY_JACKKNIFE
			|| weaponid == WEAPON_KNIFE_STILETTO || weaponid == WEAPON_KNIFE_WIDOWMAKER)
			
		{
			/*memory.Write<bool>(localPlayer + m_bInitialized, false);
			memory.Write<bool>(getEnginedll(L"engine.dll") + m_bInitialized, false);
			memory.Write<bool>(GetClientModule(L"client_panorama.dll") + m_bInitialized, false);*/
			memory.Write<short>(weaponEntity + m_iItemDefinitionIndex, knife_info.knifeType);
			weaponViewModelID = memory.Read<int>(weaponEntity + m_iViewModelIndex);
			if (localTeam == 3)
			{
				cfg.ViewModelIndex = weaponViewModelID + precache_bayonet_ct + (getPosition(knife_info.knifeType) * 3) + getNewKnifeException(knife_info.knifeType);
			}
			else if (localTeam == 2)
			{
				cfg.ViewModelIndex = weaponViewModelID + precache_bayonet_t + (getPosition(knife_info.knifeType) * 3) + getNewKnifeException(knife_info.knifeType);
			}
			//System::Diagnostics::Debug::WriteLine(cfg.ViewModelIndex);
			cfg.WorldModelIndex = cfg.ViewModelIndex + 1;
			cfg.WorldDropedModel = cfg.ViewModelIndex + 2;
			
			if (weaponid == activeWeaponId)
			{
				//System::Diagnostics::Debug::WriteLine("Match");
				//System::Diagnostics::Debug::WriteLine(System::Convert::ToInt32(cfg.ViewModelIndex));
				memory.Write<DWORD>(ViewModel + m_nModelIndex, cfg.ViewModelIndex);
			}
			
			//memory.Write<WeaponCFG>(weaponEntity + m_iViewModelIndex , cfg);
			memory.Write<DWORD>(weaponEntity + m_nModelIndex, cfg.ViewModelIndex);
			memory.Write<DWORD>(localPlayer + m_iWorldModelIndex, cfg.WorldModelIndex);
			memory.Write<DWORD>(weaponEntity + m_nFallbackPaintKit, knives_obj[knife_info.knifeSkin].id);
			memory.Write<float>(weaponEntity + m_flFallbackWear, 0.00001f);
			//memory.Write<DWORD>(weaponEntity + 0x2FC8, accountId);
			memory.Write<int>(weaponEntity + m_iItemIDHigh, -1);
			/*memory.Write<bool>(GetClientModule(L"client_panorama.dll") + m_bInitialized, true);
			memory.Write<bool>(getEnginedll(L"engine.dll") + m_bInitialized, true);
			memory.Write<bool>(localPlayer + m_bInitialized, true);*/
		}
		
		//memory.Write<DWORD>(weaponEntity + m_OriginalOwnerXuidLow, 0);
		//memory.Write<DWORD>(weaponEntity + m_OriginalOwnerXuidHigh, 0);
		//memory.Write<int>(weaponEntity + m_iItemIDHigh, -1);
		//memory.Write<int>(weaponEntity + m_iItemIDHigh - 4, -1);
		//memory.Write<int>(weaponEntity + 0x31C4, 1337);
	}
	//System::Diagnostics::Debug::WriteLine("method");
}
void scanOffsets() 
{
	dwClientState = FindPattern2((PBYTE)"\xA1\x00\x00\x00\x00\x33\xD2\x6A\x00\x6A\x00\x33\xC9\x89\xB0", (char*)"x????xxxxxxxxxx");
	dwClientState_State = FindPattern2((PBYTE)"\x83\xB8\x00\x00\x00\x00\x00\x0F\x94\xC0\xC3", (char*)"xx?????xxxx");
	dwClientState_ViewAngles = FindPattern2((PBYTE)"\xF3\x0F\x11\x80\x00\x00\x00\x00\xD9\x46\x04\xD9\x05", (char*)"xxxx????xxxxx");
	dwClientState_GetLocalPlayer = FindPattern2((PBYTE)"\x8B\x80\x00\x00\x00\x00\x40\xC3", (char*)"xx????xx");
	dwEntityList = FindPattern((PBYTE)"\xBB\x00\x00\x00\x00\x83\xFF\x01\x0F\x8C\x00\x00\x00\x00\x3B\xF8", (char*)"x????xxxxx????xx");
	dwForceAttack = FindPattern((PBYTE)"\x89\x0D\x00\x00\x00\x00\x8B\x0D\x00\x00\x00\x00\x8B\xF2\x8B\xC1\x83\xCE\x04", (char*)"xx????xx????xxxxxxx");
	dwForceForward = FindPattern((PBYTE)"\x55\x8B\xEC\x51\x53\x8A\x5D\x08", (char*)"xxxxxxxx");
	dwForceJump = FindPattern((PBYTE)"\x8B\x0D\x00\x00\x00\x00\x8B\xD6\x8B\xC1\x83\xCA\x02", (char*)"xx????xxxxxxx");
	//dwForceLeft = FindPattern((PBYTE)"\x55\x8B\xEC\x51\x53\x8A\x5D\x08", (char*)"xxxxxxxx");
	//dwForceRight = FindPattern((PBYTE)"\x55\x8B\xEC\x51\x53\x8A\x5D\x08", (char*)"xxxxxxxx");
	dwGlow = FindPattern((PBYTE)"\xA1\x00\x00\x00\x00\xA8\x01\x75\x4B", (char*)"x????xxxx");
	dwLocalPlayer = FindPattern((PBYTE)"\x8D\x34\x85\x00\x00\x00\x00\x89\x15\x00\x00\x00\x00\x8B\x41\x08\x8B\x48\x04\x83\xF9\xFF", (char*)"xxx????xx????xxxxxxxxx");
	dwRadarBase = FindPattern((PBYTE)"\xA1\x00\x00\x00\x00\x8B\x0C\xB0\x8B\x01\xFF\x50\x00\x46\x3B\x35\x00\x00\x00\x00\x7C\xEA\x8B\x0D", (char*)"x????xxxxxxx?xxx????xxxx");
	dwViewMatrix = FindPattern((PBYTE)"\x0F\x10\x05\x00\x00\x00\x00\x8D\x85\x00\x00\x00\x00\xB9", (char*)"xxx????xx????x");
	dwbSendPackets = FindPattern2((PBYTE)"\xB3\x01\x8B\x01\x8B\x40\x10\xFF\xD0\x84\xC0\x74\x0F\x80\xBF\x00\x00\x00\x00\x00\x0F\x84", (char*)"xxxxxxxxxxxxxxx?????xx");
	m_bDormant = FindPattern((PBYTE)"\x8A\x81\x00\x00\x00\x00\xC3\x32\xC0", (char*)"xx????xxx");
}