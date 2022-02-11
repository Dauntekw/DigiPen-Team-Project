//---------------------------------------------------------
// file:	anim_controller.c
// author:	Daunte Williamson
// email:	daunte.williamson@digipen.edu
//
// brief:	File that contains all core functions for
// drawing animations onto the worldspace.
//
// documentation link:
// https://github.com/DigiPen-Faculty/CProcessing/wiki
//
// Copyright © 2020 DigiPen, All rights reserved.
//---------------------------------------------------------

#include "cprocessing.h"
#include "anim_controller.h"

/*Display animation in worldspace. Returns new copy of passed animation after drawing current frame.*/
struct Animation playAnimation(struct Animation anim, float xPos, float yPos)
{
  struct Animation newAnim = anim; /*Copy of passed animation argument.*/

  int startCol = anim.startFrame; /*Starting column for animation*/
  int currentRow = anim.currentRow; /*Current row of animation being drawn*/
  int currentCol = anim.currentFrame; /*Current column of animation being drawn*/
  int endCol = anim.endFrame; /*Ending column of animation being drawn*/

  /*Draw current frame of animation to worldspace*/
  DrawSpriteFrame(anim.file, anim.frameWidth, anim.frameHeight, currentRow, currentCol, xPos, yPos, anim.opacity);
  
  /*Check if ready to advance frame in animation*/
  if (anim.currentStep <= 0)
  {
    /*
      currentStep is 0, increase current frame if next frame is less than or equal to ending column.
      Reset currentCol if value is greater than ending column
    */
    currentCol = (currentCol + 1 <= endCol) ? currentCol + 1 : (anim.loop) ? startCol : currentCol;

    newAnim.currentStep = newAnim.frameRate; /*Reset currentStep value to equal frameRate*/

    /*Pass currentRow and currentFrame values to new copy of passed animation*/
    newAnim.currentRow = currentRow;
    newAnim.currentFrame = currentCol;
  }
  else 
  {
    newAnim.currentStep = newAnim.currentStep - 1; /*currentStep is greater than 0, decrease by 1*/
  }

  return newAnim; /*Return new copy of animation with updated values*/
}

/*Draw current frame of animation to worldspace using CP_Image_DrawSubImage*/
void DrawSpriteFrame(CP_Image file, float width, float height, int row, 
  int col, float xPos, float yPos, int alpha) 
{
  CP_Image_DrawSubImage(file, xPos, yPos, width, height, 0 + (width * col), 
    0 + (height * row), width * (col + 1), height * (row + 1), alpha);
}