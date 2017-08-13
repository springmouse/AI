#include "BoidsBlackBoard.h"
#include "Information.h"
#include <iostream>
#include <Application.h>

BoidsBlackBoard::BoidsBlackBoard()
{
}


BoidsBlackBoard::~BoidsBlackBoard()
{
}

float BoidsBlackBoard::sprMagnatude(Vector2 pos)
{
    return ((pos.x * pos.x) + (pos.y * pos.y));
}

Vector2 BoidsBlackBoard::GetTarget()
{
    return Vector2(INFOMATION->ScreenWidth * 0.5, INFOMATION->ScreenHeight * 0.5);
}

