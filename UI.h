#pragma once
#include "CProcessing.h"
#include "SplashScreen.h"
#include "Battle.h"


enum MenuType
{
	MainMenu,
	ActionMenu,
	TargetMenu,

};

int end;
int currMenuLimits;
int currMenuLocation;
enum MenuType currentMenu;

void MoveUI(enum MenuType menu);
void MenuSelect(enum MenuType menu);