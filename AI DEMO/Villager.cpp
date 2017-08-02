#include "Villager.h"
#include "PlayerUnitDecsisionTree.h"
#include "EntityStateMachine.h"
#include "NavManager.h"
#include "Factory.h"



Villager::Villager()
{
    m_decsisionTree = new PlayerUnitDecsisionTree(this);
    m_health = 10;
    m_pos = Vector2(0,0);

    m_stateMachine = new EntityStateMachine(this);
    m_stateMachine->registerState(FACTORY->MakeEntityState(eEntityStateType::MOVE, this));
    m_stateMachine->pushState(0);

    m_path.clear();

	m_colourChangeTimer = 0;
	m_colour = 1;
}

Villager::Villager(Vector2 pos)
{
    m_decsisionTree = new PlayerUnitDecsisionTree(this);
    m_health = 10;
    m_pos = pos;

    m_stateMachine = new EntityStateMachine(this);
    m_stateMachine->registerState(FACTORY->MakeEntityState(eEntityStateType::MOVE, this));
    m_stateMachine->pushState(0);

    m_path.clear();

	m_colourChangeTimer = 0;
	m_colour = 1;
}


Villager::~Villager()
{

}

void Villager::Update(float deltaTime)
{
    if (m_currLocation == nullptr)
    {
        m_currLocation = NAVMANAGER->GetNode(m_pos);
        m_previousLocation = m_currLocation;

        if (m_currLocation == nullptr)
        {
            GetPos() = NAVMANAGER->g_NavNodes.front()->GetCenter();
            m_currLocation = NAVMANAGER->g_NavNodes.front();
        }

        m_currLocation->ModifyWeightCost(1);
    }

    m_decsisionTree->Update();
    m_stateMachine->Update(deltaTime);

	m_colourChangeTimer += deltaTime;
}

void Villager::Draw(aie::Renderer2D * renderer)
{
	if (m_colourChangeTimer >= 0.25f)
	{
		m_colour = rand() % 50;
		m_colour *= 0.01f;

	    m_colour += 0.5f;
	}

    renderer->setRenderColour(m_colour, m_colour, 0, 1);
    renderer->drawCircle(m_pos.x, m_pos.y, 5);
    renderer->setRenderColour(1, 1, 1, 1);
}
