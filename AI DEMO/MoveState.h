#pragma once
#include "EntityStates.h"

class MoveState :
    public EntityStates
{

public:

    MoveState(Entity * ent);

    ~MoveState();

    void onUpdate(float deltaTime);

};

