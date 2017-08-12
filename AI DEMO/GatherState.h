#pragma once
#include "EntityStates.h"

class GatherState :
	public EntityStates
{
public:
	GatherState(Entity * unit);
	~GatherState();

	void onUpdate(float deltaTime);
};

