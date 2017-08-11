#include "BoidsBlackBoard.h"
#include "Information.h"
#include <iostream>
#include <Application.h>

BoidsBlackBoard::BoidsBlackBoard()
{
    upperBounds= Vector2(INFOMATION->ScreenWidth, INFOMATION->ScreenHeight);
    boundsModifier = 40;
    isInBounds = true;
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

Vector2 BoidsBlackBoard::GetTarget(Vector2 pos)
{
    return Vector2(INFOMATION->ScreenWidth * 0.5, INFOMATION->ScreenHeight * 0.5);
}

void BoidsBlackBoard::MakeLeaders()
{
}
