#include "Glow.h"
void virtualesp::glow_player(DWORD mObj, float r, float g, float b, float alpha)
{
		memory.Write<float>(mObj + 0x4, r);
		memory.Write<float>(mObj + 0x8, g);
		memory.Write<float>(mObj + 0xC, b);
		memory.Write<float>(mObj + 0x10, alpha);
		memory.Write<BOOL>(mObj + 0x24, true);
		memory.Write<BOOL>(mObj + 0x25, false);
	}

void virtualesp::esp_thread(bool on, bool glow_friendly, myColor friendly_color, bool glow_enemy, myColor enemy_color, bool visibility_check, myColor visibility_color, float alpha)
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
