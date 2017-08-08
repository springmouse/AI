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

    Vector2 GetTarget(Vector2 pos);

    std::list<ShareBoidPtr> m_boids;

    std::list<ShareBoidPtr> m_leaders;

private:

    void MakeLeaders();

    bool isInBounds;

    float boundsModifier;

    Vector2 target;

    Vector2 upperBounds;
};

