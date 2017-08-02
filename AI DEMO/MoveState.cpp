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

        if (m_myEntity->m_path.front()->CheckIfInMeshBounds(m_myEntity->GetPos()))
        {
            m_myEntity->m_previousLocation = m_myEntity->m_currLocation;
            m_myEntity->m_currLocation = m_myEntity->m_path.front();

            m_myEntity->m_previousLocation->ModifyWeightCost(-1);
            m_myEntity->m_currLocation->ModifyWeightCost(1);

            m_myEntity->m_path.pop_front();

            if (m_myEntity->m_path.size() <= 0)
            {
                return;
            }
        }

        Vector2 move = m_myEntity->m_path.front()->GetCenter();
        move -= m_myEntity->GetPos();
        move.normalise();

        m_myEntity->UpdatePos((move * deltaTime) * 10);
    }
}
