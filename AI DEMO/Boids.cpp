#include "Boids.h"
#include "BoidsBlackBoard.h"
#include "Information.h"


Boids::Boids(BoidsBlackBoard * blackBoard, Vector2 center)
{
    m_blackBoard = blackBoard;
    m_pos = center;

    m_pos.x = std::rand() % 600;
    m_pos.y = std::rand() % 300;

    m_velocity = Vector2(0, 0);
    m_acceleration = Vector2(0, 0);

    m_maxVelocity = 120;

    m_septerationRadius = 30;
    m_alignmentRadius = 80;
    m_cohesionRadius = 120;

    m_seperationWeight = 80;
    m_alignmentWeight = 40;
    m_cohesionWeight = 10;

    m_seekWeight = 9;
    m_wonderWeight = 2;

    m_leader = false;
}


Boids::~Boids()
{
}

void Boids::Update(float deltaTime)
{
    m_acceleration = Vector2(0, 0);

    if (m_leader == false)
    {
        CalculateSeperation();
        CalculateAlignment();
        CalculateCohesion();
        CalculateSeek();
    }

    CalculateWonder();

    if (m_blackBoard->sprMagnatude(m_acceleration) > (m_maxVelocity * m_maxVelocity))
    {
        m_acceleration.normalise();
        m_acceleration *= m_maxVelocity;
    }

    m_velocity += m_acceleration;

    if (m_blackBoard->sprMagnatude(m_velocity) > (m_maxVelocity * m_maxVelocity))
    {
        m_velocity.normalise();
        m_velocity *= m_maxVelocity;
    }

    if (m_leader == true)
    {
        if ((m_pos.x + m_velocity.x) <= 0 || (m_pos.x + m_velocity.x) >= INFOMATION->ScreenWidth)
        {
            m_velocity.x -= (m_velocity.x * 2);
        }

        if ((m_pos.y + m_velocity.y) <= 0 || (m_pos.y + m_velocity.y) >= INFOMATION->ScreenHeight)
        {
            m_velocity.y -= (m_velocity.y * 2);
        }
    }

    m_pos += (m_velocity * deltaTime);
}

void Boids::CalculateSeperation()
{
    Vector2 seperationAcceleration = Vector2(0, 0);
    float count = 0;

    for each (ShareBoidPtr boid in m_blackBoard->m_boids)
    {
        if ((m_blackBoard->sprMagnatude(boid->GetPos() - m_pos)) < (m_septerationRadius * m_septerationRadius))
        {
            count += 1; 
            Vector2 holder = m_pos;
            holder -= boid->GetPos();
            seperationAcceleration += holder;
        }
    }
/*
    count = (1 / count);
    seperationAcceleration *= count;*/
    
    m_acceleration += (seperationAcceleration * m_seperationWeight);
}

void Boids::CalculateAlignment()
{
    Vector2 alignmeantAcceleration = Vector2(0,0);

    Vector2 progectedPos = m_velocity;
    progectedPos.normalise();
    progectedPos *= (m_alignmentRadius - 20);

    progectedPos += m_pos;

    float count = 0;

    for each (ShareBoidPtr boid in m_blackBoard->m_boids)
    {
        if ((m_blackBoard->sprMagnatude(boid->GetPos() - progectedPos)) < (m_alignmentRadius * m_alignmentRadius))
        {
            count += 1;
            alignmeantAcceleration += boid->GetVelocity();
        }
    }

    count = (1 / count);
    alignmeantAcceleration *= count;

    m_acceleration += (alignmeantAcceleration * m_alignmentWeight);
}

void Boids::CalculateCohesion()
{
    Vector2 cohesionAcceleration = Vector2(0, 0);
    float count = 0;

    for each (ShareBoidPtr boid in m_blackBoard->m_boids)
    {
        if ((m_blackBoard->sprMagnatude(boid->GetPos() - m_pos)) < (m_cohesionRadius * m_cohesionRadius))
        {
            count += 1;
            Vector2 holder = boid->GetPos();
            holder -= m_pos;
            cohesionAcceleration += holder;
        }
    }

    count = (1 / count);
    cohesionAcceleration *= count;

    m_acceleration += (cohesionAcceleration * m_cohesionWeight);
}

void Boids::CalculateSeek()
{
    Vector2 holder = m_blackBoard->GetTarget(m_pos);
    holder -= m_pos;

    m_acceleration += (holder * m_seekWeight);
}

void Boids::CalculateWonder()
{

    Vector2 wonder = m_velocity;
    wonder.normalise();

    wonder.x *= (std::rand() % (int)(m_septerationRadius * 2)) - m_septerationRadius;
    wonder.x *= (std::rand() % (int)(m_septerationRadius * 2)) - m_septerationRadius;

    wonder += m_pos;

    m_acceleration += (wonder * m_wonderWeight);

}

void Boids::SetLeader(bool seter)
{
    m_leader = seter;
}

Vector2 Boids::GetVelocity()
{
    return m_velocity;
}

void Boids::Draw(aie::Renderer2D * rendere)
{
    rendere->setRenderColour(0.5, 0, 0.5, 1);
    rendere->drawCircle(m_pos.x, m_pos.y, 10);
    rendere->setRenderColour(1, 1, 1, 1);
}
