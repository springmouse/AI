#pragma once
#include "EntityStates.h"
#include <List>

class Entity;

class EntityStateMachine
{
public:

    /*
    * Function: Constructor
    * ---------------------
    *
    * Default constructor, it does nothing.
    *
    */
    EntityStateMachine(Entity * entity);

    /*
    * Function: Constructor
    * ---------------------
    *
    * Default constructor, it does nothing.
    *
    */
    virtual  ~EntityStateMachine();

    /*
    * Function: registerState
    * -----------------------
    *
    * this adds the state passed into it, in to the m_registeredStates so that they can be easily called and accessed
    *
    * Parameters: this takes in a GameState pointer that will be added to the m_registeredStates
    *
    * returns: returns nothing as it is a null function
    */
    void registerState(EntityStates * state) { m_registeredStates.push_back(state); };

    /*
    * Function: pushState
    * -------------------
    *
    * this adds the state passed into it, in to the m_registeredStates so that they can be easily called and accessed
    *
    * Parameters: this takes in a GameState pointer that will be added to the m_registeredStates
    *
    * returns: returns nothing as it is a null function
    */
    void pushState(int id);

    /*
    * Function: Update
    * ----------------
    *
    * this will pop and push states properly and run the game states update funtions
    *
    * Parameters: this takes in float deltaTime to be passed into the game states
    *
    * returns: returns nothing as it is a void function
    */
    void Update(float deltaTime);

    /*
    * Function: ActiveStateCount
    * --------------------------
    *
    * this returns how many states are currently active or about to be active
    *
    * Parameters: this takes in no parameters
    *
    * returns: returns an int of m_stateStack + m_pushedStates combined leangths
    */
    int ActiveStateCount() { return (m_stateStack.size() + m_pushedStates.size()); };

    /*
    * Function: GetState
    * ------------------
    *
    * this gets a state from the m_registeredStates mainly to be
    * used to push the state on to m_pushedStates so it can be added to m_stateStack
    *
    * Parameters: this takes in an int to get the state from a certin location of m_registeredStates
    *
    * returns: GameStates pointer to a state being held in m_registeredStates
    */
    EntityStates * GetState(int id)
    {
        std::list<EntityStates *>::iterator it = m_registeredStates.begin();
        std::advance(it, id);

        return *it;

    };

    bool pop;

protected:
    std::list<EntityStates *> m_pushedStates; /*the states to be pushed onto m_stateStack*/

    std::list<EntityStates *> m_stateStack; /*holds all states currently in use*/
    std::list<EntityStates *> m_registeredStates; /*holds all states that can be used*/

    Entity * myEntity;
};

