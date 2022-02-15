#include "cprocessing.h"
#include "math.h"
#include "malloc.h"
#include "stdio.h"
#include "stdlib.h"
#include "GameObject.h"

#pragma region RenderObject Definition
//Initializes RenderObjects by setting their default values
//REFACTOR:: Turn into a constructor
void RenderObjectInit(RenderObject* obj, const char* path)
{
	obj->sprite = CP_Image_Load(path);
	obj->alpha = 255;
	obj->offset.x = 0;
	obj->offset.y = 0;
	obj->rotation = 0;
	obj->imgScale.x = 1;
	obj->imgScale.y = 1;
	obj->text = "";
}
void DrawRenderObject(RenderObject* obj, CP_Vector pos)
{
	if (obj->sprite)
	{
		CP_Image_DrawAdvanced(obj->sprite, pos.x + obj->offset.x, pos.y + obj->offset.y,
			(float)CP_Image_GetWidth(obj->sprite) * obj->imgScale.x,
			(float)CP_Image_GetHeight(obj->sprite) * obj->imgScale.y,
			obj->alpha, obj->rotation);
	}
	else if (obj->isShape)
	{
		CP_Graphics_DrawRectAdvanced(pos.x + obj->offset.x, pos.y + obj->offset.y,
			obj->imgScale.x, obj->imgScale.y, obj->rotation, 1.0);
	}
	if (obj->text);
	{
		CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
		CP_Settings_TextSize(20.0f);
		CP_Font_DrawText(obj->text, pos.x + obj->offset.x, pos.y + obj->offset.y);
		CP_Settings_Fill(CP_Color_Create(255, 255, 255, 255));
	}
}
#pragma endregion

#pragma region TextObject Definition

void TextObjectInit(TextObject* obj, char* text, float size, const char* fontPath, CP_Color color, CP_Vector offset)
{
	obj->text = text;
	obj->scale = size;
	if(fontPath)
		obj->font = CP_Font_Load(fontPath);
	obj->color = color;
	obj->offset = offset;
};

void DrawTextObject(TextObject* obj, CP_Vector pos)
{
	CP_Settings_Fill(obj->color);
	CP_Settings_TextSize(obj->scale);
	CP_Font_Set(obj->font);
	CP_Font_DrawText(obj->text, pos.x + obj->offset.x, pos.y + obj->offset.y);
	CP_Font_Set(CP_Font_GetDefault());
	CP_Settings_TextSize(20.0f);
	CP_Settings_Fill(CP_Color_Create(255, 255, 255, 255));
}

#pragma endregion

#pragma region GameObject Definition


//TODO:: FIX THIS
void GameObjectInit(GameObject* obj, RenderObject r0,
	RenderObject r1, RenderObject r2, RenderObject r3,
	ColliderObject c, float x, float y)
{
	obj->render0 = &r0;
	obj->render1 = &r1;
	obj->render2 = &r2;
	obj->render3 = &r3;
	obj->collider = &c;
	obj->position.x = x;
	obj->position.y = y;
}
void DrawGameObject(GameObject* obj)
{

	if (obj->render0)
		DrawRenderObject(obj->render0, obj->position);
	if (obj->render1)
		DrawRenderObject(obj->render1, obj->position);
	if (obj->render2)
		DrawRenderObject(obj->render2, obj->position);
	if (obj->render3)
		DrawRenderObject(obj->render3, obj->position);
};

#pragma endregion