#include "GatherState.h"
#include "Entity.h"
#include "VillegerUtility.h"
#include "Food.h";


GatherState::GatherState(Entity * unit)
{
	m_myEntity = unit;
}


GatherState::~GatherState()
{
}

void GatherState::onUpdate(float deltaTime)
{
	Vector2 pos = m_myEntity->GetPos();

	//makes sure the food it seeks still exists
	if (m_myEntity->m_neareastFood.lock() == nullptr)
	{
		return;
	}

	//move towards and if close enought gather food
	if ((m_myEntity->GetUtility()->sprMagnatude(m_myEntity->m_neareastFood.lock()->GetPos() - pos)) < 2000)
	{
		m_myEntity->m_food += m_myEntity->m_neareastFood.lock()->GatherFood();

		if (m_myEntity->m_food > m_myEntity->m_maxFood)
		{
			m_myEntity->m_food = m_myEntity->m_maxFood;
		}
	}
}
