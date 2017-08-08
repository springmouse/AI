#pragma once
#include "Boids.h"
#include "MouseState.h"
#include "TypesAndDefines.h"
#include <list>
#include <Vector2.h>

class BoidsBlackBoard
{
public:

    BoidsBlackBoard();
    ~BoidsBlackBoard();

    void Update(float deltaTime);

    float sprMagnatude(Vector2 pos);

    Vector2 GetTarget();

    std::list<ShareBoidPtr> m_boids;

private:

    Vector2 target;
};

