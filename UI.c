#include "UI.h"

void MoveUI(enum MenuType menu)
{
	switch (menu)
	{
	case MainMenu:
	{
		currMenuLimits = 1;
		if (currMenuLocation < currMenuLimits && (CP_Input_KeyTriggered(KEY_UP) ||
			CP_Input_KeyTriggered(KEY_W)))
		{
			currMenuLocation +=1;
		}
		if (currMenuLocation > 0 && (CP_Input_KeyTriggered(KEY_DOWN) ||
			CP_Input_KeyTriggered(KEY_S)))
		{
			currMenuLocation -=1;
		}
		break;
	}
	case ActionMenu:
	{
		currMenuLimits = 3;
		if (currMenuLocation < currMenuLimits && (CP_Input_KeyTriggered(KEY_UP) ||
			CP_Input_KeyTriggered(KEY_W)))
		{
			currMenuLocation += 1;
		}
		if (currMenuLocation > 0 && (CP_Input_KeyTriggered(KEY_DOWN) ||
			CP_Input_KeyTriggered(KEY_S)))
		{
			currMenuLocation -=1;
		}

		break;
	}
	}
}

void MenuSelect(enum MenuType menu)
{
	switch (menu)
	{
	case MainMenu:
	{
		if (currMenuLocation == 0)
		{
			if(end ==1)
				CP_Engine_SetNextGameState(gamestate_MainMenu_init, gamestate_MainMenu_update, gamestate_MainMenu_exit);

			else
				CP_Engine_Terminate();

		}
		if (currMenuLocation == 1) 
		{
			CP_Engine_SetNextGameState(gamestate_Battle_init, gamestate_Battle_update, gamestate_Battle_exit);
			currMenuLocation = 3;
			currentMenu = ActionMenu;
		}

		break;
	}
	case ActionMenu:
	{
		//if (currMenuLocation == 3)
		//	PlayerAction(Attack, 0);
		//if (currMenuLocation == 2)
		//	PlayerAction(Heal, 0);

		if (currMenuLocation == 0)
			CP_Engine_SetNextGameState(gamestate_SplashScreen_init, gamestate_SplashScreen_update, gamestate_SplashScreen_exit);

		break;
	}
	}
}
