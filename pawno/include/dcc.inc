
#include <discord-connector>

new DCC_Channel:BotChannel;

#define DC_CMD:%0(%1,%2)          \
			forward dc_cmd_%0(%1[],%2[]); \
			public dc_cmd_%0(%1[],%2[])

			
//CallBacks
forward OnDCCommandPerformed(args[], success);		
forward SendDC(channel[], const fmat[], va_args<>);

//Functions

public SendDC(channel[], const fmat[], va_args<>)
{
    new
        str[145];
    va_format(str, sizeof (str), fmat, va_start<2>);
	BotChannel = DCC_FindChannelById(channel);
    return DCC_SendChannelMessage(BotChannel, str);
}
//CommandsSection
public DCC_OnChannelMessage(DCC_Channel:channel, DCC_User:author, const message[])
{
	new channel_name[100 + 1];
	if(!DCC_GetChannelName(channel, channel_name))
		return 0; // invalid channel

	new user_name[32 + 1];
	if (!DCC_GetUserName(author, user_name))
		return 0; // invalid user

	if(!strcmp(user_name, BOT_NAME, true)) return 1;
	
	if(!strcmp(channel_name, BOT_CHANNEL, true)) // If user is bot then quit the callback.
	{
		new dmsg[10][128];
		explode(dmsg, message, " ", 2); // Used so we can see if the arguments next to command are empty or have value.
	
		new command[10], args[50];
		sscanf(message, "s[10]s[50]", command, args); // Sperate message in COMMAND and arguments.
		if(strfind(command, CMD_PREFIX, true) != -1) // Check if command have prefix defined above.
		{
			new funcdc[128];
			strdel(command, 0, 1);
			format(funcdc, sizeof(funcdc), "dc_cmd_%s", command); // Format function.
			
			if(isnull(dmsg[1])) {
				CallLocalFunction("OnDCCommandPerformed", "si", message, CallLocalFunction(funcdc, "ss", user_name, "\1"));
			} else CallLocalFunction("OnDCCommandPerformed", "si", message, CallLocalFunction(funcdc, "ss", user_name, args));
				
			
		}
	}
	return 1;
}
//Explode
stock explode(aExplode[][], const sSource[], const sDelimiter[] = " ", iVertices = sizeof aExplode, iLength = sizeof aExplode[])
{
	new
		iNode,
		iPointer,
		iPrevious = -1,
		iDelimiter = strlen(sDelimiter);

	while(iNode < iVertices)
	{
		iPointer = strfind(sSource, sDelimiter, false, iPointer);

		if(iPointer == -1)
		{
			strmid(aExplode[iNode], sSource, iPrevious, strlen(sSource), iLength);
			break;
		}
		else
		{
			strmid(aExplode[iNode], sSource, iPrevious, iPointer, iLength);
		}

		iPrevious = (iPointer += iDelimiter);
		++iNode;
	}

	return iPrevious;
}