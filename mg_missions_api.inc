#if defined _mg_missions_api_included
    #endinput
#endif

#define _mg_missions_api_included

#include <mg_missions_api_const>

native mg_missions_arrayid_get(arrayId = -1, arrayName = -1, arrayDesc = -1, arrayRequired = -1, arrayNext = -1,
                        arrayTargetValue = -1, arrayPrizeExp = -1, arrayPrizeMP = -1);

native mg_missions_client_mpoint_set();
native mg_missions_client_mpoint_get();
native mg_missions_client_mpoint_add();

native mg_missions_client_status_set();
native mg_missions_client_status_get();

native mg_missions_client_value_set();
native mg_missions_client_value_get();
native mg_missions_client_value_add();

forward mg_fw_client_mission_done(id, missionId, missionPrizeExp);
forward mg_fw_client_mission_unlocked(id, missionId, unlockerMissionId);