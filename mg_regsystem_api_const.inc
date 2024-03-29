#if defined _mg_regsystem_api_const_included
  #endinput
#endif

#define _mg_regsystem_api_const_included

#define MAX_USERNAME_LENGTH     32
#define MAX_PASSWORD_LENGTH     32
#define MIN_USERNAME_LENGTH     6
#define MIN_PASSWORD_LENGTH     6
#define MAX_SETINFOPW_LENGTH    32
#define MAX_EMAIL_LENGTH        320
#define MIN_EMAIL_LENGTH        3

#define ERROR_SQL_ERROR         0 // Type of error when a connection or structure problem has occured 
#define ERROR_ACCOUNT_NOT_FOUND 1 // Type of error when the account of the player was not found
#define ERROR_DONT_NOTIFY       2 // Type of error when autologin's being done(This is here, so the player won't see random messages after joining)
#define ERROR_ACCOUNT_USED      3 // Type of error when account is used(login) or already exists(register)

#define SQL_SAVETYPE_LOGOUT     0 // Type of logging out
#define SQL_SAVETYPE_REGULAR    1 // Type of normal save(called at every 30secs)

#define MG_SQLID_ZICLASSES      0
#define MG_SQLID_MISSIONS       1
#define MG_SQLID_LEVEL          2
#define MG_SQLID_ITEMS          3
#define MG_SQLID_AMMO           4

#define MG_SETTING_AUTOLOGIN          0
#define MG_SETTING_AUTOLOGINAUTHID    1
#define MG_SETTING_AUTOLOGINNAME      2
#define MG_SETTING_AUTOLOGINSETINFO   3
/* AMXX-Studio Notes - DO NOT MODIFY BELOW HERE
*{\\ rtf1\\ ansi\\ deff0{\\ fonttbl{\\ f0\\ fnil Tahoma;}}\n\\ viewkind4\\ uc1\\ pard\\ lang1066\\ f0\\ fs16 \n\\ par }
*/
