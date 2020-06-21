#if defined _mg_core_const_included
    #endinput
#endif

#define _mg_core_const_included

#include <amxmodx>

#define MG_SERVER_GLOBAL            0
#define MG_SERVER_ZOMBIEINSANITY    1
#define MG_SERVER_CURRENT           MG_SERVER_ZOMBIEINSANITY

#define MG_SERVER_VERSION           "0.0.3"
#define MG_SERVER_GAMEMODE          "[MG]Zombie Insanity"

#define MG_CM_PLAYERTOCHAT          0 // A player's message to the chat
#define MG_CM_FIX                   1 // A fix message by the server to a player or everyone(checked by id)
#define MG_CM_FIXFREQ               2 // Just like MG_CM_FIX only it blocks the frequent message for a little while

/*
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

    switch(chatTeam)
    {
        case CS_TEAM_T: copy(lChatTeam, charsmax(lChatTeam), "TERRORIST")
        case CS_TEAM_CT: copy(lChatTeam, charsmax(lChatTeam), "COUNTER-TERRORIST")
        case CS_TEAM_SPECTATOR: copy(lChatTeam, charsmax(lChatTeam), "SPECTATOR")
    }

    if(id)
	{
        if(chatTeam == CS_TEAM_UNASSIGNED)
		{
			get_user_team(id, lPlayerTeam, charsmax(lPlayerTeam))
					
			message_begin(MSG_ONE_UNRELIABLE, lMsgTeamInfo, _, id)
			write_byte(id)
			write_string(lChatTeam)
			message_end()
		}
					
        message_begin(MSG_ONE_UNRELIABLE, lMsgSayText, _, id)
        write_byte(id)
        write_string(input)
        message_end()
					
        if(chatTeam == CS_TEAM_UNASSIGNED)
		{
			message_begin(MSG_ONE_UNRELIABLE, lMsgTeamInfo, _, id)
			write_byte(id)
			write_string(lPlayerTeam)
			message_end()
        }

        return PLUGIN_HANDLED
	}
	
    for(new i = 1; i <= lMaxPlayers; i++)
	{
		if(chatTeam == CS_TEAM_UNASSIGNED)
		{
			get_user_team(i, lPlayerTeam, charsmax(lPlayerTeam))
					
			message_begin(MSG_ONE_UNRELIABLE, lMsgTeamInfo, _, i)
			write_byte(i)
			write_string(lChatTeam)
			message_end()
        }

		message_begin(MSG_ONE_UNRELIABLE, lMsgSayText, _, i)
		write_byte(i)
		write_string(input)
		message_end()
					
		if(chatTeam == CS_TEAM_UNASSIGNED)
		{
			message_begin(MSG_ONE_UNRELIABLE, lMsgTeamInfo, _, i)
			write_byte(i)
			write_string(lPlayerTeam)
			message_end()
		}
	}

    return PLUGIN_HANDLED
}
