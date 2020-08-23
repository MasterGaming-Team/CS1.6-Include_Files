#if defined _mg_core_const_included
    #endinput
#endif

#define _mg_core_const_included

#include <amxmodx>

#define MG_SERVER_GLOBAL            0
#define MG_SERVER_ZOMBIEINSANITY    1
#define MG_SERVER_CAPTURETHEFLAG    2
#define MG_SERVER_CURRENT           MG_SERVER_GLOBAL

#define MG_SERVER_VERSION           " 0.1.0"
#define MG_SERVER_GAMEMODE          "[MG]Zombie Insanity"

#define MG_CM_PLAYERTOCHAT          0 // A player's message to the chat
#define MG_CM_FIX                   1 // A fix message by the server to a player or everyone(checked by id), automatically sets prefix
#define MG_CM_FIXFREQ               2 // Just like MG_CM_FIX only it blocks the frequent message for a little while, automatically sets prefix
#define MG_CM_NORMAL                3 // Same as fix, but it has no automatic prefix
#define MG_CM_NORMALFREQ            4 // Same as fixreq, but it has no automatic prefix

#define FT_PRE                      0
#define FT_PROCEED                  1
#define FT_POST                     2

#define OFFSET_CSMENUCODE           205
#define KEYSMENU                    MENU_KEY_1|MENU_KEY_2|MENU_KEY_3|MENU_KEY_4|MENU_KEY_5|MENU_KEY_6|MENU_KEY_7|MENU_KEY_8|MENU_KEY_9|MENU_KEY_0

#define mgDefLang   "en"
new stock mgLanguageList[2][3] = {"en", "hu"}
new stock mgServerPrefixList[3][6] = {"", "[ZI]", "[CTF]"}

/**
 * Converts an integer to a formal number in string.
 * Like:
 * input = 9999     ->   return = "9.999"
 * input = 3772316  ->   return = "3.772.316"
 *
 * @note NUMBERS ONLY SUPPORTED UP TO 9.999.999!!
 */
stock mg_core_integer_to_formal(input)
{
    static lLeft[5], lRight[15], lText[20]

    num_to_str(input, lText, charsmax(lText))
	
    if(input > 999)
    {	
        if(input>= 1000 && input <= 9999)
            split(lText, lLeft, charsmax(lLeft), lRight, charsmax(lRight), "")
        else if(input >= 10000 && input <= 99999)
            split(lText, lLeft, charsmax(lLeft), lRight, charsmax(lRight), "")
        else if(input >= 100000 && input <= 999999)
            split(lText, lLeft, charsmax(lLeft), lRight, charsmax(lRight), "")
        else if(input >= 1000000 && input <= 9999999)
            split(lText, lLeft, charsmax(lLeft), lRight, charsmax(lRight), "")
			
        formatex(lText, 11, "%s.%s", lLeft, lRight)
		
        if(input > 999999)
        {
            split(lText, lLeft, 1, lRight, 11, "")
            formatex(lText, 11, "%s.%s", lLeft, lRight)
        }
    }

    return lText
}

/*
 * Sends a chatmessage.
 * @note mg_core_chatmessage_print() uses this, highly recommended to use mg_core_chatmessage_print()!
 * 
 * @param id            The player id to send to. 0 if to send to everyone.
 * @param input         The string to send as the chatmessage.
 * @param chatTeam      CS_TEAM_*, the team to color the message to.
 *
 * @noreturn
 */
stock print_chatmessage(id, input[], CsTeams:chatTeam = CS_TEAM_UNASSIGNED)
{
    static lPlayerTeam[20], lChatTeam[20], lMsgSayText, lMsgTeamInfo, lMaxPlayers

    if(!lMsgSayText)
    {
        lMsgSayText = get_user_msgid("SayText")
        lMsgTeamInfo = get_user_msgid("TeamInfo")
        lMaxPlayers = get_maxplayers()
    }

    replace_all(input, 190, "%", "%%")
    replace_all(input, 190, ";", "%;")
    replace_all(input, 190, "!n", "^1")
    replace_all(input, 190, "!t", "^3")
    replace_all(input, 190, "!g", "^4")

    switch(chatTeam)
    {
        case CS_TEAM_T: copy(lChatTeam, charsmax(lChatTeam), "TERRORIST")
        case CS_TEAM_CT: copy(lChatTeam, charsmax(lChatTeam), "COUNTER-TERRORIST")
        case CS_TEAM_SPECTATOR: copy(lChatTeam, charsmax(lChatTeam), "SPECTATOR")
    }

    if(id)
	{
        get_user_team(id, lPlayerTeam, charsmax(lPlayerTeam))

        if(chatTeam == CS_TEAM_UNASSIGNED)
		{
			copy(lChatTeam, charsmax(lChatTeam), lPlayerTeam)
		}

        message_begin(MSG_ONE_UNRELIABLE, lMsgTeamInfo, _, id)
        write_byte(id)
        write_string(lChatTeam)
        message_end()

        message_begin(MSG_ONE_UNRELIABLE, lMsgSayText, _, id)
        write_byte(id)
        write_string(input)
        message_end()

        message_begin(MSG_ONE_UNRELIABLE, lMsgTeamInfo, _, id)
        write_byte(id)
        write_string(lPlayerTeam)
        message_end()

        return PLUGIN_HANDLED
	}
	
    for(new i = 1; i <= lMaxPlayers; i++)
	{
        if(!is_user_connected(i))
            continue

        get_user_team(i, lPlayerTeam, charsmax(lPlayerTeam))

        if(chatTeam == CS_TEAM_UNASSIGNED)
		{
			copy(lChatTeam, charsmax(lChatTeam), lPlayerTeam)
        }

        message_begin(MSG_ONE_UNRELIABLE, lMsgTeamInfo, _, i)
        write_byte(i)
        write_string(lChatTeam)
        message_end()

        message_begin(MSG_ONE_UNRELIABLE, lMsgSayText, _, i)
        write_byte(i)
        write_string(input)
        message_end()

        message_begin(MSG_ONE_UNRELIABLE, lMsgTeamInfo, _, i)
        write_byte(i)
        write_string(lPlayerTeam)
        message_end()
	}

    return PLUGIN_HANDLED
}
