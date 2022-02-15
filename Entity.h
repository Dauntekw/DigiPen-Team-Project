#pragma once

#include "GameObject.h"

//Targetting method type
typedef enum t_method
{
	Select1Enemy,
	Select1Ally,
	Select1Each,
	AllEnemies,
	AllAllies,
	All,
	Self,
	Select1EnemyAndAdjacent,
	Select1AllyAndAdjacent,

}TargetMethod;

//Skill definition
typedef struct skill
{
	int ID;
	TargetMethod targeting;
	FunctionPtr skill;
}Skill;

//Type definition for RPG stat tracking
typedef struct rpg 
{
	int curHealth;
	int maxHealth;
	int base_strength;
	int base_speed;
	int base_agility;
	int level;

}StatTracker;

//Type definition for Entities
typedef struct e_obj
{
	int ID;
	GameObject obj;
	StatTracker stats;
	//Inventory Stuff & Equipment

	//Skills
}Entity;

//Type definition for BattleSlots
typedef struct b_slot
{
	int location;
	CP_Vector screenPos;
	Entity* occupier;
}BattleSlot;

//Type definition for BattleData
typedef struct b_data
{
	BattleSlot slots[8];
}BattleData;