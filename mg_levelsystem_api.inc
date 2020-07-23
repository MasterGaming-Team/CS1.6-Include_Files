#if defined _mg_levelsystem_api_included
    #endinput
#endif

#define _mg_levelsystem_api_included

native mg_level_client_level_get(id);

native mg_level_client_exp_set(id, exp);
native mg_level_client_exp_get(id);
native mg_level_client_exp_add(id, amount);

forward mg_fw_client_levelup(id, level, expLeft)