#include "MoveState.h"
#include "Entity.h"
#include "NavManager.h"



MoveState::MoveState(Entity * ent)
{
    m_myEntity = ent;
}


MoveState::~MoveState()
{
}

void MoveState::onUpdate(float deltaTime)
{
    if (m_myEntity->m_path.size() > 0)
    {
        if (m_myEntity->m_path.front() == nullptr)
        {
            m_myEntity->m_path.clear();
            return;
        }

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

        Vector2 move = m_myEntity->m_path.front();
        move -= m_myEntity->GetPos();
        move.normalise();

        m_myEntity->UpdatePos((move * 10) * deltaTime);
    }
}

float MoveState::sprMagnatude(Vector2 pos)
{
	return ((pos.x * pos.x) + (pos.y * pos.y));
}
