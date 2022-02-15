#pragma once
#include "cprocessing.h"
#include "stdio.h"

//
typedef struct t_obj 
{
	int currentFrames;
	float currentSeconds;

	int duration_f;
	float duration_s;

	int paused;
	int frameCounter;
	int expired;

	//FunctionPtr activationFunction;
}Timer;

//Initializes a timer to go off of frames rather than seconds.
void TimerInitFrames(Timer* t, int frameDuration/*, FunctionPtr function*/)
{
	t->frameCounter = 1;
	t->duration_f = frameDuration;
	t->expired = 0;
	t->paused = 0;
	//t->activationFunction = function;
}

//Initializes a timer to go off of seconds rather than frames.
void TimerInitSeconds(Timer* t, float secondsDuration/*, FunctionPtr function*/)
{
	t->frameCounter = 0;
	t->duration_s = secondsDuration;
	t->expired = 0;
	t->paused = 0;

	//t->activationFunction = function;
	
}

//Pauses the timer, preventing updates from occuring.
void PauseTimer(Timer* t)
{
	t->paused = 1;
}

//Unpauses the timer, allowing updates to occur.
//Separated from PauseTimer for clarity.
void UnpauseTimer(Timer* t)
{
	t->paused = 0;
}

//Stops the timer prematurely, preventing updates 
//or any further editing. Perform before deletion.
void StopTimer(Timer* t)
{
	t->expired = 1;
}

//Updates the timer's current
void UpdateTimer(Timer* t)
{
	if (!t->paused && !t->expired)
	{
		if (t->frameCounter)
			t->currentFrames++;
		else
			t->currentSeconds += (float)1 / CP_System_GetFrameRate();

		if (t->currentFrames >= t->duration_f && t->duration_f > 0)
		{
			//t->activationFunction();
			StopTimer(t);
		}

		if (t->currentSeconds >= t->duration_s && t->duration_s > 0)
		{
			//t->activationFunction();
			StopTimer(t);
		}
	}
}