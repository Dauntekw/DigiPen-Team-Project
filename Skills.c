#include "Skills.h"


#pragma region Base Functions
/******************************************************************************
   Function: DamageLocation

Description: Damages a target Entity based on it's position. If they would be
			 killed by this damage, it will kill the Entity as well.

	 Inputs: data - The current battle taking place.
			 target - The battle position to be damaged.
			 damage - The damage to be dealt.
******************************************************************************/
void DamageLocation(BattleData* data, int target, int damage)
{
	//Damage target.
	data->slots[target].occupier->stats.curHealth -= damage;
	//If the damage would kill them, kill them.
	if (data->slots[target].occupier->stats.curHealth <= 0)
		KillEntity(data->slots[target].occupier);
}

/******************************************************************************
   Function: DamageEntity

Description: Damages a target Entity. If they would be killed by this damage, it
			 will kill the Entity as well.

	 Inputs: target - The entity to be damaged.
			 damage - The damage to be dealt.
******************************************************************************/
void DamageEntity(Entity* target, int damage)
{
	//Damage target.
	target->stats.curHealth -= damage;
	//If the damage would kill them, kill them.
	if (target->stats.curHealth <= 0)
		KillEntity(target);
}

/******************************************************************************
   Function: SummonEntityToSlot

Description: Summons an entity into a specific BattleSlot on the battle map.

	 Inputs: slot - The BattleSlot to summon the enemy into.
			 entity - The entity to be summoned.
******************************************************************************/
void SummonEntityToSlot(BattleSlot* slot, Entity* entity)
{
	//Sets the battle slot occupier.
	slot->occupier = entity;
	//Other Summon Init Stuff.
}

/******************************************************************************
   Function: SummonEntityToPosition

Description: Summons an entity into a specific location on the battle map
			 instead of a specific BattleSlot.

	 Inputs: data - The current battle taking place.
			 pos - The battle position to summon that creature into.
			 entity - The entity to be summoned.
******************************************************************************/
void SummonEntityToPosition(BattleData* data, int pos, Entity* entity)
{
	//Sets the battle slot occupier.
	data->slots[pos].occupier = entity;
	//Other Summon Init Stuff.
}

/******************************************************************************
   Function: KillEntity

Description: Given a pointer to an entity, attempts to kill that entity if
			 possible.

	 Inputs: target -  The entity to be killed.
******************************************************************************/
void KillEntity(Entity* target)
{
	//KILL STUFF.
}
#pragma endregion
