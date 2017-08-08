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
    if (target.x >= (0 + boundsModifier) && target.y >= (0 + boundsModifier) && target.x <= (upperBounds.x - boundsModifier) && target.y <= (upperBounds.y - boundsModifier))
    {
        if (isInBounds == false)
        {
            isInBounds = true;

            for each (ShareBoidPtr boid in m_leaders)
            {
                boid->SetLeader(false);
            }

            m_leaders.clear();
        }

        return target;
    }
    else
    {
        if (isInBounds)
        {
            isInBounds = false;
            int amount = std::rand() % 5;

            for each (ShareBoidPtr boid in m_boids)
            {
                if (amount >= 0)
                {
                    boid->SetLeader(true);
                    m_leaders.push_back(boid);
                    amount--;
                }
                else
                {
                    break;
                }
            }
        }

        Vector2 closes = Vector2(10000, 10000);

        for each (ShareBoidPtr boid in m_leaders)
        {
            if (sprMagnatude(boid->GetPos()) < sprMagnatude(closes))
            {
                closes = boid->GetPos();
            }
        }

        return closes;
    }

}

void BoidsBlackBoard::MakeLeaders()
{
}
