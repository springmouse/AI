#pragma once
#include "EntityStates.h"


class MurderState :
	public EntityStates
{
public:
	MurderState(Entity * unit);
	~MurderState();

	void onUpdate(float deltaTime);
};

