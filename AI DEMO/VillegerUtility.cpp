#include "VillegerUtility.h"
#include "Entity.h"
#include "VillagerBlackBoard.h"
#include "GetAStarPath.h"

#include <iostream>


VillegerUtility::VillegerUtility(Entity * entity)
{
	m_myEntity = entity;

	m_getFood = 0;
	m_murder = 0;
	m_fight = 0;
	m_wonder = 0;
	m_flee = 0;

	m_checkRadius = 60;
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
	CalculateFlee();

	/*std::cout << "m_getFood ";
	std::cout << m_getFood;
	std::cout << "\n";

	std::cout << "m_murder ";
	std::cout << m_murder;
	std::cout << "\n";

	std::cout << "m_wonder ";
	std::cout << m_wonder;
	std::cout << "\n";

	std::cout << "m_fight ";
	std::cout << m_fight;
	std::cout << "\n";

	std::cout << "m_flee ";
	std::cout << m_flee;
	std::cout << "\n\n";*/
}

void VillegerUtility::CalculateGetFood()
{
	m_getFood = 0;

	//if we are a murder or there is no food we dont bother claculating this
	if (m_myEntity->m_murder == true || m_myEntity->GetBlackBoard()->m_food.size() <= 0)
	{
		return;
	}

	m_getFood = (m_myEntity->m_maxFood  - m_myEntity->m_food) * 1.5;

}

void VillegerUtility::ClaculateMurder()
{
	//or current health food and available food decrease the chances of murdering
	m_murder = (-m_myEntity->m_food - m_myEntity->GetBlackBoard()->m_food.size());
	m_murder += (-m_myEntity->m_health);
	
	float increase = m_myEntity->m_maxHealth - m_myEntity->m_health;
	
	//how much health we are missing^2 is our chance of snapping
	m_murder += (increase * increase);

}

void VillegerUtility::ClaculateWander()
{
	m_wonder = 0;

	//if we are not very hungery we walk on
	m_wonder = m_myEntity->m_food + m_myEntity->GetBlackBoard()->m_food.size();

}

void VillegerUtility::CalculateFight()
{
	m_fight = 0;

	//if there are no murders we dont bother
	if (m_myEntity->GetBlackBoard()->m_murders.size() <= 0)
	{
		return;
	}

	Vector2 pos = m_myEntity->GetPos();
	
	//find how many friendlys are near us and add 10 to fight chance for every one
	for each (Entity * unit in m_myEntity->GetBlackBoard()->m_entites)
	{
		if ((sprMagnatude((unit->GetPos() - pos)) < (m_checkRadius * m_checkRadius)) && *m_myEntity != unit)
		{
			if (PATH_FINDER->LineCheck(pos, unit->GetPos()) == false)
			{
				m_fight += 10;
			}
		}
	}

	//decrease our willingness depending on how hungery we are
	m_fight -= m_myEntity->m_maxFood - m_myEntity->m_food;
}

void VillegerUtility::CalculateFlee()
{
	m_flee = 0;

	//how much health we have the less the more we want to flee
	m_flee = m_myEntity->m_maxHealth - m_myEntity->m_health;
}

float VillegerUtility::sprMagnatude(Vector2 pos)
{
	return ((pos.x * pos.x) + (pos.y * pos.y));
}