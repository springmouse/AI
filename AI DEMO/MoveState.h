#pragma once
#include "EntityStates.h"
#include <Vector2.h>

class MoveState :
    public EntityStates
{

public:

    MoveState(Entity * ent);

    ~MoveState();

    void onUpdate(float deltaTime);

	float sprMagnatude(Vector2 pos);
};

