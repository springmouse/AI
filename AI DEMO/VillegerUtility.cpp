#include "VillegerUtility.h"
#include "Entity.h"
#include "VillagerBlackBoard.h"
#include "GetAStarPath.h"

#include <iostream>


VillegerUtility::VillegerUtility(Entity * entity)
{
	m_myEntity = entity;
}


VillegerUtility::~VillegerUtility()
{
	delete m_myEntity;
}

void VillegerUtility::Update(float deltaTime)
{
	CalculateGetFood();
	ClaculateMurder();
	ClaculateWander();
	CalculateFight();
	ClaculateFlee();
}

void VillegerUtility::CalculateGetFood()
{
	m_getFood = 0;

	if (m_myEntity->m_murder == true)
	{
		return;
	}

	m_getFood = - m_myEntity->m_food + m_myEntity->m_maxFood;

	std::cout << "m_getFood ";
	std::cout << m_getFood;
	std::cout << "\n";
}

void VillegerUtility::ClaculateMurder()
{
	m_murder = (-m_myEntity->m_food - m_myEntity->GetBlackBoard()->m_food.size());
	m_murder += (-m_myEntity->m_health);
	
	float increase = m_myEntity->m_maxHealth - m_myEntity->m_health;
	
	m_murder += (increase * increase);

	std::cout << "m_murder ";
	std::cout << m_murder;
	std::cout << "\n";
}

void VillegerUtility::ClaculateWander()
{
	m_wonder = 0;

	m_wonder = m_myEntity->m_food + m_myEntity->GetBlackBoard()->m_food.size();

	std::cout << "m_wonder ";
	std::cout << m_wonder;
	std::cout << "\n";
}

void VillegerUtility::CalculateFight()
{
	m_fight = 0;

	if (m_myEntity->GetBlackBoard()->m_murders.size() <= 0)
	{
		return;
	}

	Vector2 pos = m_myEntity->GetPos();

	for each (Entity * unit in m_myEntity->GetBlackBoard()->m_entites)
	{
		if ((sprMagnatude((unit->GetPos() - pos)) < (m_checkRadius * m_checkRadius)) && m_myEntity != unit)
		{
			if (PATH_FINDER->LineCheck(pos, unit->GetPos()) == false)
			{
				m_fight += 10;
			}
		}
	}

	std::cout << "m_fight ";
	std::cout << m_fight;
	std::cout << "\n";
}

void VillegerUtility::ClaculateFlee()
{
	m_flee = 0;

	if (m_myEntity->m_murder == true || m_myEntity->GetBlackBoard()->m_murders.size() <= 0)
	{
		return;
	}

	float increase = m_myEntity->m_maxHealth - m_myEntity->m_health;

	m_murder += (increase * 3);

	std::cout << "m_flee ";
	std::cout << m_flee;
	std::cout << "\n\n";
}

float VillegerUtility::sprMagnatude(Vector2 pos)
{
	return ((pos.x * pos.x) + (pos.y * pos.y));
}