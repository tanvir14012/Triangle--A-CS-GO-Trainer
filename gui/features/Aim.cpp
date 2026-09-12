#include "Aim.h"
Aimbot::vector3 Aimbot::subtract(vector3 src, vector3 des)
{
		vector3 ret;
		ret.x = des.x - src.x;
		ret.y = des.y - src.y;
		ret.z = des.z - src.z;
		return ret;
	}

float Aimbot::vectorDistance(vector3 src, vector3 des)
{
		return sqrt(pow(des.x - src.x, 2) + pow(des.y - src.y, 2) + pow(des.z - src.z, 2));
	}

Aimbot::vector3 Aimbot::GetBonePosition(DWORD dwEntity, int iTargetBone)
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

float Aimbot::vectorMagnitude(vector3 vector)
{
		return sqrt(vector.x*vector.x + vector.y*vector.y);
	}

Aimbot::vector3 Aimbot::addVectors(vector3 a, vector3 b)
{
		return vector3{ a.x + b.x, a.y + b.y, a.z + b.z };
	}

bool Aimbot::isAngleValid(vector3 angle)
{
		if ((angle.x >= -89.0 && angle.x <= 89.0) && (angle.y >= -180.0f && angle.y <= 180.0f) && angle.z == 0)
		{
			return true;
		}
		return false;
	}

void Aimbot::normalizeAngles(vector3 &angles)
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

int Aimbot::getRandomBone()
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
        default: return BONE_HEAD;
		}
	}

int Aimbot::getLock(int index)
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

Aimbot::vector3 Aimbot::calculateAngles(DWORD enemyEntity, int lock)
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

void Aimbot::smooth(vector3 oldAngles, vector3 &newAngles, float smooth)
{
		if (smooth < 1 || smooth > 50)
		{
			smooth = 5.0f;
		}
		newAngles.x = ((newAngles.x - oldAngles.x) / smooth) + oldAngles.x;
		newAngles.y = ((newAngles.y - oldAngles.y) / smooth) + oldAngles.y;
		newAngles.z = ((newAngles.z - oldAngles.z) / smooth) + oldAngles.z;
	}

float Aimbot::maxAngleDifference(vector3 a, vector3 b)
{
		return max(fabs(a.x - b.x), fabs(a.y - b.y));
	}

float Aimbot::angleDifference(vector3 a, vector3 b)
{
		return (fabs(a.x - b.x) + fabs(a.y - b.y));
	}

void Aimbot::startAimbot(bool on, bool autoFire, int aimKey, int fov, int smoother, int aimlock)
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

void Aimbot::rcs(bool on)
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

void Aimbot::afk(bool on)
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
