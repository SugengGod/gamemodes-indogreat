#include <a_http>

#define Function_IP:%1(%2) forward %1(%2); public %1(%2)

forward SendProxy(playerid);

Function_IP:GetPlayerProxyData(playerid) //player ip
{
    if(!IsPlayerNPC(playerid))
    {
	    new string[60];
	    new s_ip[16];
	    GetPlayerIp(playerid, s_ip, 16);
		format(string, sizeof(string), "ipdata.ultra-h.com/ipdata/proxyapi.php?ip=%s",s_ip);
		HTTP(playerid, HTTP_GET, string, "", "DataResponse");
	}
	return 1;
}

Function_IP:DataResponse(index, response_code, data[])
{
	if(index >= 0)
	{
		if(response_code == 200)
		{
		    if(strval(data) != 0)
			{
				if(funcidx("SendProxy")) CallLocalFunction("SendProxy", "i", index);
			}
		}
	}
}
