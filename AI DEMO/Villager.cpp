#include "Villager.h"
#include "PlayerUnitDecsisionTree.h"
#include "EntityStateMachine.h"
#include "NavManager.h"
#include "VillegerUtility.h"
#include "VillagerBlackBoard.h"
#include "Factory.h"

#include <iostream>



Villager::Villager(VillagerBlackBoard * blackBoard)
{
    m_decsisionTree = new PlayerUnitDecsisionTree(this);
    m_health = 10;
    m_pos = NAVMANAGER->g_NavNodes.front()->GetCenter();

    m_stateMachine = new EntityStateMachine(this);
    m_stateMachine->registerState(FACTORY->MakeEntityState(eEntityStateType::MOVE, this));
	m_stateMachine->registerState(FACTORY->MakeEntityState(eEntityStateType::GATHER, this));
	m_stateMachine->registerState(FACTORY->MakeEntityState(eEntityStateType::MURDER, this));
	m_stateMachine->registerState(FACTORY->MakeEntityState(eEntityStateType::ATTACK, this));
    m_stateMachine->pushState(0);

#pragma region murder
	m_murderHealth = 200;
	m_maxMurderHealth = 200;

	m_murderMoveSpeed = 20;
	m_murderAttack = 15;
	m_murderAttackSpeed = 0.1f;

	m_murderTarget = nullptr;
#pragma endregion

	m_moveSpeed = 10;
	m_attack = 5;
	m_attackSpeed = 0.2f;

	m_attackTarget = nullptr;

	m_utility = new VillegerUtility(this);

	m_blackBoard = blackBoard;

	m_murder = false;

    m_path.clear();

	m_colourChangeTimer = 0;
	m_colour = 1;

	m_health = m_maxHealth = 100;

	m_food = m_maxFood = 100;
	m_foodDecay = 5;

	m_updatePathTimer = 0;

	m_attckCoolDown = 0;
}

Villager::Villager(Vector2 pos, VillagerBlackBoard * blackBoard)
{
    m_decsisionTree = new PlayerUnitDecsisionTree(this);
    m_health = 10;
    m_pos = pos;

    m_stateMachine = new EntityStateMachine(this);
    m_stateMachine->registerState(FACTORY->MakeEntityState(eEntityStateType::MOVE, this));
	m_stateMachine->registerState(FACTORY->MakeEntityState(eEntityStateType::GATHER, this));
	m_stateMachine->registerState(FACTORY->MakeEntityState(eEntityStateType::MURDER, this));
	m_stateMachine->registerState(FACTORY->MakeEntityState(eEntityStateType::ATTACK, this));
    m_stateMachine->pushState(0);

#pragma region murder
	m_murderHealth = 200;
	m_maxMurderHealth = 200;

	m_murderMoveSpeed = 20;
	m_murderAttack = 15;
	m_murderAttackSpeed = 0.1f;

	m_murderTarget = nullptr;
#pragma endregion

	m_moveSpeed = 10;
	m_attack = 5;
	m_attackSpeed = 0.2f;

	m_attackTarget = nullptr;

	m_utility = new VillegerUtility(this);

	m_blackBoard = blackBoard;

	m_murder = false;

    m_path.clear();

	m_colourChangeTimer = 0;
	m_colour = 1;

	m_food = m_maxFood = 100;
	m_foodDecay = 5;

	m_health = m_maxHealth = 100;

	m_updatePathTimer = 0;

	m_attckCoolDown = 0;
}


Villager::~Villager()
{
	delete m_decsisionTree;
	delete m_stateMachine;
	delete m_utility;
	delete m_blackBoard;
}

void Villager::Update(float deltaTime)
{
	m_updatePathTimer += deltaTime;
	m_attckCoolDown += deltaTime;

    m_decsisionTree->Update();
    m_stateMachine->Update(deltaTime);
	m_utility->Update(deltaTime);

	m_colourChangeTimer += deltaTime;

	ConsumeHunger(deltaTime);
}

void Villager::Draw(aie::Renderer2D * renderer)
{
	if (m_colourChangeTimer >= 0.25f)
	{
		m_colour = rand() % 50;
		m_colour *= 0.01f;

	    m_colour += 0.5f;
	}

	/*Vector2 holder = m_pos;

	for each (Vector2 vec in m_path)
	{
		renderer->setRenderColour(0.5, 1, 0, 1);
		renderer->drawLine(holder.x, holder.y, vec.x, vec.y);
		holder = vec;
	}*/

	if (m_murder)
	{
		renderer->setRenderColour(1, 0, 0, 1);
	}
	else
	{
		renderer->setRenderColour(m_colour, m_colour, 0, 1);
	}

	renderer->drawCircle(m_pos.x, m_pos.y, 5);
    renderer->setRenderColour(1, 1, 1, 1);
}

VillagerBlackBoard * Villager::GetBlackBoard()
{
	return m_blackBoard;
}

VillegerUtility * Villager::GetUtility()
{
	return m_utility;
}

EntityStateMachine * Villager::GetStateMachine()
{
	return m_stateMachine;
}

void Villager::ConsumeHunger(float DeltaTime)
{
	if (m_food > m_maxFood)
	{
		m_food = m_maxFood;
	}

	if (m_food > 0)
	{
		m_food -= m_foodDecay * DeltaTime;
	}
	else
	{
		m_food = 0;
	}

	if (m_food > 75)
	{
		if (m_murder)
		{
			m_murderHealth += (m_foodDecay * DeltaTime) * 0.5;
			m_food -= m_foodDecay * DeltaTime;
		}
		else
		{
			m_health += (m_foodDecay * DeltaTime) * 0.5;
			m_food -= m_foodDecay * DeltaTime;
		}
	}

	if (m_food <= 0)
	{
		if (m_murder)
		{
			m_murderHealth -= m_foodDecay * DeltaTime;
		}
		else
		{
			m_health -= m_foodDecay * DeltaTime;
		}
	}
}
