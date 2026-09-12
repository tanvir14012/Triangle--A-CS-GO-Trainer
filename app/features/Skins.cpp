#include "TrainerFunctions.h"
#include "SkinSettings.h"
weaponSkin weapon_skin;
knifeInfo knife_info;
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
    default: return 0;

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
