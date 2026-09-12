#pragma once
#include "../Header.h"
#include "../Offsets.h"
#include "../SkinId.h"
#include "ProcessMemory.h"
#include "VisualTypes.h"
class Aimbot
{
private:
	//oyvhgyy *junk;
	struct vector3 {
		float x = 0;
		float y = 0;
		float z = 0;
	};
	vector3 subtract(vector3 src, vector3 des);
	float vectorDistance(vector3 src, vector3 des);
	vector3 GetBonePosition(DWORD dwEntity, int iTargetBone);
	float vectorMagnitude(vector3 vector);
	vector3 addVectors(vector3 a, vector3 b);
	bool isAngleValid(vector3 angle);
	void normalizeAngles(vector3 &angles);
	int getRandomBone();
	int getLock(int index);
	vector3 calculateAngles(DWORD enemyEntity, int lock);
	void smooth(vector3 oldAngles, vector3 &newAngles, float smooth);
	float maxAngleDifference(vector3 a, vector3 b);
	float angleDifference(vector3 a, vector3 b);
public:
	//Aimbot():oyvhgyy()

	void startAimbot(bool on, bool autoFire, int aimKey, int fov, int smoother, int aimlock);

	void rcs(bool on);

	void afk(bool on);
};
