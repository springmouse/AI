#pragma once
#include "EntityStates.h"

/*
* Class:
* ------
*
* used to make the entity it belongs to Gather food
* if it is in range and cabable of doing so
* inhearits from EntityStates
*
* Author: Callum Dunstone
*/
class GatherState :
	public EntityStates
{
public:

	/*
	* Function: Constructor
	* ---------------------
	*
	* the constructor takes in an entity pointer to the
	* entity that owns it
	*
	*/
	GatherState(Entity * unit);

	/*
	* Function: DeConstructer
	* ------------------------
	*
	* Default deConstructor.
	*
	*/
	~GatherState();

	/*
	* Function:
	* ---------
	*
	* the update loop used to exacute the 
	* gather state and gather food
	*
	* Parameters: float delta time to get the delta time if needed
	*
	* returns: returns nothing as it is a void function
	*/
	void onUpdate(float deltaTime);
};

