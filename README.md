# Elegant-Login-Register-TextDraws


| Credits | Reason |
| --- | --- |
| MP2 | PNS Coordinates |
| Jelly23 | Scripting Support |
| Kaliber | Scripting Support |



```
CreateLoginTextDraws(playerid) 	    - Create all TextDraws
ShowLoginTextDraws(playerid) 	    - Show all TextDraws
HideLoginTextDraws(playerid) 	    - Hide all TextDraws
DestroyLoginTextDraws(playerid)     - Destroys all TextDraws
PlayerIsRegistered(playerid) 	    - Adapt the Textdraw messages to already registered players
PlayerIsNotRegistered(playerid)     - Adapt the Textdraw messages to players who are not registered
#define LoginTextDrawColor          - Change the TextDraw Color (PAWN HEX CODE)
#define TextDrawHoverColor 	    - Change the TextDraw Hover Color (PAWN HEX CODE)
#define LT_ServerName		    - Adapt's the Servername (Welcome to YOUR_SERVERNAME..)
#define RandomLoginColors           - Uncommented = Random TextDraw colors for each player

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
