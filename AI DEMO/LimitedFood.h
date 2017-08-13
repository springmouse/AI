#pragma once
#include "Food.h"

/*
* Class: LimitedFood
* ------------------
*
* this is the limited food class that villigers will gather food from
* it inherits from food
*
* Author: Callum Dunstone
*/
class LimitedFood : 
	public Food
{
public:

	/*
	* Function: Constructor
	* ---------------------
	*
	* constructor that takes in a vector2 to set its
	* position with
	*
	*/
	LimitedFood(Vector2 pos);

	/*
	* Function: DeConstructer
	* ------------------------
	*
	* Default deConstructor.
	*
	*/
	~LimitedFood();

	/*
	* Function: Draw
	* --------------
	*
	* this draws out the limited food to the screen in world space
	*
	* Parameters: aie::Renderer2D * renderer so that we can render things out
	*
	* returns: returns nothing as it is a void function
	*/
	void Draw(aie::Renderer2D * m_2dRenderer);

	/*
	* Function:
	* ---------
	*
	* this returns 25 food to the unit that
	* gathered from it, depleting its food stores
	*
	* Parameters: none
	*
	* returns: float of the food gathered from it
	*/
	float GatherFood();

private:
};

