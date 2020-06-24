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
 * @param dest                  The string to copy to.
 * @param len                   Max length of the string.
 *
 * @return                      True.
 */
native mg_core_gamemode_get(const dest[], len);

/*
 * You can get the menuprefix with this
 *
 * @param dest                  The string to copy to.
 * @param len                   Max length of the strin.
 *
 * @return                      True.
 */
native mg_core_menu_prefix_get(const dest[], len);

/*
 * You can create a menu title with this
 *
 * @param id                    Player id.
 * @param titleLang             The lang access of the title's text.
 * @param titleLangLen          The max length of the titleLang parameter.
 * @param dest                  The string to copy the whole title line to.
 * @param destLen               The max length of the dest parameter.
 * @param lVersion              Set to true if you want to see the version of the server in the title.
 *
 * @return true
 */
native mg_core_menu_title_create(id, const titleLang[], const dest[], destLen, bool:lVersion = false);


/*
 * You can get the chat prefix with this
 *
 * @param dest                  The string to copy the prefix to.
 * @param len                   The max length of the dest.
 *
 * @return true
 */
native mg_core_chat_prefix_get();

/*
 * You can write a chatmessages with this.
 *
 * @note If chatTeam equals to CS_TEAM_UNASSIGNED then everyone to who the message
 * is sent to will see the team color as his team's color!
 *
 * @param id                    Player id.
 * @param type                  The message type(MG_CM_*), see mg_core_const.inc.
 * @param message               The message you want to send, string.
 * @param chatTeam              CS_TEAM_*, the team to set the team color to.
 *
 * @return true
 */
native mg_core_chatmessage_print(id, type, CsTeams:chatTeam = CS_TEAM_UNASSIGNED, const message[], ...);

/*
 * You can register a lang type message to be sent frequently
 *
 * @param frequentMessageLang   The lang name of the message to be sent.
 *
 * @return true
 */
native mg_core_chatmessage_freq_reg(const frequentMessageLang[]);

/*
 * You can block the next upcoming chat message with this.
 */
native mg_core_chatmessage_freq_block();

/*
 * Registers a command.
 * @note The command should look like this: mg_core_command_reg("command", "function")
 * @note The function must be public, it triggers console commands either.
 * @note In chat, the commands are registered with "!" and with "/" prefixes!
 *
 * @param command               The command with which the function can be triggered.
 * @param function              The public functions name.
 */
native mg_core_command_reg(const command[], const function[]);

/*
 * Deletes a command.
 *
 * @param command               The command to delete.
 *
 * @return                      True if it was successfully deleted, false if there was no command like this.
 */
native mg_core_command_del(const command[]);