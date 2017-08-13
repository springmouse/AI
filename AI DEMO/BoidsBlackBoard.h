#pragma once
#include "Boids.h"
#include "MouseState.h"
#include "TypesAndDefines.h"
#include <list>
#include <Vector2.h>


/*
* Class:
* ------
*
* black board for all the boids in flocking to use
* to figure out where everyone is around them and what to do
*
* Author: Callum Dunstone
*/

class BoidsBlackBoard
{
public:

	/*
	* Function: Constructor
	* ---------------------
	*
	* Default constructor, it does nothing.
	*
	*/
    BoidsBlackBoard();
	
	/*
	* Function: DeConstructer
	* ------------------------
	*
	* Default deConstructor, it does nothing.
	*
	*/
    ~BoidsBlackBoard();

	/*
	* Function: sprMagnatude
	* ----------------------
	*
	* this finds the sprMagnatude of the vector passed into it
	* mainly used for checks to see if something is with in a certin radius
	*
	* Parameters:
	*
	* returns: returns a float of the sprMagnatude from the vector passed in
	*/
    float sprMagnatude(Vector2 pos);

	/*
	* Function:
	* ---------
	*
	* this returns the center of the screen at the size it was specififed to
	* this is used in the boids flocking as a very weak seek to keep them from clumping up at the sides
	*
	* Parameters: Nnone
	*
	* returns: returns a vector2
	*/
    Vector2 GetTarget();	

    std::list<ShareBoidPtr> m_boids;	/*List of all boids in the world*/
};

