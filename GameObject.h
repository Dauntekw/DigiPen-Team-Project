#pragma once
#include "cprocessing.h"

#pragma region Struct Definitions
typedef struct img_obj
{
	CP_Vector offset;
	float rotation;
	CP_Image sprite;
	int alpha;
	CP_Vector imgScale;
	char* text;
	int ID;
	CP_BOOL isShape;
} RenderObject;

typedef struct txt_obj
{
	float scale;
	CP_Color color;
	CP_Vector offset;
	char* text;
	CP_Font font;
}TextObject;

enum ColliderType
{
	ColCircle,
	ColRectangle,
};

typedef struct coll_obj
{
	CP_BOOL trigger;
	CP_Vector offset;
	enum ColliderType colType;
	int ID;
} ColliderObject;

typedef struct coll_event
{
	ColliderObject* sender;
	ColliderObject* collider;
	int frame;

}Collision;

typedef struct gm_obj
{
	RenderObject* render0;
	RenderObject* render1;
	RenderObject* render2;
	RenderObject* render3;
	ColliderObject* collider;
	CP_Vector position;
} GameObject;
#pragma endregion

#pragma region Function prototypes
void TextObjectInit(TextObject* obj, char* text, float size, const char* fontPath, CP_Color color, CP_Vector offset);

void DrawTextObject(TextObject* obj, CP_Vector pos);

void RenderObjectInit(RenderObject* obj, const char* path);

void DrawGameObject(GameObject* obj);
#pragma endregion
