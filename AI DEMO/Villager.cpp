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
}

void Villager::Draw(aie::Renderer2D * renderer)
{
    renderer->setRenderColour(1, 1, 0, 1);
    renderer->drawCircle(m_pos.x, m_pos.y, 5);
    renderer->setRenderColour(1, 1, 1, 1);
}
