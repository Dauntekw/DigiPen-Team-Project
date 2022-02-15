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
#include "UI.h"
#include "Entity.h"

void gamestate_Battle_init(void);
void gamestate_Battle_update(void);
void gamestate_Battle_exit(void);

void StartBattle(BattleData data);
void SetInitiative();
void RunBattleAction();