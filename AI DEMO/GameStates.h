#pragma once
#include "Font.h"
#include "Renderer2D.h"
#include "Button.h"

#include "Entity.h"
#include "Food.h"
#include "BoidsBlackBoard.h"
#include "VillagerBlackBoard.h"

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

/*
* Class: InGameFlockStake
* -----------------------
*
* this runs the flocking simulation
* inherits from GameStates
*
* Author: Callum Dunstone
*/

class InGameFlockStake :
    public GameStates
{
public:

	/*
	* Function: Constructor
	* ---------------------
	*
	* Default constructor
	*
	*/
    InGameFlockStake();

	/*
	* Function: DeConstructer
	* ------------------------
	*
	* Default deConstructor.
	*
	*/
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

    BoidsBlackBoard * m_boidsBlackBoard; /*the black board for the boids*/
    std::list<ShareBoidPtr> m_boids; /*list of all the boids*/
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
    void onEnter();

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
	* Function: ButtonAssignBuildMode
	* -------------------------------
	*
	* assigns the function NAVMANAGER->CreatNewNode() to the button to assign to the left mouse click
	* when we select the button this function is assigned to
	*
	* Parameters: none
	*
	* returns: returns nothing as it is a void function
	*/
    void ButtonAssignBuildMode();

	/*
	* Function: ButtonAssignDestroyMode
	* ---------------------------------
	*
	* assigns the function NAVMANAGER->DestroyNode() to the button to assign to the left mouse click
	* when we select the button this function is assigned to
	*
	* Parameters: none
	*
	* returns: returns nothing as it is a void function
	*/
    void ButtonAssignDestroyMode();

	/*
	* Function: ButtonAssignLimitedFood
	* ---------------------------------
	*
	* assigns the function CreatLimitedFood() to the button to assign to the left mouse click
	* when we select the button this function is assigned to
	*
	* Parameters: none
	*
	* returns: returns nothing as it is a void function
	*/
	void ButtonAssignLimitedFood();

	/*
	* Function: ButtonAssignInfiniteFood
	* ----------------------------------
	*
	* assigns the function CreatInfiniteFood() to the button to assign to the left mouse click
	* when we select the button this function is assigned to
	*
	* Parameters: none
	*
	* returns: returns nothing as it is a void function
	*/
	void ButtonAssignInfiniteFood();

	/*
	* Function: CreatLimitedFood
	* --------------------------
	*
	* this places down a limited food supply into the world
	*
	* Parameters: none
	*
	* returns: returns nothing as it is a void function
	*/
	void CreatLimitedFood();

	/*
	* Function:
	* ---------
	*
	* this places down an infinte food supply into the world
	*
	* Parameters: none
	*
	* returns: returns nothing as it is a void function
	*/
	void CreatInfiniteFood();

	/*
	* Function:
	* ---------
	*
	* this checks if the tile the food was on is gone or if the limited
	* food has run out of stockpile and if so removes them from the game
	*
	* Parameters: none
	*
	* returns: returns nothing as it is a void function
	*/
	void CheckToRemoveFood();

	/*
	* Function:
	* ---------
	*
	* this checks to see if any units have died and removes them
	*
	* Parameters: none
	*
	* returns: returns nothing as it is a void function
	*/
	void CheckUnitsToRemove();

	/*
	* Function:
	* ---------
	*
	* this finds all the murders in m_units and assigns them to
	* m_villigerBlackBoard->m_murders
	*
	* Parameters: none
	*
	* returns: returns nothing as it is a void function
	*/
	void GatherMurders();

private:

    std::list<Button::SharedPtr> m_buttons; /*list of all the buttons*/

    std::list<Entity *> m_units; /*list of all the units*/
	VillagerBlackBoard * m_villigerBlackBoard;  /*the villiger black board*/

	std::list<Entity *> m_unitsToRemove; /*list of all the dead units we need to purge*/

	std::list<SharedFoodPtr> m_food; /*list of all the food in the world*/
	std::list<SharedFoodPtr> m_foodToRemove; /*list of all food to remove*/

    float timmer = 0; /*a timer*/
};