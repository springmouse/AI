#include "AttackState.h"
#include "Entity.h"
#include "VillegerUtility.h"
#include "VillagerBlackBoard.h"
#include "Entity.h"
#include <iostream>


AttackState::AttackState(Entity * unit)
{
	m_myEntity = unit;
}


AttackState::~AttackState()
{
}

void AttackState::onUpdate(float deltaTime)
{
	Vector2 pos = m_myEntity->GetPos();
	bool check = false;

	//make suer our target still exists
	for each (Entity * ent in m_myEntity->GetBlackBoard()->m_murders)
	{
		if (m_myEntity->m_attackTarget == ent)
		{
			check = true;
			break;
		}
	}
	//if target does  not exit
	if (check == false)
	{
		m_myEntity->m_attackTarget = nullptr;
		return;
	}

	//if target is still alive and we are near them kill them
	if (m_myEntity->m_attackTarget->IsAlive())
	{
		if ((m_myEntity->GetUtility()->sprMagnatude(m_myEntity->m_attackTarget->GetPos() - pos)) < 100 && m_myEntity->m_attckCoolDown > m_myEntity->m_attackSpeed)
		{
			m_myEntity->m_attckCoolDown = 0;
			m_myEntity->m_attackTarget->TakeDamage(m_myEntity->m_attack);
			
			//if we killed the target we get to feast on there bodies tonight >:)
			if (m_myEntity->m_attackTarget->IsAlive() == false)
			{
				m_myEntity->m_food = m_myEntity->m_maxFood;
			}
		}
	}
}
