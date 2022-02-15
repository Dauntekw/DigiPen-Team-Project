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
#include "GameObject.h"
#include "UI.h"
#include "Battle.h"

void gamestate_Victory_init(void);
void gamestate_Defeat_init(void);
void gamestate_EndingScreen_update(void);
void gamestate_EndingScreen_exit(void);
