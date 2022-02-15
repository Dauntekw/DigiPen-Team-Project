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

#include "SplashScreen.h"


RenderObject testObject0;
GameObject testGAMEObject;
int currentFrameCount;

// use CP_Engine_SetNextGameState to specify this function as the initialization function
// this function will be called once at the beginning of the program
void gamestate_SplashScreen_init(void)
{
	currentFrameCount = 0;
	// initialize variables and CProcessing settings for this gamestate
	testGAMEObject.render0 = &testObject0;
	testGAMEObject.position.x = (float)CP_System_GetWindowWidth() / 2;
	testGAMEObject.position.y = (float)CP_System_GetWindowHeight() / 2;

	// initialize variables and CProcessing settings for this gamestate
	RenderObjectInit(testGAMEObject.render0, "./Assets/Digipen_BLACK.png");
	testGAMEObject.render0->offset.x = 0;
	testGAMEObject.render0->offset.y = 0;
	testGAMEObject.render0->alpha = 255;

}

// use CP_Engine_SetNextGameState to specify this function as the update function
// this function will be called repeatedly every frame
void gamestate_SplashScreen_update(void)
{
	CP_Graphics_ClearBackground(CP_Color_Create(255, 255, 255, 255));

	currentFrameCount++;
	// check input, update simulation, render etc.
	CP_Graphics_DrawRect((float)CP_System_GetWindowWidth() / 2, 
		(float)CP_System_GetWindowHeight() / 2, 
		1920, 1080);
	DrawGameObject(&testGAMEObject);
	if (currentFrameCount > 120)
		testGAMEObject.render0->alpha -= 3;
	if (currentFrameCount == 224)
	{
		CP_Engine_SetNextGameStateForced(gamestate_MainMenu_init, gamestate_MainMenu_update, gamestate_MainMenu_exit);
	}

}

// use CP_Engine_SetNextGameState to specify this function as the exit function
// this function will be called once just before leaving the current gamestate
void gamestate_SplashScreen_exit(void)
{
	// shut down the gamestate and cleanup any dynamic memory
}
