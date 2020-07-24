#if defined _mg_tutormessages_api_included
    #endinput
#endif

#define _mg_tutormessages_api_included

#include <mg_tutormessages_api_const>

native mg_tutormessage_send(id, const text[], type = TUTORTYPE_YELLOW, Float:time = 5.0, const soundEffect[] = "", bool:primary = false, bool:immediately = false);
native mg_tutormessage_clear(id);