#if defined _mg_round_manager_included
    #endinput
#endif

#define _mg_round_manager_included

#include <mg_round_manager_const>

native mg_rmanager_roundend_trigger(type);

native mg_rmanager_toundtime_get();
native mg_rmanager_toundtime_set(value);

native mg_rmanaget_time_get(value);
native mg_rmanaget_time_set();
native mg_rmanaget_time_add(value);

forward mg_fw_round_end_pre(type);
forward mg_fw_round_end_post(type);
forward mg_fw_round_respawn();
forward mg_fw_round_start_post();