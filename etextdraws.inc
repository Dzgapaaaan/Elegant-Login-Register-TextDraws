#include <a_samp> //JustMe.77


#define LT_ServerName "YOUR_SERVERNAME"
#define LoginTextDrawColor 0xFF0000FF
#define TextDrawHoverColor 0x80FF80FF

new PlayerText:LoginTextDraw[MAX_PLAYERS][33];
static realtimer[MAX_PLAYERS];

/*

@ Titel: Elegant Login / Register TextDraws
@ Author: JustMe.77
@ Version: 1.0.0
@ Download: https://github.com/JustMe77/Elegant-Login-Register-TextDraws


Credits: 

@ Zamaroth - TextDraw Editor
@ ipsLeon - This textdraws are inspired a bit by his textdraws from the old project "Zombotec"


Available Functions:

CreateLoginTextDraws(playerid)  - Create all TextDraws
ShowLoginTextDraws(playerid)    - Show all TextDraws
HideLoginTextDraws(playerid)    - Hide all TextDraws
DestroyLoginTextDraws(playerid) - Destroys all TextDraws
PlayerIsRegistered(playerid)    - Adapt the Textdraw messages to already registered players
PlayerIsNotRegistered(playerid) - Adapt the Textdraw messages to players who are not registered
#define LoginTextDrawColor      - Change the TextDraw Color (PAWN HEX CODE)
#define TextDrawHoverColor      - Change the TextDraw Hover Color (PAWN HEX CODE)
#define LT_ServerName           - Adapt's the Servername (Welcome to YOUR_SERVERNAME..)

*/

public OnPlayerConnect(playerid)
{
  realtimer[playerid] = SetTimerEx("UpdateRealTime", 1000, true, "i", playerid);

  #if defined td_OnPlayerConnect
  return td_OnPlayerConnect(playerid);
  #else
  return 1;
  #endif
}

public OnPlayerDisconnect(playerid, reason)
{
  KillTimer(realtimer[playerid]);

  #if defined td_OnPlayerDisconnect
  return td_OnPlayerDisconnect(playerid,reason);
  #else
  return 1;
  #endif
}

public OnPlayerSpawn(playerid)
{
  KillTimer(realtimer[playerid]);

  #if defined td_OnPlayerSpawn
  return td_OnPlayerSpawn(playerid);
  #else
  return 1;
  #endif
}

forward UpdateRealTime(playerid);
public UpdateRealTime(playerid)
{
    new str[16];
    gettime(str[0], str[1]);
    format(str,sizeof(str),"%02d:%02d Time",str[0],str[1]);
    PlayerTextDrawSetString(playerid,LoginTextDraw[playerid][16], str);
    return 1;
}


stock PlayerIsRegistered(playerid)
{
  PlayerTextDrawSetString(playerid, LoginTextDraw[playerid][29], !"This name seem to be ~g~registered~w~.~n~You can now ~g~login~w~ to your Account.");
  PlayerTextDrawSetString(playerid, LoginTextDraw[playerid][11], !"      Login"); 
  PlayerTextDrawSetString(playerid, LoginTextDraw[playerid][15], !"          Welcome back!"); 
}

stock PlayerIsNotRegistered(playerid)
{
  new str[128]; //Adapt the size..
  PlayerTextDrawSetString(playerid, LoginTextDraw[playerid][29], !"This name is ~g~not~w~ registered.~n~You can now create an ~g~Account.");
  PlayerTextDrawSetString(playerid, LoginTextDraw[playerid][11], !"   Register");
  format(str, sizeof(str),"Welcome to %s", LT_ServerName);
  PlayerTextDrawSetString(playerid, LoginTextDraw[playerid][15], str);
}

stock ShowLoginTextDraws(playerid)
{
  for(new i; i < sizeof(LoginTextDraw[]); i++)
  {
    PlayerTextDrawShow(playerid, LoginTextDraw[playerid][i]);
  }

  SelectTextDraw(playerid, TextDrawHoverColor);
}

stock HideLoginTextDraws(playerid)
{
  for(new i; i < sizeof(LoginTextDraw[]); i++)
  {
    PlayerTextDrawHide(playerid, LoginTextDraw[playerid][i]);
  }

  CancelSelectTextDraw(playerid);
}

stock DestroyLoginTextDraws(playerid)
{
  for(new i; i < sizeof(LoginTextDraw[]); i++)
  {
    PlayerTextDrawDestroy(playerid, LoginTextDraw[playerid][i]);
  }
}


//Callback Hooks

#if defined _ALS_OnPlayerConnect
#undef OnPlayerConnect
#else
#define _ALS_OnPlayerConnect
#endif

#define OnPlayerConnect td_OnPlayerConnect
#if defined td_OnPlayerConnect
forward td_OnPlayerConnect();
#endif

#if defined _ALS_OnPlayerDisconnect
#undef OnPlayerDisconnect
#else
#define _ALS_OnPlayerDisconnect
#endif

#define OnPlayerDisconnect td_OnPlayerDisconnect
#if defined td_OnPlayerDisconnect
forward td_OnPlayerDisconnect();
#endif


#if defined _ALS_OnPlayerSpawn
#undef OnPlayerSpawn
#else
#define _ALS_OnPlayerSpawn
#endif

