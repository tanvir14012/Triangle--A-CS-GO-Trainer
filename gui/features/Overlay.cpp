#include "Overlay.h"
bool DrawingESP::WorldToScreen(vector3 from, float * to)
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

float DrawingESP::vectorDistance(vector3 src, vector3 des)
{
		return sqrt(pow(des.x - src.x, 2) + pow(des.y - src.y, 2) + pow(des.z - src.z, 2));
	}

void DrawingESP::DrawFilledRect(int x, int y, int w, int h)
{
		//We create our rectangle to draw on screen
		RECT rect = { x, y, x + w, y + h };
		//We clear that portion of the screen and display our rectangle
		FillRect(h_Desktop, &rect, hbrush);
	}

void DrawingESP::DrawBorderBox(int x, int y, int w, int h, int thickness)
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

void DrawingESP::DrawLine(float StartX, float StartY, float EndX, float EndY, COLORREF Pen)
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

void DrawingESP::DrawString(int x, int y, COLORREF color, const char* text)
{
		SetTextAlign(h_Desktop, TA_CENTER | TA_NOUPDATECP);

		SetBkColor(h_Desktop, RGB(0, 0, 0));
		SetBkMode(h_Desktop, TRANSPARENT);

		SetTextColor(h_Desktop, color);

		HGDIOBJ previousFont = SelectObject(h_Desktop, font);

		TextOutA(h_Desktop, x, y, text, strlen(text));

		SelectObject(h_Desktop, previousFont);
	}

void DrawingESP::drawESP(int x, int y, float distance, bool line, COLORREF color, bool boxESP, bool itemESP)
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

DrawingESP::DrawingESP()
{
		hbrush = CreateSolidBrush(RGB(0, 255, 255));
		hwnd = FindWindow(NULL, L"Counter-Strike: Global Offensive");
		h_Desktop = GetDC(hwnd);
		hpen = CreatePen(PS_SOLID, 2, RGB(0, 255, 255));
		GetWindowRect(hwnd, &windowRect);
		font = CreateFont(15, 0, 0, 0, FW_REGULAR, 0, 0, 0, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS,
			CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, DEFAULT_PITCH | FF_SWISS, L"Segoe UI");
	}

void DrawingESP::drawBox(bool boxESP,bool friendly, bool enemy, myColor boxEspColor, bool lineESP, bool nameESP, bool healthESP, bool itemESP)
{
		if (!boxESP && !nameESP && !healthESP && !itemESP && !lineESP)
		{
			return ;
		}
		static DWORD entity, entityTeam, entityHealth, vTable, fN, ptr, classID, localPlayer, localTeam, pointerToGlow, objCount;
		static float screenXY[2];
		static vector3 entityPosition, localPosition;
		std::string health;
		std::string name;
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
								DrawString(screenXY[0] - windowRect.left, screenXY[1] - windowRect.top + 12, RGB(0, 255, 255), (const char*)name.c_str());
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

	std::string DrawingESP::getName(int index)
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
		var.szName[sizeof(var.szName) - 1] = '\0';
		return std::string(var.szName);
	}

DrawingESP::~DrawingESP()
{
    DeleteObject(font);
    DeleteObject(hbrush);
    DeleteObject(hpen);
    ReleaseDC(hwnd, h_Desktop);
}
