#pragma once
#include "Object.h"

//the diffrent types of food there is
enum eFoodTypes
{
	FOOD_LIMITED,
	FOOD_INFINITE
};

/*
* Class:
* ------
*
* this is the base food class
* it inherits from Object
*
* Author: Callum Dunstone
*/
class Food :
	public Object
{
public:

	/*
	* Function: Constructor
	* ---------------------
	*
	* Default constructor
	*
	*/
	Food();

	/*
	* Function: DeConstructer
	* ------------------------
	*
	* Default deConstructor.
	*
	*/
	~Food();

	/*
	* Function: GatherFood
	* --------------------
	*
	* this is a pure virtual function this will return food to the unit 
	* that requested it from classes that inherit from food
	*
	* Parameters: none
	*
	* returns: returns float of food gather from it
	*/
	virtual float GatherFood() = 0;

	/*
	* Function:
	* ---------
	*
	* this checks to see if there is still a tile under it or not
	*
	* Parameters: none
	*
	* returns: returns bool, true if tile still exists under it, flase if not
	*/
	bool CheckIFPosValid();

	/*
	* Function: Draw
	* --------------
	*
	* this draws out the food to the world
	*
	* Parameters: aie::Renderer2D * renderer so that we can render things out
	*
	* returns: returns nothing as it is a void function
	*/
	virtual void Draw(aie::Renderer2D * m_2dRenderer) {};

	/*
	* Function: IsFoodLeft
	* --------------------
	*
	* checks if there is food still left in the stock pile
	*
	* Parameters: none
	*
	* returns: returns bool, true if food > 0, flase if not
	*/
	bool IsFoodLeft();

protected:
	float m_foodStock; /*how much food is stocked in the food entity*/
};

