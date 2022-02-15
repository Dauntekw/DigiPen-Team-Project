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

#include "cprocessing.h"
#include "EndingScreen.h"


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

TextObject tester;

// use CP_Engine_SetNextGameState to specify this function as the initialization function
// this function will be called once at the beginning of the program
void gamestate_Victory_init(void)
{
	CP_Vector testerPos;
	testerPos.x = 100;
	testerPos.y = 100;
	TextObjectInit(&tester,"Super tester", 50, "", CP_Color_Create(0,0,255,255),testerPos);
	currMenuLocation = 1;
	end = 1;

	// initialize variables and CProcessing settings for this gamestate
	// initialize variables and CProcessing settings for this gamestate
	CP_Settings_RectMode(CP_POSITION_CENTER);
	currentMenu = MainMenu;
	MoveUI(currentMenu);

	RenderObjectInit(&sRender0, "");
	RenderObjectInit(&sRender1, "");
	startText.render0 = &sRender0;
	startText.render1 = &sRender1;
	startText.render2 = &sRender2;
	startText.position.x = 600;
	startText.position.y = 300;
	
	
	sRender0.text = "Good job! You won!";
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
	mRender0.text = "Fight Again";
	mRender1.offset.y = 50;
	mRender1.text = "Main Menu";
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

void gamestate_Defeat_init(void)
{
	currMenuLocation = 1;
	end = 1;

	// initialize variables and CProcessing settings for this gamestate
	// initialize variables and CProcessing settings for this gamestate
	CP_Settings_RectMode(CP_POSITION_CENTER);
	currentMenu = MainMenu;
	MoveUI(currentMenu);

	RenderObjectInit(&sRender0, "");
	RenderObjectInit(&sRender1, "");
	startText.render0 = &sRender0;
	startText.render1 = &sRender1;
	startText.render2 = &sRender2;
	startText.position.x = 600;
	startText.position.y = 300;


	sRender0.text = "You Lost! Try again?";
	sRender1.text = "Press Enter to retry or Escape to exit.";
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
	mRender0.text = "Try Again";
	mRender1.offset.y = 50;
	mRender1.text = "Main Menu";
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


// use CP_Engine_SetNextGameState to specify this function as the update function
// this function will be called repeatedly every frame
void gamestate_EndingScreen_update(void)
{
	CP_Vector testerPos;
	testerPos.x = 100;
	testerPos.y = 100;
	DrawTextObject(&tester, testerPos);

	// check input, update simulation, render etc.
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

// use CP_Engine_SetNextGameState to specify this function as the exit function
// this function will be called once just before leaving the current gamestate
void gamestate_EndingScreen_exit(void)
{
	// shut down the gamestate and cleanup any dynamic memory
}
