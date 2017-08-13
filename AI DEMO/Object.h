#pragma once
#include <Vector2.h>
#include <Renderer2D.h>
#include "TypesAndDefines.h"

/*
* Class:
* ------
*
* this is the base class for basically everything that will
* exist in world space and in the game
*
* Author: Callum Dunstone
*/
class Object
{
protected:
    
	/*
	* Function: Update
	* ----------------
	*
	* update loop for the object
	*
	* Parameters: float deltaTime so we have the deltaTime
	*
	* returns: returns nothing as it is a void function
	*/
    virtual void Update(float deltaTime) {};

	/*
	* Function: Draw
	* --------------
	*
	* this draws out the object
	*
	* Parameters: aie::Renderer2D * renderer so that we can render things out
	*
	* returns: returns nothing as it is a void function
	*/
    virtual void Draw(aie::Renderer2D * m_2dRenderer) {};

    Vector2 m_pos; /*objects position in space*/
    

public:

	/*
	* Function: Constructor
	* ---------------------
	*
	* Default constructor
	*
	*/
    Object();

	/*
	* Function: DeConstructer
	* ------------------------
	*
	* Default deConstructor.
	*
	*/
    ~Object();

	/*
	* Function:
	* ---------
	*
	* changes the objects position in world space with the vecotr passed in
	*
	* Parameters: Vector2 pos
	*
	* returns: returns nothing as it is a void function
	*/
	void UpdatePos(Vector2 pos) { m_pos += pos; };

	/*
	* Function:
	* ---------
	*
	* get the objects position in world space
	*
	* Parameters: none
	*
	* returns: returns Vector2 of m_pos
	*/
	Vector2 GetPos() { return m_pos; };


};

