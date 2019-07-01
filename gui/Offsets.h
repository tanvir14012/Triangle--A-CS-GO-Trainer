#pragma once
#include <Windows.h>
DWORD dwLocalPlayer = 0xCBD6A4;  //will be scanned ...
DWORD dwGlow = 0x520DA80;        
DWORD dwEntityList = 0x4CCDC3C;
DWORD dwCrosshairId = 0xB394;
DWORD m_hActiveWeapon = 0x2EF8;

DWORD m_dwBoneMatrix = 0x26A8;
DWORD m_vecOrigin = 0x138;
DWORD m_vecViewOffset = 0x108;
DWORD dwClientState = 0x58ACFC;
DWORD dwClientState_State = 0x108;
DWORD dwClientState_GetLocalPlayer = 0x180;
DWORD dwClientState_ViewAngles = 0x4D10;
DWORD m_bSpotted = 0x93D;
DWORD m_bSpottedByMask = 0x980;
DWORD m_viewPunchAngle = 0x3020;
DWORD m_aimPunchAngle = 0x302C;
DWORD dwForceAttack = 0x30FF2A0;
DWORD m_iShotsFired = 0xA370;

DWORD m_iGlowIndex = 0xA3F8;
DWORD m_flFlashMaxAlpha = 0xA3DC;
DWORD  m_fFlags = 0x104;
DWORD dwForceJump = 0x5170DF0;
DWORD dwForceForward = 0x30FF2F4;
DWORD dwbSendPackets = 0xD210A;
DWORD dwViewMatrix = 0x4CBF614;
DWORD dwClientState_PlayerInfo = 0x5240;
DWORD dwRadarBase = 0x510297C;


DWORD m_bDormant = 0xED;
DWORD dwTeam = 0xF4;
DWORD dwHealth = 0x100;
//Skin
DWORD  m_nFallbackPaintKit = 0x31B8;
DWORD m_nFallbackStatTrak = 0x31C4;
DWORD m_iItemIDHigh = 0x2FC0;
DWORD m_bInitialized = 0x2FD4;//
DWORD m_AttributeManager = 0x2D80;
DWORD m_Item = 0x2DC0;
DWORD m_OriginalOwnerXuidLow = 0x31B0;
DWORD m_OriginalOwnerXuidHigh = 0x31B4;
DWORD m_flFallbackWear = 0x31C0;
DWORD m_hMyWeapons = 0x2DF8;
DWORD m_iItemDefinitionIndex = 0x2FAA;
//Knife
DWORD m_nModelIndex = 0x258;
DWORD  m_iViewModelIndex = 0x3220;
DWORD m_iWorldModelIndex = 0x3224;
DWORD m_hViewModel = 0x32F8;

enum BoneIds
{
	BONE_HEAD = 8,
	BONE_NECK = 7,
	BONE_CHEST = 6,
	BONE_BELLY = 5,
	BONE_LOWERBELLY = 4,
	BONE_WAIST = 3,
	BONE_WAIST2 = 0,
	BONE_PELVIS = 77,
	BONE_RARM = 11,
	BONE_LARM = 41,
	BONE_RLEG = 71,
	BONE_LLEG = 78,
	BONE_RSHOE = 72,
	BONE_LSHOE = 79,
	BONE_RHAND = 12,
	BONE_LHAND = 42
};