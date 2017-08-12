#include "EntityStateMachine.h"
#include "Entity.h"

EntityStateMachine::EntityStateMachine(Entity * entity)
{
    myEntity = entity;
    pop = false;
}


EntityStateMachine::~EntityStateMachine()
{
    //cleans up all the lists
    m_registeredStates.clear();
    m_pushedStates.clear();
    m_stateStack.clear();
}

void EntityStateMachine::pushState(int id)
{
    //adds the picked state to be pushed onto m_stateStack
    std::list<EntityStates *>::iterator it = m_registeredStates.begin();
    std::advance(it, id);

    EntityStates * holder = *it;

    m_pushedStates.push_back(holder);
}

void EntityStateMachine::Update(float deltaTime)
{
    //checks if we need to pop a state off
    while (pop)
    {
        pop = false;

        //runs the closing functions of the GameState
		m_stateToPop->exit();

		m_stateStack.remove(m_stateToPop);

		m_stateToPop->onPopped();

        //runs the enter functions for the last elemeant in the list
        if (m_stateStack.size() > 0)
        {
            m_stateStack.back()->enter();
        }
    }

    //loops throught the sataes being held in m_pushedStates
    for (auto pushedState : m_pushedStates)
    {
        //runs the exit function on the last elemeant in m_stateStack
        if (m_stateStack.size() > 0)
        {
            m_stateStack.back()->exit();
        }

        //runs the opening functions for the state just added
        pushedState->onPushed();
        m_stateStack.push_back(pushedState);
        m_stateStack.back()->enter();
    }

    //clears pushed states
    m_pushedStates.clear();

    //goes through all the states in the list and runs there update functions
    for (auto state : m_stateStack)
    {
        state->onUpdate(deltaTime);
    }

}