#define OnPlayerSpawn td_OnPlayerSpawn
#if defined td_OnPlayerSpawn
forward td_OnPlayerSpawn();
#endif

stock CreateLoginTextDraws(playerid)
{

  LoginTextDraw[playerid][0] = CreatePlayerTextDraw(playerid,169.000000, 121.000000, !"_");
  PlayerTextDrawBackgroundColor(playerid,LoginTextDraw[playerid][0], 255);
  PlayerTextDrawFont(playerid,LoginTextDraw[playerid][0], 1);
  PlayerTextDrawLetterSize(playerid,LoginTextDraw[playerid][0], 0.500000, 26.200000);
  PlayerTextDrawColor(playerid,LoginTextDraw[playerid][0], -1);
  PlayerTextDrawSetOutline(playerid,LoginTextDraw[playerid][0], 0);
  PlayerTextDrawSetProportional(playerid,LoginTextDraw[playerid][0], 1);
  PlayerTextDrawSetShadow(playerid,LoginTextDraw[playerid][0], 1);
  PlayerTextDrawUseBox(playerid,LoginTextDraw[playerid][0], 1);
  PlayerTextDrawBoxColor(playerid,LoginTextDraw[playerid][0], 255);
  PlayerTextDrawTextSize(playerid,LoginTextDraw[playerid][0], 470.000000, 0.000000);
  PlayerTextDrawSetSelectable(playerid,LoginTextDraw[playerid][0], 0);

  LoginTextDraw[playerid][1] = CreatePlayerTextDraw(playerid,170.000000, 123.000000, !"_");
  PlayerTextDrawBackgroundColor(playerid,LoginTextDraw[playerid][1], 255);
  PlayerTextDrawFont(playerid,LoginTextDraw[playerid][1], 1);
  PlayerTextDrawLetterSize(playerid,LoginTextDraw[playerid][1], 0.500000, 25.799999);
  PlayerTextDrawColor(playerid,LoginTextDraw[playerid][1], -1);
  PlayerTextDrawSetOutline(playerid,LoginTextDraw[playerid][1], 0);
  PlayerTextDrawSetProportional(playerid,LoginTextDraw[playerid][1], 1);
  PlayerTextDrawSetShadow(playerid,LoginTextDraw[playerid][1], 1);
  PlayerTextDrawUseBox(playerid,LoginTextDraw[playerid][1], 1);
  PlayerTextDrawBoxColor(playerid,LoginTextDraw[playerid][1], 286331391);
  PlayerTextDrawTextSize(playerid,LoginTextDraw[playerid][1], 469.000000, 0.000000);
  PlayerTextDrawSetSelectable(playerid,LoginTextDraw[playerid][1], 0);

  LoginTextDraw[playerid][2] = CreatePlayerTextDraw(playerid,170.000000, 122.000000, !"_______");
  PlayerTextDrawBackgroundColor(playerid,LoginTextDraw[playerid][2], 255);
  PlayerTextDrawFont(playerid,LoginTextDraw[playerid][2], 1);
  PlayerTextDrawLetterSize(playerid,LoginTextDraw[playerid][2], 0.500000, 1.200000);
  PlayerTextDrawColor(playerid,LoginTextDraw[playerid][2], -1);
  PlayerTextDrawSetOutline(playerid,LoginTextDraw[playerid][2], 0);
  PlayerTextDrawSetProportional(playerid,LoginTextDraw[playerid][2], 1);
  PlayerTextDrawSetShadow(playerid,LoginTextDraw[playerid][2], 1);
  PlayerTextDrawUseBox(playerid,LoginTextDraw[playerid][2], 1);
  PlayerTextDrawBoxColor(playerid,LoginTextDraw[playerid][2], LoginTextDrawColor);
  PlayerTextDrawTextSize(playerid,LoginTextDraw[playerid][2], 469.000000, 0.000000);
  PlayerTextDrawSetSelectable(playerid,LoginTextDraw[playerid][2], 0);

  LoginTextDraw[playerid][3] = CreatePlayerTextDraw(playerid,177.000000, 156.000000, !"______");
  PlayerTextDrawBackgroundColor(playerid,LoginTextDraw[playerid][3], 255);
  PlayerTextDrawFont(playerid,LoginTextDraw[playerid][3], 1);
  PlayerTextDrawLetterSize(playerid,LoginTextDraw[playerid][3], 0.500000, 3.700000);
  PlayerTextDrawColor(playerid,LoginTextDraw[playerid][3], -1);
  PlayerTextDrawSetOutline(playerid,LoginTextDraw[playerid][3], 0);
  PlayerTextDrawSetProportional(playerid,LoginTextDraw[playerid][3], 1);
  PlayerTextDrawSetShadow(playerid,LoginTextDraw[playerid][3], 1);
  PlayerTextDrawUseBox(playerid,LoginTextDraw[playerid][3], 1);
  PlayerTextDrawBoxColor(playerid,LoginTextDraw[playerid][3], 255);
  PlayerTextDrawTextSize(playerid,LoginTextDraw[playerid][3], 264.000000, 0.000000);
  PlayerTextDrawSetSelectable(playerid,LoginTextDraw[playerid][3], 0);

  LoginTextDraw[playerid][4] = CreatePlayerTextDraw(playerid,178.000000, 157.000000, !"_____________");
  PlayerTextDrawBackgroundColor(playerid,LoginTextDraw[playerid][4], 255);
  PlayerTextDrawFont(playerid,LoginTextDraw[playerid][4], 1);
  PlayerTextDrawLetterSize(playerid,LoginTextDraw[playerid][4], 0.500000, 3.500000);
  PlayerTextDrawColor(playerid,LoginTextDraw[playerid][4], -1);
  PlayerTextDrawSetOutline(playerid,LoginTextDraw[playerid][4], 0);
  PlayerTextDrawSetProportional(playerid,LoginTextDraw[playerid][4], 1);
  PlayerTextDrawSetShadow(playerid,LoginTextDraw[playerid][4], 1);
  PlayerTextDrawUseBox(playerid,LoginTextDraw[playerid][4], 1);
  PlayerTextDrawBoxColor(playerid,LoginTextDraw[playerid][4], LoginTextDrawColor);
  PlayerTextDrawTextSize(playerid,LoginTextDraw[playerid][4], 263.000000, 0.000000);
  PlayerTextDrawSetSelectable(playerid,LoginTextDraw[playerid][4], 0);

  LoginTextDraw[playerid][5] = CreatePlayerTextDraw(playerid,177.000000, 206.000000, !"______");
  PlayerTextDrawBackgroundColor(playerid,LoginTextDraw[playerid][5], 255);
  PlayerTextDrawFont(playerid,LoginTextDraw[playerid][5], 1);
  PlayerTextDrawLetterSize(playerid,LoginTextDraw[playerid][5], 0.500000, 3.700000);
  PlayerTextDrawColor(playerid,LoginTextDraw[playerid][5], -1);
  PlayerTextDrawSetOutline(playerid,LoginTextDraw[playerid][5], 0);
  PlayerTextDrawSetProportional(playerid,LoginTextDraw[playerid][5], 1);
  PlayerTextDrawSetShadow(playerid,LoginTextDraw[playerid][5], 1);
  PlayerTextDrawUseBox(playerid,LoginTextDraw[playerid][5], 1);
  PlayerTextDrawBoxColor(playerid,LoginTextDraw[playerid][5], 255);
  PlayerTextDrawTextSize(playerid,LoginTextDraw[playerid][5], 264.000000, 0.000000);
  PlayerTextDrawSetSelectable(playerid,LoginTextDraw[playerid][5], 0);

  LoginTextDraw[playerid][6] = CreatePlayerTextDraw(playerid,178.000000, 207.000000, !"_____________");
  PlayerTextDrawBackgroundColor(playerid,LoginTextDraw[playerid][6], 255);
  PlayerTextDrawFont(playerid,LoginTextDraw[playerid][6], 1);
  PlayerTextDrawLetterSize(playerid,LoginTextDraw[playerid][6], 0.500000, 3.500000);
  PlayerTextDrawColor(playerid,LoginTextDraw[playerid][6], -1);
  PlayerTextDrawSetOutline(playerid,LoginTextDraw[playerid][6], 0);
  PlayerTextDrawSetProportional(playerid,LoginTextDraw[playerid][6], 1);
  PlayerTextDrawSetShadow(playerid,LoginTextDraw[playerid][6], 1);
  PlayerTextDrawUseBox(playerid,LoginTextDraw[playerid][6], 1);
  PlayerTextDrawBoxColor(playerid,LoginTextDraw[playerid][6], LoginTextDrawColor);
  PlayerTextDrawTextSize(playerid,LoginTextDraw[playerid][6], 263.000000, 0.000000);
  PlayerTextDrawSetSelectable(playerid,LoginTextDraw[playerid][6], 0);

  LoginTextDraw[playerid][7] = CreatePlayerTextDraw(playerid,177.000000, 256.000000, !"______");
  PlayerTextDrawBackgroundColor(playerid,LoginTextDraw[playerid][7], 255);
  PlayerTextDrawFont(playerid,LoginTextDraw[playerid][7], 1);
  PlayerTextDrawLetterSize(playerid,LoginTextDraw[playerid][7], 0.500000, 3.700000);
  PlayerTextDrawColor(playerid,LoginTextDraw[playerid][7], -1);
  PlayerTextDrawSetOutline(playerid,LoginTextDraw[playerid][7], 0);
  PlayerTextDrawSetProportional(playerid,LoginTextDraw[playerid][7], 1);
  PlayerTextDrawSetShadow(playerid,LoginTextDraw[playerid][7], 1);
  PlayerTextDrawUseBox(playerid,LoginTextDraw[playerid][7], 1);
  PlayerTextDrawBoxColor(playerid,LoginTextDraw[playerid][7], 255);
  PlayerTextDrawTextSize(playerid,LoginTextDraw[playerid][7], 264.000000, 0.000000);
  PlayerTextDrawSetSelectable(playerid,LoginTextDraw[playerid][7], 0);

  LoginTextDraw[playerid][8] = CreatePlayerTextDraw(playerid,178.000000, 257.000000, !"_____________");
  PlayerTextDrawBackgroundColor(playerid,LoginTextDraw[playerid][8], 255);
  PlayerTextDrawFont(playerid,LoginTextDraw[playerid][8], 1);
  PlayerTextDrawLetterSize(playerid,LoginTextDraw[playerid][8], 0.500000, 3.500000);
  PlayerTextDrawColor(playerid,LoginTextDraw[playerid][8], -1);
  PlayerTextDrawSetOutline(playerid,LoginTextDraw[playerid][8], 0);
  PlayerTextDrawSetProportional(playerid,LoginTextDraw[playerid][8], 1);
  PlayerTextDrawSetShadow(playerid,LoginTextDraw[playerid][8], 1);
  PlayerTextDrawUseBox(playerid,LoginTextDraw[playerid][8], 1);
  PlayerTextDrawBoxColor(playerid,LoginTextDraw[playerid][8], LoginTextDrawColor);
  PlayerTextDrawTextSize(playerid,LoginTextDraw[playerid][8], 263.000000, 0.000000);
  PlayerTextDrawSetSelectable(playerid,LoginTextDraw[playerid][8], 0);

  LoginTextDraw[playerid][9] = CreatePlayerTextDraw(playerid,177.000000, 306.000000, !"______");
  PlayerTextDrawBackgroundColor(playerid,LoginTextDraw[playerid][9], 255);
  PlayerTextDrawFont(playerid,LoginTextDraw[playerid][9], 1);
  PlayerTextDrawLetterSize(playerid,LoginTextDraw[playerid][9], 0.500000, 3.700000);
  PlayerTextDrawColor(playerid,LoginTextDraw[playerid][9], -1);
  PlayerTextDrawSetOutline(playerid,LoginTextDraw[playerid][9], 0);
  PlayerTextDrawSetProportional(playerid,LoginTextDraw[playerid][9], 1);
  PlayerTextDrawSetShadow(playerid,LoginTextDraw[playerid][9], 1);
  PlayerTextDrawUseBox(playerid,LoginTextDraw[playerid][9], 1);
  PlayerTextDrawBoxColor(playerid,LoginTextDraw[playerid][9], 255);
  PlayerTextDrawTextSize(playerid,LoginTextDraw[playerid][9], 264.000000, 0.000000);
  PlayerTextDrawSetSelectable(playerid,LoginTextDraw[playerid][9], 0);

  LoginTextDraw[playerid][10] = CreatePlayerTextDraw(playerid,178.000000, 307.000000, !"_____________");
  PlayerTextDrawBackgroundColor(playerid,LoginTextDraw[playerid][10], 255);
  PlayerTextDrawFont(playerid,LoginTextDraw[playerid][10], 1);
  PlayerTextDrawLetterSize(playerid,LoginTextDraw[playerid][10], 0.500000, 3.500000);
  PlayerTextDrawColor(playerid,LoginTextDraw[playerid][10], -1);
  PlayerTextDrawSetOutline(playerid,LoginTextDraw[playerid][10], 0);
  PlayerTextDrawSetProportional(playerid,LoginTextDraw[playerid][10], 1);
  PlayerTextDrawSetShadow(playerid,LoginTextDraw[playerid][10], 1);
  PlayerTextDrawUseBox(playerid,LoginTextDraw[playerid][10], 1);
  PlayerTextDrawBoxColor(playerid,LoginTextDraw[playerid][10], LoginTextDrawColor);
  PlayerTextDrawTextSize(playerid,LoginTextDraw[playerid][10], 263.000000, 0.000000);
  PlayerTextDrawSetSelectable(playerid,LoginTextDraw[playerid][10], 0);

  LoginTextDraw[playerid][11] = CreatePlayerTextDraw(playerid,192.000000, 166.000000, !"      Login");
  PlayerTextDrawBackgroundColor(playerid,LoginTextDraw[playerid][11], 255);
  PlayerTextDrawFont(playerid,LoginTextDraw[playerid][11], 2);
  PlayerTextDrawLetterSize(playerid,LoginTextDraw[playerid][11], 0.189999, 1.299999);
  PlayerTextDrawTextSize(playerid, LoginTextDraw[playerid][11], 240.0, 15.0);
  PlayerTextDrawColor(playerid,LoginTextDraw[playerid][11], -1);
  PlayerTextDrawSetOutline(playerid,LoginTextDraw[playerid][11], 1);
  PlayerTextDrawSetProportional(playerid,LoginTextDraw[playerid][11], 1);
  PlayerTextDrawSetSelectable(playerid,LoginTextDraw[playerid][11], 1);

  LoginTextDraw[playerid][12] = CreatePlayerTextDraw(playerid,191.000000, 217.000000, !"   About us");
  PlayerTextDrawBackgroundColor(playerid,LoginTextDraw[playerid][12], 255);
  PlayerTextDrawFont(playerid,LoginTextDraw[playerid][12], 2);
  PlayerTextDrawLetterSize(playerid,LoginTextDraw[playerid][12], 0.189999, 1.299999);
  PlayerTextDrawTextSize(playerid, LoginTextDraw[playerid][12], 260.0, 20.0);
  PlayerTextDrawColor(playerid,LoginTextDraw[playerid][12], -1);
  PlayerTextDrawSetOutline(playerid,LoginTextDraw[playerid][12], 1);
  PlayerTextDrawSetProportional(playerid,LoginTextDraw[playerid][12], 1);
  PlayerTextDrawSetSelectable(playerid,LoginTextDraw[playerid][12], 1);

  LoginTextDraw[playerid][13] = CreatePlayerTextDraw(playerid,202.000000, 267.000000, !" Rules");
  PlayerTextDrawBackgroundColor(playerid,LoginTextDraw[playerid][13], 255);
  PlayerTextDrawFont(playerid,LoginTextDraw[playerid][13], 2);
  PlayerTextDrawLetterSize(playerid,LoginTextDraw[playerid][13], 0.189999, 1.299999);
  PlayerTextDrawTextSize(playerid, LoginTextDraw[playerid][13], 240.0, 15.0);
  PlayerTextDrawColor(playerid,LoginTextDraw[playerid][13], -1);
  PlayerTextDrawSetOutline(playerid,LoginTextDraw[playerid][13], 1);
  PlayerTextDrawSetProportional(playerid,LoginTextDraw[playerid][13], 1);
  PlayerTextDrawSetSelectable(playerid,LoginTextDraw[playerid][13], 1);

  LoginTextDraw[playerid][14] = CreatePlayerTextDraw(playerid,202.000000, 316.000000, !"Credits");
  PlayerTextDrawBackgroundColor(playerid,LoginTextDraw[playerid][14], 255);
  PlayerTextDrawFont(playerid,LoginTextDraw[playerid][14], 2);
  PlayerTextDrawLetterSize(playerid,LoginTextDraw[playerid][14], 0.189999, 1.299999);
  PlayerTextDrawTextSize(playerid, LoginTextDraw[playerid][14], 240.0, 15.0);
  PlayerTextDrawColor(playerid,LoginTextDraw[playerid][14], -1);
  PlayerTextDrawSetOutline(playerid,LoginTextDraw[playerid][14], 1);
  PlayerTextDrawSetProportional(playerid,LoginTextDraw[playerid][14], 1);
  PlayerTextDrawSetSelectable(playerid,LoginTextDraw[playerid][14], 1);

  new str[128];
  LoginTextDraw[playerid][15] = CreatePlayerTextDraw(playerid,269.000000, 123.000000, !"Welcome to <YOUR_SERVERNAME>");
  PlayerTextDrawBackgroundColor(playerid,LoginTextDraw[playerid][15], 255);
  PlayerTextDrawFont(playerid,LoginTextDraw[playerid][15], 2);
  PlayerTextDrawLetterSize(playerid,LoginTextDraw[playerid][15], 0.140000, 0.799998);
  PlayerTextDrawColor(playerid,LoginTextDraw[playerid][15], -1);
  PlayerTextDrawSetOutline(playerid,LoginTextDraw[playerid][15], 1);
  PlayerTextDrawSetProportional(playerid,LoginTextDraw[playerid][15], 1);
  PlayerTextDrawSetSelectable(playerid,LoginTextDraw[playerid][15], 0);
  format(str, sizeof(str),"Welcome to %s", LT_ServerName);
  PlayerTextDrawSetString(playerid, LoginTextDraw[playerid][15], str);

  LoginTextDraw[playerid][16] = CreatePlayerTextDraw(playerid,427.000000, 123.000000, !"00:00 Time");
  PlayerTextDrawBackgroundColor(playerid,LoginTextDraw[playerid][16], 255);
  PlayerTextDrawFont(playerid,LoginTextDraw[playerid][16], 2);
  PlayerTextDrawLetterSize(playerid,LoginTextDraw[playerid][16], 0.140000, 0.799998);
  PlayerTextDrawColor(playerid,LoginTextDraw[playerid][16], -1);
  PlayerTextDrawSetOutline(playerid,LoginTextDraw[playerid][16], 1);
  PlayerTextDrawSetProportional(playerid,LoginTextDraw[playerid][16], 1);
  PlayerTextDrawSetSelectable(playerid,LoginTextDraw[playerid][16], 0);

  LoginTextDraw[playerid][17] = CreatePlayerTextDraw(playerid,340.000000, 155.000000, !"___");
  PlayerTextDrawBackgroundColor(playerid,LoginTextDraw[playerid][17], 255);
  PlayerTextDrawFont(playerid,LoginTextDraw[playerid][17], 1);
  PlayerTextDrawLetterSize(playerid,LoginTextDraw[playerid][17], 0.500000, 3.799999);
  PlayerTextDrawColor(playerid,LoginTextDraw[playerid][17], -1);
  PlayerTextDrawSetOutline(playerid,LoginTextDraw[playerid][17], 0);
  PlayerTextDrawSetProportional(playerid,LoginTextDraw[playerid][17], 1);
  PlayerTextDrawSetShadow(playerid,LoginTextDraw[playerid][17], 1);
  PlayerTextDrawUseBox(playerid,LoginTextDraw[playerid][17], 1);
  PlayerTextDrawBoxColor(playerid,LoginTextDraw[playerid][17], 255);
  PlayerTextDrawTextSize(playerid,LoginTextDraw[playerid][17], 460.000000, 0.000000);
  PlayerTextDrawSetSelectable(playerid,LoginTextDraw[playerid][17], 0);

  LoginTextDraw[playerid][18] = CreatePlayerTextDraw(playerid,341.000000, 156.000000, !"____");
  PlayerTextDrawBackgroundColor(playerid,LoginTextDraw[playerid][18], 255);
  PlayerTextDrawFont(playerid,LoginTextDraw[playerid][18], 1);
  PlayerTextDrawLetterSize(playerid,LoginTextDraw[playerid][18], 0.500000, 3.599999);
  PlayerTextDrawColor(playerid,LoginTextDraw[playerid][18], -1);
  PlayerTextDrawSetOutline(playerid,LoginTextDraw[playerid][18], 0);
  PlayerTextDrawSetProportional(playerid,LoginTextDraw[playerid][18], 1);
  PlayerTextDrawSetShadow(playerid,LoginTextDraw[playerid][18], 1);
  PlayerTextDrawUseBox(playerid,LoginTextDraw[playerid][18], 1);
  PlayerTextDrawBoxColor(playerid,LoginTextDraw[playerid][18], 505290495);
  PlayerTextDrawTextSize(playerid,LoginTextDraw[playerid][18], 459.000000, 0.000000);
  PlayerTextDrawSetSelectable(playerid,LoginTextDraw[playerid][18], 0);

  LoginTextDraw[playerid][19] = CreatePlayerTextDraw(playerid,340.000000, 206.000000, !"___");
  PlayerTextDrawBackgroundColor(playerid,LoginTextDraw[playerid][19], 255);
  PlayerTextDrawFont(playerid,LoginTextDraw[playerid][19], 1);
  PlayerTextDrawLetterSize(playerid,LoginTextDraw[playerid][19], 0.500000, 3.799999);
  PlayerTextDrawColor(playerid,LoginTextDraw[playerid][19], -1);
  PlayerTextDrawSetOutline(playerid,LoginTextDraw[playerid][19], 0);
  PlayerTextDrawSetProportional(playerid,LoginTextDraw[playerid][19], 1);
  PlayerTextDrawSetShadow(playerid,LoginTextDraw[playerid][19], 1);
  PlayerTextDrawUseBox(playerid,LoginTextDraw[playerid][19], 1);
  PlayerTextDrawBoxColor(playerid,LoginTextDraw[playerid][19], 255);
  PlayerTextDrawTextSize(playerid,LoginTextDraw[playerid][19], 460.000000, 0.000000);
  PlayerTextDrawSetSelectable(playerid,LoginTextDraw[playerid][19], 0);

  LoginTextDraw[playerid][20] = CreatePlayerTextDraw(playerid,341.000000, 207.000000, !"____");
  PlayerTextDrawBackgroundColor(playerid,LoginTextDraw[playerid][20], 255);
  PlayerTextDrawFont(playerid,LoginTextDraw[playerid][20], 1);
  PlayerTextDrawLetterSize(playerid,LoginTextDraw[playerid][20], 0.500000, 3.599999);
  PlayerTextDrawColor(playerid,LoginTextDraw[playerid][20], -1);
  PlayerTextDrawSetOutline(playerid,LoginTextDraw[playerid][20], 0);
  PlayerTextDrawSetProportional(playerid,LoginTextDraw[playerid][20], 1);
  PlayerTextDrawSetShadow(playerid,LoginTextDraw[playerid][20], 1);
  PlayerTextDrawUseBox(playerid,LoginTextDraw[playerid][20], 1);
  PlayerTextDrawBoxColor(playerid,LoginTextDraw[playerid][20], 505290495);
  PlayerTextDrawTextSize(playerid,LoginTextDraw[playerid][20], 459.000000, 0.000000);
  PlayerTextDrawSetSelectable(playerid,LoginTextDraw[playerid][20], 0);

  LoginTextDraw[playerid][21] = CreatePlayerTextDraw(playerid,318.000000, 203.000000, !"~<~");
  PlayerTextDrawBackgroundColor(playerid,LoginTextDraw[playerid][21], 255);
  PlayerTextDrawFont(playerid,LoginTextDraw[playerid][21], 1);
  PlayerTextDrawLetterSize(playerid,LoginTextDraw[playerid][21], 0.539999, 3.900000);
  PlayerTextDrawColor(playerid,LoginTextDraw[playerid][21], -16776961);
  PlayerTextDrawSetOutline(playerid,LoginTextDraw[playerid][21], 1);
  PlayerTextDrawSetProportional(playerid,LoginTextDraw[playerid][21], 1);
  PlayerTextDrawSetSelectable(playerid,LoginTextDraw[playerid][21], 0);

  LoginTextDraw[playerid][22] = CreatePlayerTextDraw(playerid,340.000000, 259.000000, !"___");
  PlayerTextDrawBackgroundColor(playerid,LoginTextDraw[playerid][22], 255);
  PlayerTextDrawFont(playerid,LoginTextDraw[playerid][22], 1);
  PlayerTextDrawLetterSize(playerid,LoginTextDraw[playerid][22], 0.500000, 3.799999);
  PlayerTextDrawColor(playerid,LoginTextDraw[playerid][22], -1);
  PlayerTextDrawSetOutline(playerid,LoginTextDraw[playerid][22], 0);
  PlayerTextDrawSetProportional(playerid,LoginTextDraw[playerid][22], 1);
  PlayerTextDrawSetShadow(playerid,LoginTextDraw[playerid][22], 1);
  PlayerTextDrawUseBox(playerid,LoginTextDraw[playerid][22], 1);
  PlayerTextDrawBoxColor(playerid,LoginTextDraw[playerid][22], 255);
  PlayerTextDrawTextSize(playerid,LoginTextDraw[playerid][22], 460.000000, 0.000000);
  PlayerTextDrawSetSelectable(playerid,LoginTextDraw[playerid][22], 0);

  LoginTextDraw[playerid][23] = CreatePlayerTextDraw(playerid,341.000000, 260.000000, !"____");
  PlayerTextDrawBackgroundColor(playerid,LoginTextDraw[playerid][23], 255);
  PlayerTextDrawFont(playerid,LoginTextDraw[playerid][23], 1);
  PlayerTextDrawLetterSize(playerid,LoginTextDraw[playerid][23], 0.500000, 3.599999);
  PlayerTextDrawColor(playerid,LoginTextDraw[playerid][23], -1);
  PlayerTextDrawSetOutline(playerid,LoginTextDraw[playerid][23], 0);
  PlayerTextDrawSetProportional(playerid,LoginTextDraw[playerid][23], 1);
  PlayerTextDrawSetShadow(playerid,LoginTextDraw[playerid][23], 1);
  PlayerTextDrawUseBox(playerid,LoginTextDraw[playerid][23], 1);
  PlayerTextDrawBoxColor(playerid,LoginTextDraw[playerid][23], 505290495);
  PlayerTextDrawTextSize(playerid,LoginTextDraw[playerid][23], 459.000000, 0.000000);
  PlayerTextDrawSetSelectable(playerid,LoginTextDraw[playerid][23], 0);

  LoginTextDraw[playerid][24] = CreatePlayerTextDraw(playerid,340.000000, 309.000000, !"___");
  PlayerTextDrawBackgroundColor(playerid,LoginTextDraw[playerid][24], 255);
  PlayerTextDrawFont(playerid,LoginTextDraw[playerid][24], 1);
  PlayerTextDrawLetterSize(playerid,LoginTextDraw[playerid][24], 0.500000, 3.799999);
  PlayerTextDrawColor(playerid,LoginTextDraw[playerid][24], -1);
  PlayerTextDrawSetOutline(playerid,LoginTextDraw[playerid][24], 0);
  PlayerTextDrawSetProportional(playerid,LoginTextDraw[playerid][24], 1);
  PlayerTextDrawSetShadow(playerid,LoginTextDraw[playerid][24], 1);
  PlayerTextDrawUseBox(playerid,LoginTextDraw[playerid][24], 1);
  PlayerTextDrawBoxColor(playerid,LoginTextDraw[playerid][24], 255);
  PlayerTextDrawTextSize(playerid,LoginTextDraw[playerid][24], 460.000000, 0.000000);
  PlayerTextDrawSetSelectable(playerid,LoginTextDraw[playerid][24], 0);

  LoginTextDraw[playerid][25] = CreatePlayerTextDraw(playerid,341.000000, 310.000000, !"____");
  PlayerTextDrawBackgroundColor(playerid,LoginTextDraw[playerid][25], 255);
  PlayerTextDrawFont(playerid,LoginTextDraw[playerid][25], 1);
  PlayerTextDrawLetterSize(playerid,LoginTextDraw[playerid][25], 0.500000, 3.599999);
  PlayerTextDrawColor(playerid,LoginTextDraw[playerid][25], -1);
  PlayerTextDrawSetOutline(playerid,LoginTextDraw[playerid][25], 0);
  PlayerTextDrawSetProportional(playerid,LoginTextDraw[playerid][25], 1);
  PlayerTextDrawSetShadow(playerid,LoginTextDraw[playerid][25], 1);
  PlayerTextDrawUseBox(playerid,LoginTextDraw[playerid][25], 1);
  PlayerTextDrawBoxColor(playerid,LoginTextDraw[playerid][25], 505290495);
  PlayerTextDrawTextSize(playerid,LoginTextDraw[playerid][25], 459.000000, 0.000000);
  PlayerTextDrawSetSelectable(playerid,LoginTextDraw[playerid][25], 0);

  LoginTextDraw[playerid][26] = CreatePlayerTextDraw(playerid,318.000000, 152.000000, !"~<~");
  PlayerTextDrawBackgroundColor(playerid,LoginTextDraw[playerid][26], 255);
  PlayerTextDrawFont(playerid,LoginTextDraw[playerid][26], 1);
  PlayerTextDrawLetterSize(playerid,LoginTextDraw[playerid][26], 0.539999, 3.900000);
  PlayerTextDrawColor(playerid,LoginTextDraw[playerid][26], -16776961);
  PlayerTextDrawSetOutline(playerid,LoginTextDraw[playerid][26], 1);
  PlayerTextDrawSetProportional(playerid,LoginTextDraw[playerid][26], 1);
  PlayerTextDrawSetSelectable(playerid,LoginTextDraw[playerid][26], 0);

  LoginTextDraw[playerid][27] = CreatePlayerTextDraw(playerid,318.000000, 256.000000, !"~<~");
  PlayerTextDrawBackgroundColor(playerid,LoginTextDraw[playerid][27], 255);
  PlayerTextDrawFont(playerid,LoginTextDraw[playerid][27], 1);
  PlayerTextDrawLetterSize(playerid,LoginTextDraw[playerid][27], 0.539999, 3.900000);
  PlayerTextDrawColor(playerid,LoginTextDraw[playerid][27], -16776961);
  PlayerTextDrawSetOutline(playerid,LoginTextDraw[playerid][27], 1);
  PlayerTextDrawSetProportional(playerid,LoginTextDraw[playerid][27], 1);
  PlayerTextDrawSetSelectable(playerid,LoginTextDraw[playerid][27], 0);

  LoginTextDraw[playerid][28] = CreatePlayerTextDraw(playerid,318.000000, 306.000000, !"~<~");
  PlayerTextDrawBackgroundColor(playerid,LoginTextDraw[playerid][28], 255);
  PlayerTextDrawFont(playerid,LoginTextDraw[playerid][28], 1);
  PlayerTextDrawLetterSize(playerid,LoginTextDraw[playerid][28], 0.539999, 3.900000);
  PlayerTextDrawColor(playerid,LoginTextDraw[playerid][28], -16776961);
  PlayerTextDrawSetOutline(playerid,LoginTextDraw[playerid][28], 1);
  PlayerTextDrawSetProportional(playerid,LoginTextDraw[playerid][28], 1);
  PlayerTextDrawSetSelectable(playerid,LoginTextDraw[playerid][28], 0);

  LoginTextDraw[playerid][29] = CreatePlayerTextDraw(playerid,346.000000, 162.000000, !"This name seem to be ~g~registered~w~.~n~You can now ~g~login~w~ to your Account.");
  PlayerTextDrawBackgroundColor(playerid,LoginTextDraw[playerid][29], 255);
  PlayerTextDrawFont(playerid,LoginTextDraw[playerid][29], 2);
  PlayerTextDrawLetterSize(playerid,LoginTextDraw[playerid][29], 0.129997, 0.899999);
  PlayerTextDrawColor(playerid,LoginTextDraw[playerid][29], -1);
  PlayerTextDrawSetOutline(playerid,LoginTextDraw[playerid][29], 1);
  PlayerTextDrawSetProportional(playerid,LoginTextDraw[playerid][29], 1);
  PlayerTextDrawSetSelectable(playerid,LoginTextDraw[playerid][29], 0);

  LoginTextDraw[playerid][30] = CreatePlayerTextDraw(playerid,348.000000, 213.000000, !"Click here for useful ~g~Information~w~.~n~How the server works etc...");
  PlayerTextDrawBackgroundColor(playerid,LoginTextDraw[playerid][30], 255);
  PlayerTextDrawFont(playerid,LoginTextDraw[playerid][30], 2);
  PlayerTextDrawLetterSize(playerid,LoginTextDraw[playerid][30], 0.129997, 0.899999);
  PlayerTextDrawColor(playerid,LoginTextDraw[playerid][30], -1);
  PlayerTextDrawSetOutline(playerid,LoginTextDraw[playerid][30], 1);
  PlayerTextDrawSetProportional(playerid,LoginTextDraw[playerid][30], 1);
  PlayerTextDrawSetSelectable(playerid,LoginTextDraw[playerid][30], 0);

  LoginTextDraw[playerid][31] = CreatePlayerTextDraw(playerid,348.000000, 266.000000, !"~w~Please read carefully all ~g~Rules.~w~~n~Behave and respect other players.");
  PlayerTextDrawBackgroundColor(playerid,LoginTextDraw[playerid][31], 255);
  PlayerTextDrawFont(playerid,LoginTextDraw[playerid][31], 2);
  PlayerTextDrawLetterSize(playerid,LoginTextDraw[playerid][31], 0.129997, 0.899999);
  PlayerTextDrawColor(playerid,LoginTextDraw[playerid][31], -1);
  PlayerTextDrawSetOutline(playerid,LoginTextDraw[playerid][31], 1);
  PlayerTextDrawSetProportional(playerid,LoginTextDraw[playerid][31], 1);
  PlayerTextDrawSetSelectable(playerid,LoginTextDraw[playerid][31], 0);

  LoginTextDraw[playerid][32] = CreatePlayerTextDraw(playerid,348.000000, 317.000000, !"Take a look who ~g~contributed~w~ to us.~n~You won't regret it ;)");
  PlayerTextDrawBackgroundColor(playerid,LoginTextDraw[playerid][32], 255);
  PlayerTextDrawFont(playerid,LoginTextDraw[playerid][32], 2);
  PlayerTextDrawLetterSize(playerid,LoginTextDraw[playerid][32], 0.129997, 0.899999);
  PlayerTextDrawColor(playerid,LoginTextDraw[playerid][32], -1);
  PlayerTextDrawSetOutline(playerid,LoginTextDraw[playerid][32], 1);
  PlayerTextDrawSetProportional(playerid,LoginTextDraw[playerid][32], 1);
  PlayerTextDrawSetSelectable(playerid,LoginTextDraw[playerid][32], 0);

}
