#if defined _zi_core_included
	#endinput
#endif

#define _zi_core_included

#include <cstrike>
#include <zi_core_const>

native zi_core_arrayid_gamemode_get(arrayId = -1, arrayName = -1, arrayType = -1, arrayLaser = -1, arrayShield = -1, arrayInfect = -1, arrayRespawn = -1);
native zi_core_arrayid_zombie_get(arrayId = -1, arrayName = -1, arrayDesc = -1, arrayModel = -1);
native zi_core_arrayid_zombiesub_get(arrayParent = -1, arrayId = -1, arrayName = -1, arrayDesc = -1, arrayModel = -1, arrayBody = -1, arrayHealth = -1, arraySpeed = -1, arrayGravity = -1);
native zi_core_arrayid_human_get(arrayId = -1, arrayName = -1, arrayDesc = -1, arrayModel = -1, arrayBody = -1);
native zi_core_arrayid_hero_get(arrayId = -1, arrayName = -1, arrayTeam = -1);

native zi_core_allow_laser();
native zi_core_allow_shield();
native zi_core_allow_infect();
native zi_core_allow_respawn();

native zi_core_gamemode_reg(gamemodeId, const gamemodeName[], gamemodeType, bool:gamemodeAllowLaser, bool:gamemodeAllowShield, bool:gamemodeAllowInfect, bool:gamemodeAllowRespawn);

native zi_core_class_zombie_reg(classId, const className[], const classDesc[], const classModel[]);
native zi_core_class_zombiesub_reg(classParent, classId, const className[], const classDesc, const classModel, classBody, classHealth, classSpeed, classGravity);
native zi_core_class_human_reg(classId, const className[], const classDesc[], const classModel, classBody);
native zi_core_class_hero_reg(classId, const className[], classTeam);

native zi_core_class_zombie_arrayslot_get(classId);
native zi_core_class_zombiesub_arrayslot_get(classId);
native zi_core_class_human_arrayslot_get(classId);
native zi_core_class_hero_arrayslot_get(classId);

native zi_core_client_last(id, team);

native zi_core_client_zombiesub_available(id, classId);

native zi_core_client_zombie_get(id, next = false);
native zi_core_client_zombiesub_get(id, next = false);
native zi_core_client_human_get(id, next = false);
native zi_core_client_hero_get(id);

native zi_core_client_zombie_set(id, classId = ZI_CLASS_NONE, classSubId = ZI_CLASS_NONE, current = false);
native zi_core_client_human_set(id, classId = ZI_CLASS_NONE, current = false);

native zi_core_client_infect(victim, attacker = 0);
native zi_core_client_cure(victim, attacker = 0);
native zi_core_client_heroisate(id, classId);

forward zi_fw_client_spawn(id);
forward zi_fw_client_last(id, team);

forward zi_fw_client_infect(victim, attacker, zombieClass, subClass);
forward zi_fw_client_cure(victim, attacker, humanClass);
forward zi_fw_client_heroisate(id, heroClass);

forward zi_fw_gamemode_chosen(gamemodeId);
forward zi_fw_countdown_start(gamemodeId);
forward zi_fw_gamemode_start(gamemodeId);
forward zi_fw_gamemode_end(gamemodeId);

forward zi_fw_class_zombiesub_critcheck(id, classId);

stock zi_client_armor_set(id, value)
{
	cs_set_user_armor(id, value, ZI_ARMOR_TYPE)
}

stock zi_client_armor_damage(id, Float:damage)
{
	cs_set_user_armor(id, zi_client_armor_get(id) - floatround(damage), ZI_ARMOR_TYPE)
}

stock zi_client_armor_get(id)
{
	return cs_get_user_armor(id)
}