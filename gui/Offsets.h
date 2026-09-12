#pragma once
#include <Windows.h>
extern DWORD dwLocalPlayer;  //will be scanned ...
extern DWORD dwGlow;
extern DWORD dwEntityList;
extern DWORD dwCrosshairId;
extern DWORD m_hActiveWeapon;

extern DWORD m_dwBoneMatrix;
extern DWORD m_vecOrigin;
extern DWORD m_vecViewOffset;
extern DWORD dwClientState;
extern DWORD dwClientState_State;
extern DWORD dwClientState_GetLocalPlayer;
extern DWORD dwClientState_ViewAngles;
extern DWORD m_bSpotted;
extern DWORD m_bSpottedByMask;
extern DWORD m_viewPunchAngle;
extern DWORD m_aimPunchAngle;
extern DWORD dwForceAttack;
extern DWORD m_iShotsFired;

extern DWORD m_iGlowIndex;
extern DWORD m_flFlashMaxAlpha;
extern DWORD m_fFlags;
extern DWORD dwForceJump;
extern DWORD dwForceForward;
extern DWORD dwbSendPackets;
extern DWORD dwViewMatrix;
extern DWORD dwClientState_PlayerInfo;
extern DWORD dwRadarBase;


extern DWORD m_bDormant;
extern DWORD dwTeam;
extern DWORD dwHealth;
//Skin
extern DWORD m_nFallbackPaintKit;
extern DWORD m_nFallbackStatTrak;
extern DWORD m_iItemIDHigh;
extern DWORD m_bInitialized;//
extern DWORD m_AttributeManager;
extern DWORD m_Item;
extern DWORD m_OriginalOwnerXuidLow;
extern DWORD m_OriginalOwnerXuidHigh;
extern DWORD m_flFallbackWear;
extern DWORD m_hMyWeapons;
extern DWORD m_iItemDefinitionIndex;
//Knife
extern DWORD m_nModelIndex;
extern DWORD m_iViewModelIndex;
extern DWORD m_iWorldModelIndex;
extern DWORD m_hViewModel;

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