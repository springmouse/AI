#pragma once
#include <Windows.h>
#include <Vector2.h>
#include <memory>
#include "TypesAndDefines.h"

#define MOUSE MouseState::GetInstanceOfMouseState() /*lets us call and use the MouseState*/

/*
* Class:
* ------
*
* this is the mouse state used to figure out where the mouse is
* whether it is othere the gui or in world space and exacutes the functions assigned to it
* with a function pointer
*
* Author: Callum Dunstone
*/
class MouseState
{
public:

	/*
	* Function: GetInstanceOfMouseState
	* ---------------------------------
	*
	* returns a static pointer to an instance of the MouseState
	* to be used as it is a singleton class
	*
	* Parameters: none
	*
	* returns: returns static MouseState *
	*/
    static MouseState * GetInstanceOfMouseState();

	/*
	* Function: connect
	* -----------------
	*
	* this connects a function to the mouses function pointer
	*
	* Parameters: myFUNC_0(void) setEvent <- the function pointerwe will set ou function pointer to
	*
	* returns: returns nothing as it is a void function
	*/
    void connect(myFUNC_0(void) setEvent);

	/*
	* Function: Update
	* ----------------
	*
	* update loop for the mouse button
	*
	* Parameters: float deltaTime so we have the deltaTime
	*
	* returns: returns nothing as it is a void function
	*/
    void Update(float deltaTime);

	/*
	* Function: Nothing
	* -----------------
	*
	* this function litteraly does nothing, i simply is.
	* m_event gets set to this when the game is first lunched
	*
	* Parameters: none
	*
	* returns: returns nothing as it is a void function
	*/
    void Nothing();

	enum class States { GUI, INGAME };	/*the mouse states it can be in*/

	States mousestate = States::INGAME;	/*the current mouse state*/

	POINT mousePosGUI;			/*the mouse position in the GUI*/
	Vector2 mousePosGameSpace;	/*the mouse position in game space wich works in multiples of 20*/

private:

    myFUNC_0(void)  m_event; /*function pointer for what the mouse is meant to do when you left click*/

    float m_timer; /*timer to moderate how quickly you can left click*/

	/*
	* Function: Constructor
	* ---------------------
	*
	* Default constructor
	*
	*/
    MouseState();

	/*
	* Function: DeConstructer
	* ------------------------
	*
	* Default deConstructor.
	*
	*/
    ~MouseState();
};

