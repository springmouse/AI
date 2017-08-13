#include "Boids.h"
#include "BoidsBlackBoard.h"
#include "Information.h"


Boids::Boids(BoidsBlackBoard * blackBoard)
{
	//set units black board
    m_blackBoard = blackBoard;

	//set up units position
    m_pos.x = std::rand() % 600;
    m_pos.y = std::rand() % 300;

	//set velocity and acceleration to 0
    m_velocity = Vector2(0, 0);
    m_acceleration = Vector2(0, 0);

	//set up min max velocities
    m_maxVelocity = 240;
    m_minVolocity = 150;

	//set up the radius to check in
    m_septerationRadius = 40;
    m_alignmentRadius = 250;
    m_cohesionRadius = 150;

	//set you the diffrent forces weights
    m_seperationWeight = 40;
    m_alignmentWeight = 18;
    m_cohesionWeight = 20;

    m_seekWeight = 1;
    m_wonderWeight = 2;
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

	//calculate the diffrent forces and apply them to m_acceleration
    CalculateSeperation();
    CalculateAlignment();
    CalculateCohesion();
    CalculateWonder();
    CalculateSeek();

	//devide the acceleration by a 5th as we add five diffrent forces to it
    m_acceleration *= 0.25f;

	//if acceleration is to great rescale it down
    if (m_blackBoard->sprMagnatude(m_acceleration) > (m_maxVelocity * m_maxVelocity))
    {
        m_acceleration.normalise();
        m_acceleration *= m_maxVelocity;
    }

	//add acceleration to velocity, we do this to avoid snapping to the new heading
    m_velocity = (m_velocity + m_velocity + m_velocity + m_acceleration) * 0.25f;

	//check if we are going to fast and slow down
    if (m_blackBoard->sprMagnatude(m_velocity) > (m_maxVelocity * m_maxVelocity))
    {
        m_velocity.normalise();
        m_velocity *= m_maxVelocity;
    }

	//check if we are going to slow and speed up
    if (m_blackBoard->sprMagnatude(m_velocity) < (m_minVolocity * m_minVolocity))
    {
        m_velocity.normalise();
        m_velocity *= m_minVolocity;
    }

	//update our pos
    m_pos += (m_velocity * deltaTime);

	//wraps us around to the other side of the screen if one of these are triggered
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

	//find the position of all the boids with in m_septerationRadius^2
    for each (ShareBoidPtr boid in m_blackBoard->m_boids)
    {
        if ((m_blackBoard->sprMagnatude(boid->GetPos() - m_pos)) < (m_septerationRadius * m_septerationRadius) && *this != boid)
        {
            count += 1; 
            seperationAcceleration += boid->GetPos();
        }
    }

	//get average, find vector away from you and the average and apply to m_acceleration
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


	//find the velocity of all the boids with in m_alignmentRadius^2
    for each (ShareBoidPtr boid in m_blackBoard->m_boids)
    {
        if ((m_blackBoard->sprMagnatude(boid->GetPos() - progectedPos)) < (m_alignmentRadius * m_alignmentRadius) && *this != boid)
        {
            count += 1;
            alignmeantAcceleration += boid->GetVelocity();
        }
    }


	//get average and apply to m_acceleration
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

	//find the position of all the boids with in m_alignmentRadius^2
    for each (ShareBoidPtr boid in m_blackBoard->m_boids)
    {
        if ((m_blackBoard->sprMagnatude(boid->GetPos() - progectedPos)) < (m_cohesionRadius * m_cohesionRadius) && *this != boid)
        {
            count += 1;
            cohesionAcceleration += boid->GetPos();
        }
    }


	//get average, get vector from you to it and apply to m_acceleration
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
		//get vector from you to the seek position and add to m_acceleration
        Vector2 holder = m_blackBoard->GetTarget();
        holder -= m_pos;

        m_acceleration += (holder * m_seekWeight);
}

void Boids::CalculateWonder()
{
	//makes random vector based on m_velocity and applies it to m_acceleration
    Vector2 wonder = m_velocity;
    wonder.normalise();

    wonder.x *= (std::rand() % (int)(m_septerationRadius * 2)) - m_septerationRadius;
    wonder.y *= (std::rand() % (int)(m_septerationRadius * 2)) - m_septerationRadius;

    m_acceleration += (wonder * m_wonderWeight);

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
