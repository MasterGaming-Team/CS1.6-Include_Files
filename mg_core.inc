#if defined _mg_core_included
    #endinput
#endif

#define _mg_core_included

#include <mg_core_const>

/*
 * Returns the serverid, you can set it in mg_core_const.inc
 */
native mg_core_serverid_get();

/*
 * Loads the gamemode name into the string
 *
 * @param dest          The string to copy to.
 * @param len           Max length of the string.
 */
 native mg_core_gamemode_get(const dest[], len);