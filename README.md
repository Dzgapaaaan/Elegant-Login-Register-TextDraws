# Elegant-Login-Register-TextDraws


| Credits | Reason |
| --- | --- |
| Zamaroht | Using his TextDraw Editor |
| n0minal | Inspired by his TextDraws |


```
CreateLoginTextDraws(playerid) 	- Create all TextDraws
ShowLoginTextDraws(playerid) 	- Show all TextDraws
HideLoginTextDraws(playerid) 	- Hide all TextDraws
DestroyLoginTextDraws(playerid) - Destroys all TextDraws
PlayerIsRegistered(playerid) 	- Adapt the Textdraw messages to already registered players
PlayerIsNotRegistered(playerid) - Adapt the Textdraw messages to players who are not registered
#define LoginTextDrawColor	- Change the TextDraw Color (PAWN HEX CODE)
#define TextDrawHoverColor 	- Change the TextDraw Hover Color (PAWN HEX CODE)
#define LT_ServerName		- Adapt's the Servername (Welcome to YOUR_SERVERNAME..)

```

Example of showing TextDraws to registered / not registered players:

```

public OnPlayerConnect(playerid)
{
    if(mysql_num_rows() != 0)
    {
      //Player is registered
      PlayerIsRegistered(playerid);
      } 
        else 
      {
      //Player is not registered
      PlayerIsNotRegistered(playerid);
    }
    return 1;

```

Example of using the Buttons

```

public OnPlayerClickPlayerTextDraw(playerid, PlayerText:playertextid)
{

  new string[1024];
  if(playertextid == LoginTextDraw[playerid][11])
  {
    if(pData[playerid][P_Logged] == false)
    {
      new Query[39 + MAX_PLAYER_NAME];
      format(Query, sizeof(Query),"SELECT * FROM `players` WHERE Name = '%s'",GetName(playerid));

      mysql_query(MySQL, Query);
      mysql_store_result();
      if(mysql_num_rows() != 0)
      {
        ShowPlayerDialog(playerid,D_Login,DIALOG_STYLE_PASSWORD,"Log in","Type your password below to sign in","Sign In","Quit");
      }

      else
      {
        ShowPlayerDialog(playerid,D_Register,DIALOG_STYLE_PASSWORD,"Registering","Type in your password to register yourself.","Register","Quit");
      }
        mysql_free_result();
      }
        else
      {
        pData[playerid][P_Logged] = true;
      }
  }
  
  if(playertextid == LoginTextDraw[playerid][12])
  {
    strcat(string,"{FFFFFF}<Unknown Server Name>\n");
    strcat(string,"{FFFFFF}Describe here your server..\n");
    strcat(string,"{FFFFFF}Describe here your server..\n");
    strcat(string,"{FFFFFF}Describe here your server..\n");
    strcat(string,"{FFFFFF}Describe here your server..\n");
    strcat(string,"{FFFFFF}Describe here your server..\n");
    strcat(string,"{FFFFFF}Describe here your server..\n");
    strcat(string,"{FFFFFF}Describe here your server..\n");
    ShowPlayerDialog(playerid, D_About, DIALOG_STYLE_MSGBOX, "About the Server", string, "Ok", "");
  }

  if(playertextid == LoginTextDraw[playerid][13])
  {
    //Rules Button
    strcat(string,"{FF0000}Read carefully all rules:\n\n");
    strcat(string,"{FFFFFF}- Don't use cheats / illegal modifications\n");
    strcat(string,"{FFFFFF}- Behave\n");
    ShowPlayerDialog(playerid, D_Rules, DIALOG_STYLE_MSGBOX, "Server Rules", string, "Ok", "");
  }

  if(playertextid == LoginTextDraw[playerid][14])
  {
    strcat(string,"{FF0000}Special thanks to:\n\n");
    strcat(string,"{FFFFFF}JustMe.77 - Scripting\n");
    strcat(string,"{FFFFFF}Unknown69 - Mapping\n");
    ShowPlayerDialog(playerid, D_Rules, DIALOG_STYLE_MSGBOX, "Credits", string, "Ok", "");
  }

}

```
