#pragma once
#include "cprocessing.h"
/* 
Author:       Daunte Williamson
Email:        daunte.williamson@digipen.edu
Description:  Header file for anim_controller.c
              Contains definition for Animation Struct,
              playAnimation(), DrawSpriteFrame()
*/

/*Struct for specific animations.*/
struct Animation
{
  CP_Image file; /*CP file path for image resource*/
  float frameWidth; /*Width of animation frame in pixels*/
  float frameHeight; /*Height of animation frame in pixels*/
  int startRow; /*0 indexed - starting row for animation on image file*/
  int startFrame; /*0 indexed - starting column for first frame in animation*/
  int currentRow; /*0 indexed - current row of image being drawn*/
  int currentFrame; /*0 indexed - current column of image being drawn*/
  int endRow; /*0 indexed - ending row for animation*/
  int endFrame; /*0 indexed - ending column for animation*/
  int frameRate; /*How many delay frames(steps) that must pass before next frame is drawn to scene*/
  int currentStep; /*Decreasing counter for frameRate. 0 = move to next frame*/
  int loop; /*Boolean - 1 = loop the animation, 0 = play animation only once; hold on end frame*/
  int opacity; /*Value for alpha channel. 0 = invisible, 255 = completely visible*/
};

struct Animation playAnimation(struct Animation anim, float xPos, float yPos);
void DrawSpriteFrame(CP_Image file, float width, float height, int row,
  int col, float xPos, float yPos, int alpha);
