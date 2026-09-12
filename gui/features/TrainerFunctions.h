#pragma once
#include "../Header.h"
#include "../Offsets.h"
#include "../SkinId.h"
#include "ProcessMemory.h"
void noFlash(bool on);
void bunnyHop();
bool bCompare(const BYTE* Data, const BYTE* Mask, const char* szMask);
DWORD FindPattern(BYTE* Mask, char* szMask);
void autoAcceptMatch();
void radarHack(bool on);
void triggerbot(bool on, bool autoFire, int key, int delay);
void afk(bool on);
void fakeLag(System::Object^ delay);
DWORD FindPattern2(BYTE* Mask, char* szMask);
DWORD FindHudElement(std::string name);
void changeWeaponSkin();
int getPosition(int id);
int getNewKnifeException(int id);
void changeKnife();
void scanOffsets();
