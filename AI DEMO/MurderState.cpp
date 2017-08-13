#include "MurderState.h"
#include "VillegerUtility.h"
#include "VillagerBlackBoard.h"
#include "Entity.h"
#include <iostream>


MurderState::MurderState(Entity * unit)
{
	m_myEntity = unit;
}


MurderState::~MurderState()
{
}

void MurderState::onUpdate(float deltaTime)
{
	Vector2 pos = m_myEntity->GetPos();
	bool check = false;

	//check that the target is actually still alive and exists 
	for each (Entity * ent in m_myEntity->GetBlackBoard()->m_entites)
	{
		if (m_myEntity->m_murderTarget == ent)
		{
			check = true;
			break;
		}
	}

	//if target is not still alive or does not exist, exit out
	if (check == false)
	{
		m_myEntity->m_murderTarget = nullptr;
		return;
	}

	//if the target is still alive and we are close enought to attack do that
	if (m_myEntity->m_murderTarget->IsAlive())
	{
		if ((m_myEntity->GetUtility()->sprMagnatude(m_myEntity->m_murderTarget->GetPos() - pos)) < 100 && m_myEntity->m_attckCoolDown > m_myEntity->m_murderAttackSpeed)
		{
			m_myEntity->m_attckCoolDown = 0;
			m_myEntity->m_murderTarget->TakeDamage(m_myEntity->m_murderAttack);

			//if the target is now dead it means we killed them and we get all our food back >:)
			if (m_myEntity->m_murderTarget->IsAlive() == false)
			{
				m_myEntity->m_food = m_myEntity->m_maxFood;
			}
		}
	}

}
