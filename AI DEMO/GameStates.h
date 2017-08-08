#pragma once
#include "Font.h"
#include "Renderer2D.h"
#include "Button.h"

#include "Entity.h"
#include "BoidsBlackBoard.h"

#include <Vector3.h>
#include <List>

/*
* enum for all the game state types 
*/
enum eGameStateType
{
    MENU,
    INGAME,
    FLOCKING,
	Total
};

/*
* Class: GameStates
* -----------------
*
* this is the base game state that all the rest are derived from
*
* Author: Callum Dunstone
*/
class GameStates
{
public:

	/*
	* Function: Constructor
	* ---------------------
	*
	* Default constructor, it does nothing.
	*
	*/
    GameStates();

	/*
	* Function: Constructor
	* ---------------------
	*
	* Default constructor, it does nothing.
	*
	*/
    virtual ~GameStates();

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

	/*
	* Function: onDraw
	* ----------------
	*
	* this gets called when we want to draw what ever the state wants to draw on the screen
	*
	* Parameters: aie::Renderer2D * the reder so the state can render things to screen
	*	aie::Font * so we can print words to the screen
	*
	* returns: nothing
	*/
    virtual void onDraw(aie::Renderer2D*, aie::Font*) = 0;

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
};


/*
* Class: GameStates
* -----------------
*
* this is the MenuState for the game, derived from GameStates
*
* Author: Callum Dunstone
*/
class MenuState : 
    public GameStates
{
public:

	/*
	* Function: Constructor
	* ---------------------
	*
	* Default constructor, it does nothing.
	*
	*/
    MenuState();

	/*
	* Function: Constructor
	* ---------------------
	*
	* Default constructor, it does nothing.
	*
	*/
     ~MenuState();

	 /*
	 * Function: onUpdate
	 * ------------------
	 *
	 * this runs the update function to update the game
	 *
	 * Parameters: this takes in a float delta time to be used to update things
	 *
	 * returns: nothing
	 */
    void onUpdate(float deltaTime);

	/*
	* Function: onDraw
	* ----------------
	*
	* this gets called when we want to draw what ever the state wants to draw on the screen
	*
	* Parameters: aie::Renderer2D * the reder so the state can render things to screen
	*	aie::Font * so we can print words to the screen
	*
	* returns: nothing
	*/
    void onDraw(aie::Renderer2D*, aie::Font*);

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
    void onPopped();

private:



};


class InGameFlockStake :
    public GameStates
{
public:
    InGameFlockStake();
    ~InGameFlockStake();

    /*
    * Function: onUpdate
    * ------------------
    *
    * this runs the update function to update the game
    *
    * Parameters: this takes in a float delta time to be used to update things
    *
    * returns: nothing
    */
    void onUpdate(float deltaTime);

    /*
    * Function: onDraw
    * ----------------
    *
    * this gets called when we want to draw what ever the state wants to draw on the screen
    *
    * Parameters: aie::Renderer2D * the reder so the state can render things to screen
    *	aie::Font * so we can print words to the screen
    *
    * returns: nothing
    */
    void onDraw(aie::Renderer2D * m_2dRenderer, aie::Font * font);

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
    void onPopped();

private:

    BoidsBlackBoard * m_boidsBlackBoard;
    std::list<ShareBoidPtr> m_boids;
};


/*
* Class: InGameState
* ------------------
*
* this is the InGameState for the game, derived from GameStates
* it basically runs and managers the game while running
*
* Author: Callum Dunstone
*/
class InGameState :
    public GameStates
{
public:

	/*
	* Function: Constructor
	* ---------------------
	*
	* Default constructor, it does nothing.
	*
	*/
    InGameState();

	/*
	* Function: Constructor
	* ---------------------
	*
	* Default constructor, it does nothing.
	*
	*/
    ~InGameState();

    virtual void onEnter();

	/*
	* Function: onUpdate
	* ------------------
	*
	* this runs the update function to update the game
	*
	* Parameters: this takes in a float delta time to be used to update things
	*
	* returns: nothing
	*/
    void onUpdate(float deltaTime);

	/*
	* Function: onDraw
	* ----------------
	*
	* this gets called when we want to draw what ever the state wants to draw on the screen
	*
	* Parameters: aie::Renderer2D * the reder so the state can render things to screen
	*	aie::Font * so we can print words to the screen
	*
	* returns: nothing
	*/
    void onDraw(aie::Renderer2D*, aie::Font*);

    void ButtonAssignBuildMode();

    void ButtonAssignDestroyMode();

    //void SlectState();

private:

    std::list<Button::SharedPtr> m_buttons; 


    std::list<Entity *> m_units;
    float timmer = 0;
};