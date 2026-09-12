#pragma once
#include "features/VisualTypes.h"
namespace gui {
	/// Summary for MyForm
	struct aimUi
	{
		bool on = false;
		bool autoFire = false;
		int aimKeyIndex = 0;
		int fov = 1;
		int smooth = 1;
		int aimlock = 3;
		bool rcs = false;
	};
	struct triggerUI
	{
		bool on = false;
		bool autoFire = false;
		int aimKeyIndex = 0;
		int delay = 0;
	};

	struct visualUI
	{
		bool glow_on = false;
		bool glow_friendly = false;
		myColor friendly_glow_color = { 0, 1, 0 };
		bool glow_enemy = false;
		myColor enemy_glow_color = { 1, 0, 0 };
		bool visibility_check = false;
		myColor visibility_check_color = { 1, 0.27, 0 };
		float alpha = 0.5;
		bool box_esp = false;
		myColor box_esp_color = { 0, 255, 255 };
		bool box_esp_friendly = false;
		bool box_esp_enemy = false;
		bool line_esp = false;
		bool item_esp = false;
		bool name_esp = false;
		bool radar_hack = false;
		bool health_esp = false;
	};

	struct misc
	{
		bool bunnyhop = false;
		bool autoAccept = false;
		bool noFlash = false;
		bool afk = false;
		bool fakeLag = false;
		int fakeLagDelay = 1;
	};


extern aimUi aim_ui;
extern triggerUI trigger_ui;
extern visualUI visual_ui;
extern misc misc_ui;
}
