#pragma once

#include "../Math/Vectors.hpp"
#include <list>

// Generated using ReClass.NET

enum struct EPlayerActions // GEnum3
{
	None,
	Healing,
	HealingCupgrade,
	Zipline
};
enum struct EPlatformType // GEnum26
{
	Anonymous,
	Steam,
	Xbox,
	PSN,
	Switch,
	FB
};
enum struct EWalkMode // GEnum34
{
	Slow,
	Normal,
	Roll,
	RollCreep,
	Vehicle,
	Downed,
	BananaStun,
	ParachuteFreefallSplat
};

class LocalPlayerScript
{
public:
	char pad_0000[24]; //0x0000
	void* camera; //0x0018
	float horizInput; //0x0020
	float vertInput; //0x0024
	Vector2 velocity; //0x0028
	char pad_0030[8]; //0x0030
	void* gameLevelType; //0x0038
	void* mainGameScript; //0x0040
	class NetworkPlayer* player; //0x0048
	char pad_0050[116]; //0x0050
	bool canFlightEject; //0x00C4
	char pad_00C5[3]; //0x00C5
	Vector2 lastServerPosition; //0x00C8
}; //Size: 0x00D0

class NetworkPlayer
{
public:
	char pad_0000[48]; //0x0000
	int32_t eAction; //0x0030
	char pad_0034[60]; //0x0034
	class GameCamera* gameCamera; //0x0070
	char pad_0078[64]; //0x0078
	int16_t playerID; //0x00B8
	char pad_00BA[22]; //0x00BA
	int32_t ePlatformType; //0x00D0
	char pad_00D4[4]; //0x00D4
	wchar_t* playerName; //0x00D8
	int32_t accountLevelIndex; //0x00E0
	bool isAdminStartingGhost; //0x00E4
	char pad_00E5[11]; //0x00E5
	class LocalPlayerScript* localPlayerScript; //0x00F0
	char pad_00F8[40]; //0x00F8
	float currentGunAngleToMouse; //0x0120
	bool isPressingMoveKeys; //0x0124
	char pad_0125[3]; //0x0125
	float playerHP; //0x0128
	float playerHPMax; //0x012C
	bool playerIsDead; //0x0130
	char pad_0131[15]; //0x0131
	int32_t numKills; //0x0140
	int16_t killedByPlayerID; //0x0144
	char pad_0146[74]; //0x0146
	int8_t weaponID; //0x0190
	char pad_0191[31]; //0x0191
	float healingJuice; //0x01B0
	bool healingCurrently; //0x01B4
	char pad_01B5[11]; //0x01B5
	int8_t ductTapes; //0x01C0
	char pad_01C1[23]; //0x01C1
	int8_t currArmorLvl; //0x01D8
	char pad_01D9[3]; //0x01D9
	int32_t currArmorAmount; //0x01DC
	int32_t grenadeCount; //0x01E0
	void* lastAttackTime; //0x01E4
	char pad_01EC[16]; //0x01EC
	float lastAttackTimeMelee; //0x01FC
	bool attacking; //0x0200
	bool currentAttackIsMelee; //0x0201
	bool currentAttackIsAuto; //0x0202
	char pad_0203[181]; //0x0203
	Vector2 pos; //0x02BC
	char pad_02C4[24]; //0x02C4
	float currParachuteHeight; //0x02DC
	char pad_02E0[24]; //0x02E0
	bool inFlight; //0x02F8
	char pad_02F9[15]; //0x02F9
	int8_t walkMode; //0x0308
	char pad_0309[53]; //0x0309
	bool isZombie; //0x033E
	char pad_033F[69]; //0x033F
	float rollStartTime; //0x0384
	float rollEndTime; //0x0388
	char pad_038C[32]; //0x038C
	bool didHitBunnyHopRoll; //0x03AC
	char pad_03AD[3]; //0x03AD
	float bunnyHopCurrentBonus; //0x03B0
	char pad_03B4[84]; //0x03B4
	class Bone* bone_1; //0x0408
	class Bone* bone_2; //0x0410
	class Bone* bone_3; //0x0418
	class Bone* bone_4; //0x0420
	class Bone* bone_5; //0x0428
	class Bone* bone_6; //0x0430
	class Bone* bone_7; //0x0438
	class Bone* bone_8; //0x0440
	char pad_0448[16]; //0x0448
	class SkeletalBounds* skeletalBounds; //0x0458
	char pad_0460[53]; //0x0460
	bool isWithinVisionBounds; //0x0495
	char pad_0496[6]; //0x0496
}; //Size: 0x049C

class GameCamera
{
public:
	char pad_0000[24]; //0x0000
	Vector2 camTarget; //0x0018
	float camAngleRadians; //0x0020
	char pad_0024[8]; //0x0024
	bool inFlight; //0x002C
	char pad_002D[3]; //0x002D
	float mainOrthoSize; //0x0030
	char pad_0034[8]; //0x0034
	float ghostMaxOrthoSize; //0x003C
	char pad_0040[12]; //0x0040
	bool isAdminGhost; //0x004C
	char pad_004D[19]; //0x004D
	bool adminGhostNeedsRefreshUI; //0x0060
	char pad_0061[23]; //0x0061
	void* unityCamera; //0x0078
}; //Size: 0x0080

class Bone
{
public:
	char pad_0000[16]; //0x0000
	class BoneData* data; //0x0010
	char pad_0018[8]; //0x0018
	class Bone* parentBone; //0x0020
	char pad_0028[8]; //0x0028
	float x; //0x0030
	float y; //0x0034
	float rotation; //0x0038
	float scaleX; //0x003C
	float scaleY; //0x0040
	char pad_0044[8]; //0x0044
	float ax; //0x004C
	float ay; //0x0050
	float arotation; //0x0054
	float ascaleX; //0x0058
	float ascaleY; //0x005C
	char pad_0060[16]; //0x0060
	float worldX; //0x0070
	char pad_0074[8]; //0x0074
	float worldY; //0x007C
}; //Size: 0x0080

class BoneData
{
public:
	char pad_0000[16]; //0x0000
	int32_t index; //0x0010
	char pad_0014[4]; //0x0014
	wchar_t* name; //0x0018
	class BoneData* parent; //0x0020
	char pad_0028[4]; //0x0028
	float x; //0x002C
	float y; //0x0030
	float rotation; //0x0034
	float scaleX; //0x0038
	float scaleY; //0x003C
}; //Size: 0x0040

class SkeletalBounds
{
public:
	char pad_0000[24]; //0x0000
	float minX; //0x0018
	float minY; //0x001C
	float maxX; //0x0020
	float maxY; //0x0024
}; //Size: 0x0028

constexpr const int LOCAL_PLAYER_INDEX = 0;
class GameContext
{
public:
	explicit GameContext()
		: localPlayer(nullptr)
	{}

	LocalPlayerScript* localPlayer = nullptr;

	std::list<NetworkPlayer*> players;
};