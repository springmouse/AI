#pragma once
#include "EntityStates.h"

class AttackState :
	public EntityStates
{
public:
	AttackState(Entity * unit);
	~AttackState();

	void onUpdate(float deltaTime);
};

