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

#include "MainMenu.h"
#include "Timer.h"

Timer timertest;

RenderObject sRender0;
RenderObject sRender1;
RenderObject sRender2;
ColliderObject c;
GameObject startText;

RenderObject mRender0;
RenderObject mRender1;
RenderObject mRender2;
RenderObject mRender3;
GameObject menu1;

void gamestate_MainMenu_init(void)
{
	end = 0;
	// initialize variables and CProcessing settings for this gamestate
	CP_Settings_RectMode(CP_POSITION_CENTER);
	currentMenu = MainMenu;
	MoveUI(currentMenu);

	TimerInitFrames(&timertest, 60);


	RenderObjectInit(&sRender0, "");
	RenderObjectInit(&sRender1, "");
	startText.render0 = &sRender0;
	startText.render1 = &sRender1;
	startText.render2 = &sRender2;
	startText.position.x = 600;
	startText.position.y = 300;
	sRender0.text = "RPG TEST GAME";
	sRender1.text = "Press Enter to start the battle or Escape to exit.";
	sRender2.text = "Press Space to reset.";
	sRender2.offset.y = 40;
	sRender1.offset.y = 20;
	sRender1.offset.x = -100;

	RenderObjectInit(&mRender0, "");
	RenderObjectInit(&mRender1, "");
	RenderObjectInit(&mRender2, "");
	RenderObjectInit(&mRender3, "");
	menu1.render0 = &mRender0;
	menu1.render1 = &mRender1;
	menu1.render2 = &mRender2;
	menu1.render3 = &mRender3;
	menu1.position.x = 600;
	menu1.position.y = 500;
	mRender0.text = "Start Battle";
	mRender1.offset.y = 50;
	mRender1.text = "Quit";
	mRender2.offset.x = -50;
	mRender3.offset.x = -50;
	mRender2.offset.y = 50;
	mRender3.offset.y = 50;
	mRender0.isShape = 0;
	mRender1.isShape = 0;
	mRender2.isShape = 1;
	mRender3.isShape = 1;
	mRender2.imgScale.x = 50;
	mRender2.imgScale.y = 50;
	mRender3.imgScale.x = 50;
	mRender3.imgScale.y = 50;
}

void gamestate_MainMenu_update(void)
{
	UpdateTimer(&timertest);

	if (CP_System_GetFrameCount() == 300)
		PauseTimer(&timertest);
	if (CP_Input_GetMouseX() <= 675 && CP_Input_GetMouseX() >= 575)
	{
		if (CP_Input_GetMouseY() <= 550 && CP_Input_GetMouseY() >= 450) 
		{
			mRender0.isShape = 1;
			mRender0.imgScale.x = 200;
			mRender0.imgScale.y = 50;
			if (CP_Input_MouseClicked())
			{
				currMenuLocation = 1;
				MenuSelect(currentMenu);
			}
		}
		if (CP_Input_GetMouseY() <= 650 && CP_Input_GetMouseY() >= 550)
		{
			mRender1.isShape = 1;
			mRender1.imgScale.x = 200;
			mRender1.imgScale.y = 50;
			if (CP_Input_MouseClicked())
			{
				currMenuLocation = 0;
				MenuSelect(currentMenu);
			}
		}

	}
	else 
	{
		mRender0.isShape = 0;
		mRender1.isShape = 0;

	}



	CP_Graphics_ClearBackground(CP_Color_Create(255, 255, 255, 255));

	// check input, update simulation, render etc.
			//Reset
	DrawGameObject(&startText);

	mRender2.rotation += 3;
	mRender3.rotation -= 1;
	CP_Settings_TextSize(100);
	mRender2.offset.y = 50 + (-50.0f * currMenuLocation);
	mRender3.offset.y = 50 + (-50.0f * currMenuLocation);
	DrawGameObject(&menu1);
	CP_Settings_TextSize(20);
	MoveUI(currentMenu);

	if (CP_Input_KeyTriggered(KEY_ENTER))
	{
		MenuSelect(currentMenu);
	}
	if (CP_Input_KeyTriggered(KEY_SPACE))
	{
		CP_Engine_SetNextGameState(gamestate_SplashScreen_init, gamestate_SplashScreen_update, gamestate_SplashScreen_exit);
	}
}

void gamestate_MainMenu_exit(void)
{
	// shut down the gamestate and cleanup any dynamic memory
}
