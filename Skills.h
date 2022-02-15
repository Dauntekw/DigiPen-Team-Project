#pragma once
#include "Entity.h"


#pragma region Function Prototypes
void DamageLocation(BattleData* data, int target, int damage);
void DamageEntity(Entity* target, int damage);
void KillEntity(Entity* target);
void SummonEntityToSlot(BattleSlot* slot, Entity* entity);
void SummonEntityToPosition(BattleData* data, int pos, Entity* entity);
#pragma endregion

