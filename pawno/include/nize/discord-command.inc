/*
	Discord Command Processor

	A simple library for discord based commands
	with iZCMD-like code and functionality. Does
	not require any additional libraries. Simple.

	Written by AliLogic
*/

// Include guard

#if defined _discordcmd_included
	#endinput
#endif
#define _discordcmd_included

#tryinclude <discord-connector_new>
#if !defined dcconnector_included
	#error To use this include you need to have "https://github.com/maddinat0r/samp-discord-connector" installed
#endif

// Config

#define MAX_CMD_LEN			(50)
#define MAX_CMD_NAME		(10)

// Prefix

#if	!defined CMD_PREFIX
	#define	CMD_PREFIX		'!'
#endif

// Macros

#define DISCORD:%1(%2)		\
	forward discord_%1(%2);	\
	public discord_%1(%2)

#define DC:%1(%2) 			\
	DISCORD:%1(%2)

// Command result

#define DISCORD_SUCCESS		(1)
#define DISCORD_FAILURE		(0)

// Code
public DCC_OnMessageCreate(DCC_Message: message) {

	new
		DCC_User: author,
		DCC_Channel: channel,
		bool: is_bot,
		discord_cmd[100];

	DCC_GetMessageChannel(message, channel);
	DCC_GetMessageAuthor(message, author);
	DCC_IsUserBot(author, is_bot);
	DCC_GetMessageContent(message, discord_cmd);

	if (!is_bot && discord_cmd[0] == CMD_PREFIX) { // Skip if the message author is a bot or is not a command

		new // static had issues
			discord[MAX_CMD_LEN] = "discord_",
			pos;

		if ((pos = strfind(discord_cmd, " ", false, 1)) == -1) { // Space was not found

			strcat(discord, discord_cmd[1], MAX_CMD_LEN - 8);

			#if defined OnDiscordCommandPerformed
				OnDiscordCommandPerformed(channel, author, bool: CallLocalFunction(discord, "iis", _: channel, _: author, "\1"));
			#else
				CallLocalFunction(discord, "iis", _: channel, _: author, "\1");
			#endif

		} else { // Space was found

			strcat(discord, discord_cmd[1], pos + 8);

			while (discord_cmd[pos] == ' ') { // Checks for spaces

				pos ++;
			}

			if (discord_cmd[pos]) { // Parameter was found

				#if defined OnDiscordCommandPerformed
					OnDiscordCommandPerformed(channel, author, bool: CallLocalFunction(discord, "iis", _: channel, _: author, discord_cmd[pos]));
				#else
					CallLocalFunction(discord, "iis", _: channel, _: author, discord_cmd[pos]);
				#endif

			} else { // Parameter was not found

				#if defined OnDiscordCommandPerformed
					OnDiscordCommandPerformed(channel, author, bool: CallLocalFunction(discord, "iis", _: channel, _: author, "\1"));
				#else
					CallLocalFunction(discord, "iis", _: channel, _: author, "\1");
				#endif
			}
		}
	}	
	
	#if defined discdcmd_DCC_OnMessageCreate
		return discdcmd_DCC_OnMessageCreate(DCC_Message: message);
	#else
		return 1;
	#endif
}

// Hooking and functions

#if defined _ALS_DCC_OnMessageCreate
	#undef DCC_OnMessageCreate
#else
	#define _ALS_DCC_OnMessageCreate
#endif

#define DCC_OnMessageCreate discdcmd_DCC_OnMessageCreate
#if defined discdcmd_DCC_OnMessageCreate
	forward discdcmd_DCC_OnMessageCreate(DCC_Message: message);
#endif

#if defined OnDiscordCommandPerformed
	forward OnDiscordCommandPerformed(DCC_Channel: channel, DCC_User: author, bool: success);
#endif
