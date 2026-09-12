#pragma once
#include "../Header.h"
#include "../Offsets.h"
#include "../SkinId.h"
#include "ProcessMemory.h"
#include "VisualTypes.h"
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
	bool WorldToScreen(vector3 from, float * to);
	float vectorDistance(vector3 src, vector3 des);
	void DrawFilledRect(int x, int y, int w, int h);
	void DrawBorderBox(int x, int y, int w, int h, int thickness);
	void DrawLine(float StartX, float StartY, float EndX, float EndY, COLORREF Pen);
	void DrawString(int x, int y, COLORREF color, const char* text);

	void drawESP(int x, int y, float distance, bool line, COLORREF color, bool boxESP, bool itemESP);

public:

	DrawingESP();

	void drawBox(bool boxESP,bool friendly, bool enemy, myColor boxEspColor, bool lineESP, bool nameESP, bool healthESP, bool itemESP);
	std::string getName(int index);
	~DrawingESP();
	DrawingESP(const DrawingESP&) = delete;
	DrawingESP& operator=(const DrawingESP&) = delete;
};
