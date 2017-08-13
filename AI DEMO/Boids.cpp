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

    m_maxVelocity = 240;
    m_minVolocity = 150;

    m_septerationRadius = 40;
    m_alignmentRadius = 250;
    m_cohesionRadius = 150;

    m_seperationWeight = 40;
    m_alignmentWeight = 18;
    m_cohesionWeight = 20;

    m_seekWeight = 1;
    m_wonderWeight = 2;

    m_leader = false;
}


Boids::~Boids()
{
}

bool Boids::operator==(Boids & other)
{
    if (m_pos == other.GetPos())
    {
        return true;
    }
    return false;
}

bool Boids::operator!=(ShareBoidPtr & other)
{
    if (m_pos != other->GetPos())
    {
        return true;
    }
    return false;
}

void Boids::Update(float deltaTime)
{
    m_acceleration = Vector2(1, 1);

    CalculateSeperation();
    CalculateAlignment();
    CalculateCohesion();
    CalculateWonder();
    CalculateSeek();

    m_acceleration *= 0.25f;



    if (m_blackBoard->sprMagnatude(m_acceleration) > (m_maxVelocity * m_maxVelocity))
    {
        m_acceleration.normalise();
        m_acceleration *= m_maxVelocity;
    }

    m_velocity = (m_velocity + m_velocity + m_velocity + m_acceleration) * 0.25f;

    if (m_blackBoard->sprMagnatude(m_velocity) > (m_maxVelocity * m_maxVelocity))
    {
        m_velocity.normalise();
        m_velocity *= m_maxVelocity;
    }

    if (m_blackBoard->sprMagnatude(m_velocity) < (m_minVolocity * m_minVolocity))
    {
        m_velocity.normalise();
        m_velocity *= m_minVolocity;
    }

    m_pos += (m_velocity * deltaTime);

    if (m_pos.x > INFOMATION->ScreenWidth)
    {
        m_pos.x = 0;
    }
    if (m_pos.x < 0)
    {
        m_pos.x = INFOMATION->ScreenWidth;
    }
    if (m_pos.y > INFOMATION->ScreenHeight)
    {
        m_pos.y = 0;
    }
    if (m_pos.y < 0)
    {
        m_pos.y = INFOMATION->ScreenHeight;
    }
}

void Boids::CalculateSeperation()
{
    Vector2 seperationAcceleration = Vector2(0, 0);
    float count = 0;

    for each (ShareBoidPtr boid in m_blackBoard->m_boids)
    {
        if ((m_blackBoard->sprMagnatude(boid->GetPos() - m_pos)) < (m_septerationRadius * m_septerationRadius) && *this != boid)
        {
            count += 1; 
            seperationAcceleration += boid->GetPos();
        }
    }


    if (count != 0)
    {
        float devide = (float)(1 / count);

        seperationAcceleration *= devide;

        seperationAcceleration = (m_pos - seperationAcceleration);
        
        m_acceleration += (seperationAcceleration * m_seperationWeight);
    }
}

void Boids::CalculateAlignment()
{
    Vector2 alignmeantAcceleration = Vector2(0,0);

    Vector2 progectedPos = m_velocity;
    progectedPos.normalise();
    progectedPos *= (m_alignmentRadius);

    progectedPos += m_pos;

    float count = 0;

    for each (ShareBoidPtr boid in m_blackBoard->m_boids)
    {
        if ((m_blackBoard->sprMagnatude(boid->GetPos() - progectedPos)) < (m_alignmentRadius * m_alignmentRadius) && *this != boid)
        {
            count += 1;
            alignmeantAcceleration += boid->GetVelocity();
        }
    }


    if (count != 0)
    {
        count = (float)(1 / count);

        alignmeantAcceleration *= count;

        m_acceleration += (alignmeantAcceleration * m_alignmentWeight);
    }
}

void Boids::CalculateCohesion()
{
    Vector2 cohesionAcceleration = Vector2(0, 0);

    Vector2 progectedPos = m_velocity;
    progectedPos.normalise();
    progectedPos *= ((m_cohesionRadius * 0.5f));

    progectedPos += m_pos;

    float count = 0;

    for each (ShareBoidPtr boid in m_blackBoard->m_boids)
    {
        if ((m_blackBoard->sprMagnatude(boid->GetPos() - progectedPos)) < (m_cohesionRadius * m_cohesionRadius) && *this != boid)
        {
            count += 1;
            cohesionAcceleration += boid->GetPos();
        }
    }


    if (count != 0)
    {
        count = (float)(1 / count);
        cohesionAcceleration *= count;

        cohesionAcceleration = (m_pos - cohesionAcceleration);

        m_acceleration += (cohesionAcceleration * m_cohesionWeight);
    }
}

void Boids::CalculateSeek()
{
        Vector2 holder = m_blackBoard->GetTarget();
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

    wonder -= m_pos;

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
