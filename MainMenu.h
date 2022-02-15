//---------------------------------------------------------
// file:	gamestate_template.h
// author:	[NAME]
// email:	[DIGIPEN EMAIL ADDRESS]
//
// brief:	header file for template gamestate
//
// documentation link:
// https://github.com/DigiPen-Faculty/CProcessing/wiki
//
// Copyright © 2020 DigiPen, All rights reserved.
//---------------------------------------------------------

#pragma once
#include "cprocessing.h"
#include "gamestate_template.h"
#include "GameObject.h"
#include "UI.h"
#include "SplashScreen.h"
#include "malloc.h"
#include "Battle.h"

void gamestate_MainMenu_init(void);
void gamestate_MainMenu_update(void);
void gamestate_MainMenu_exit(void);
