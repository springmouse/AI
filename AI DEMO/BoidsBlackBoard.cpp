#include "BoidsBlackBoard.h"
#include <iostream>


BoidsBlackBoard::BoidsBlackBoard()
{
}


BoidsBlackBoard::~BoidsBlackBoard()
{
}

void BoidsBlackBoard::Update(float deltaTime)
{

    target = MOUSE->mousePosExact;

}

float BoidsBlackBoard::sprMagnatude(Vector2 pos)
{
    return ((pos.x * pos.x) + (pos.y * pos.y));
}

Vector2 BoidsBlackBoard::GetTarget()
{
    if (target == Vector2(0.0f, 0.0f))
    {
        return Vector2(600, 350);
    }

    return target;
}
