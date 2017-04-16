# Elegant-Login-Register-TextDraws


| Credits | Reason |
| --- | --- |
| n0minal| Inspired by his TextDraws|
| Jelly23 | Scripting Support |
| Zamaroth | TextDraw Editor |



```
CreateGlobalLoginTextDraws()             - Create all Global-TextDraws
CreatePlayerLoginTextDraws(playerid)     - Create all Player-TextDraws
ShowLoginTextDraws(playerid)             - Show all TextDraws
HideLoginTextDraws(playerid)             - Hide all TextDraws
DestroyGlobalLoginTextDraws()            - Destroys all Global-TextDraws
DestroyPlayerLoginTextDraws(playerid)    - Destroys all Player-TextDraws
PlayerIsRegistered(playerid)             - Adapt the Textdraw messages to already registered players
PlayerIsNotRegistered(playerid)          - Adapt the Textdraw messages to players who are not registered
#define LoginTextDrawColor               - Change the TextDraw Color (PAWN HEX CODE)
#define TextDrawHoverColor               - Change the TextDraw Hover Color (PAWN HEX CODE)
#define LT_ServerName                    - Adapt's the Servername (Welcome to YOUR_SERVERNAME..)
#define RandomLoginColors                - Uncommented = Random TextDraw colors for each player

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

Example of showing Dialogs to registered / not registered users.
The variable pRegistered is automaticly set if you use PlayerIsRegistered(playerid); & PlayerIsNotRegistered(playerid); to adapt the textdraws to the player.

```

public OnPlayerClickPlayerTextDraw(playerid, PlayerText:playertextid) 
{
  if(playertextid == PlayerLoginTextDraw[playerid][0])
  {
    if(pRegistered[playerid] == true)
    {
      ShowPlayerDialog(playerid,D_Login,DIALOG_STYLE_PASSWORD,"Log in","Melde dich mit deinem Passwort an","Login","Bye");
    }
    else
    {
      ShowPlayerDialog(playerid,D_Register,DIALOG_STYLE_PASSWORD,"Registrieren","Gib ein Passwort ein um ein Account anzulegen","Registrieren","Bye");
    }
}

```
