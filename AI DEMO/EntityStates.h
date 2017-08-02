#pragma once 


class Entity;

/*
* enum for all the game state types
*/
    enum eEntityStateType
{
    MOVE
};

class EntityStates
{
public:

    /*
    * Function: Constructor
    * ---------------------
    *
    * Default constructor, it does nothing.
    *
    */
    EntityStates() {};

    /*
    * Function: Constructor
    * ---------------------
    *
    * Default constructor, it does nothing.
    *
    */
    virtual ~EntityStates() {};

    /*
    * Function: isActive
    * ------------------
    *
    * this retunrs if the gamestate is active or not
    *
    * Parameters: this takes no parameters
    *
    * returns: returns the active state of the state
    */
    bool isActive() const { return m_active; };

    /*
    * Function: enter
    * ---------------
    *
    * this gets called when the state gets added to the stack
    *
    * Parameters: this takes no parameters
    *
    * returns: nothing
    */
    void enter() { m_active = true; onEnter(); };

    /*
    * Function: exit
    * --------------
    *
    * this gets called when the state gets removed from the stack
    *
    * Parameters: this takes no parameters
    *
    * returns: nothing
    */
    void exit() { m_active = false; onExit(); };

    /*
    * Function: onPushed
    * ------------------
    *
    * this gets called when the stack gets pushed on to the stack
    *
    * Parameters: this takes no parameters
    *
    * returns: nothing
    */
    virtual void onPushed() {};

    /*
    * Function: onPushed
    * ------------------
    *
    * this gets called when the stack gets poped off the stack
    *
    * Parameters: this takes no parameters
    *
    * returns: nothing
    */
    virtual void onPopped() {};

    /*
    * Function: onUpdate
    * ------------------
    *
    * this gets called when we want to update the state
    *
    * Parameters: this takes in a float delta time to be used to update things
    *
    * returns: nothing
    */
    virtual void onUpdate(float deltaTime) = 0;

protected:

    /*
    * Function: onDraw
    * ----------------
    *
    * this gets called when we enter the state into use
    *
    * Parameters: is void
    *
    * returns: returns the active state of the state
    */
    virtual void onEnter() {};

    /*
    * Function: onExit
    * ----------------
    *
    * this gets called when we take the state out of use
    *
    * Parameters: is void
    *
    * returns: returns the active state of the state
    */
    virtual void onExit() {};


    bool m_active = false; /*state meant to see if the state is active or not*/
    Entity * m_myEntity; /*the entity that this state manager belongs to*/
};
