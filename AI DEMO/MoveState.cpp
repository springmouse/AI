#include "MoveState.h"
#include "Entity.h"
#include "NavManager.h"
#include "GetAStarPath.h"



MoveState::MoveState(Entity * ent)
{
    m_myEntity = ent;
}


MoveState::~MoveState()
{
}

void MoveState::onUpdate(float deltaTime)
{
	//make sure we have a path
    if (m_myEntity->m_path.size() > 0)
    {
		//make sure said path is still mostly valid
        if (m_myEntity->m_path.front() == nullptr)
        {
            m_myEntity->m_path.clear();
            return;
        }

		//check that the unit is not trying to do something stupid like move through a wall or off the map
		if (PATH_FINDER->LineCheck(m_myEntity->GetPos(), m_myEntity->m_path.front()))
		{
			m_myEntity->m_path.clear();
			return;
		}

		//check if we are within a certin distance of the vector in the fron of the path list
		Vector2 holder = m_myEntity->m_path.front();
		holder -= m_myEntity->GetPos();

        if (sprMagnatude(holder) < (100))
        {
            m_myEntity->m_path.pop_front();

            if (m_myEntity->m_path.size() <= 0)
            {
                return;
            }
        }

		//get us a movmeant direction
        Vector2 move = m_myEntity->m_path.front();
        move -= m_myEntity->GetPos();
        move.normalise();

		//move us with the correct speed if we are a murderer or not
		if(m_myEntity->m_murder == false)
		{
			m_myEntity->UpdatePos((move * m_myEntity->m_moveSpeed) * deltaTime);
		}
		else
		{
			m_myEntity->UpdatePos((move * m_myEntity->m_murderMoveSpeed) * deltaTime);
		}
    }
}

float MoveState::sprMagnatude(Vector2 pos)
{
	return ((pos.x * pos.x) + (pos.y * pos.y));
}
