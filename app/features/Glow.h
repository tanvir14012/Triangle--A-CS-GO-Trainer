#pragma once
#include "../Header.h"
#include "../Offsets.h"
#include "../SkinId.h"
#include "ProcessMemory.h"
#include "VisualTypes.h"
class virtualesp //: public oyvhgyy
{
private:

	//oyvhgyy *junk;
	static void glow_player(DWORD mObj, float r, float g, float b, float alpha);


public:

	void esp_thread(bool on, bool glow_friendly, myColor friendly_color, bool glow_enemy, myColor enemy_color, bool visibility_check, myColor visibility_color, float alpha);
};
