//---------------------------------------------------------
// file:	gamestate_template.c
// author:	[NAME]
// email:	[DIGIPEN EMAIL ADDRESS]
//
// brief:	template file for holding gamestate functions
//
// documentation link:
// https://github.com/DigiPen-Faculty/CProcessing/wiki
//
// Copyright © 2020 DigiPen, All rights reserved.
//---------------------------------------------------------

#include "Battle.h"
#include "cprocessing.h"
#include "SplashScreen.h"
#include "GameObject.h"
#include "malloc.h"
#include "UI.h"
#include "stdio.h"
#include "EndingScreen.h"

int pHealth = 20;
int pMaxHealth = 20;
int eHealth = 15;

BattleData currentBattle;

void StartBattle(BattleData data) 
{
	currentBattle = data;
}





RenderObject bRender0;
RenderObject bRender1;
RenderObject bRender2;
RenderObject bRender3;
GameObject battle1;

RenderObject eRender0;
RenderObject eRender1;
RenderObject eRender2;
GameObject enemy;

RenderObject tRender0;
RenderObject tRender1;
RenderObject tRender2;
GameObject tracker;


RenderObject pRender0;
RenderObject pRender1;
RenderObject pRender2;
GameObject player;

// use CP_Engine_SetNextGameState to specify this function as the initialization function
// this function will be called once at the beginning of the program
void gamestate_Battle_init(void)
{
	pHealth = pMaxHealth;
	eHealth = 15;

	tracker.render0 = &tRender0;
	tracker.render1 = &tRender1;
	tracker.render2 = &tRender2;
	RenderObjectInit(&tRender0, "");
	RenderObjectInit(&tRender1, "");
	RenderObjectInit(&tRender2, "");

	tRender0.isShape = 1;
	tRender1.isShape = 1;
	tRender0.imgScale.x = 20;
	tRender0.imgScale.y = 20;
	tRender1.imgScale.x = 20;
	tRender1.imgScale.y = 20;
	tracker.position.x = 1150;
	tracker.position.y = 620;

	RenderObjectInit(&bRender0, "");
	RenderObjectInit(&bRender1, "");
	RenderObjectInit(&bRender2, "");
	RenderObjectInit(&bRender3, "");
	battle1.render0 = &bRender0;
	battle1.render1 = &bRender1;
	battle1.render2 = &bRender2;
	battle1.render3 = &bRender3;
	battle1.position.x = 1200;
	battle1.position.y = 600;
	bRender0.text = "Attack";
	bRender1.text = "Heal";
	bRender2.text = "Spell - BROKEN";
	bRender3.text = "Quit";
	bRender0.offset.y = 25;
	bRender1.offset.y = 50;
	bRender2.offset.y = 75;
	bRender3.offset.y = 100;

	enemy.render0 = &eRender0;
	enemy.render1 = &eRender1;
	enemy.render2 = &eRender2;
	RenderObjectInit(&eRender0, "");
	eRender1.text = "Enemy";
	eRender2.text = calloc(20, sizeof(char));
	if (eRender2.text)
		sprintf_s(eRender2.text, 20, "Health: %i", eHealth);
	enemy.position.x = 800;
	enemy.position.y = 300;
	eRender2.offset.y = 20;
	eRender0.isShape = 1;
	eRender0.imgScale.x = 100;
	eRender0.imgScale.y = 100;
	eRender0.offset.x = 35;
	eRender0.offset.y = -125;

	player.render0 = &pRender0;
	player.render1 = &pRender1;
	player.render2 = &pRender2;
	RenderObjectInit(&pRender0, "");
	pRender1.text = "Player";

	pRender2.text = calloc(20, sizeof(char));
	if (pRender2.text)
		sprintf_s(pRender2.text, 20, "Health: %i", pHealth);

	player.position.x = 500;
	player.position.y = 500;
	pRender2.offset.y = 20;

	pRender0.isShape = 1;
	pRender0.imgScale.x = 100;
	pRender0.imgScale.y = 100;

	pRender0.offset.x = 35;
	pRender0.offset.y = -125;
	// initialize variables and CProcessing settings for this gamestate
}

// use CP_Engine_SetNextGameState to specify this function as the update function
// this function will be called repeatedly every frame
void gamestate_Battle_update(void)
{
	CP_Graphics_ClearBackground(CP_Color_Create(255, 255, 255, 255));

	if (eHealth <= 0 )
	{
		CP_Engine_SetNextGameStateForced(gamestate_Victory_init, gamestate_EndingScreen_update, gamestate_EndingScreen_exit);

	}
	if (pHealth <= 0)
	{
		CP_Engine_SetNextGameStateForced(gamestate_Defeat_init, gamestate_EndingScreen_update, gamestate_EndingScreen_exit);

	}

	// check input, update simulation, render etc.
	if (CP_Input_KeyTriggered(KEY_ENTER))
	{
		MenuSelect(currentMenu);
	}
	MoveUI(currentMenu);
	DrawGameObject(&battle1);
	CP_Settings_Fill(CP_Color_Create(0, 255, 0, 255));
	DrawGameObject(&player);
	CP_Settings_Fill(CP_Color_Create(255, 0, 0, 255));
	DrawGameObject(&enemy);
	CP_Settings_Fill(CP_Color_Create(255, 255, 255, 255));
	tRender0.rotation += 3;
	tRender1.rotation -= 1;
	tRender0.offset.y = +25.0f * (3 - currMenuLocation);
	tRender1.offset.y = +25.0f * (3 - currMenuLocation);
	CP_Settings_RectMode(CP_POSITION_CENTER);
	DrawGameObject(&tracker);


	pRender2.text = calloc(20, sizeof(char));
	if (pRender2.text)
		sprintf_s(pRender2.text, 20, "Health: %i", pHealth);

	eRender2.text = calloc(20, sizeof(char));
	if (eRender2.text)
		sprintf_s(eRender2.text, 20, "Health: %i", eHealth);


	if (CP_Input_KeyTriggered(KEY_SPACE))
	{
		CP_Engine_SetNextGameState(gamestate_SplashScreen_init, gamestate_SplashScreen_update, gamestate_SplashScreen_exit);
	}
}

// use CP_Engine_SetNextGameState to specify this function as the exit function
// this function will be called once just before leaving the current gamestate
void gamestate_Battle_exit(void)
{
	// shut down the gamestate and cleanup any dynamic memory
}