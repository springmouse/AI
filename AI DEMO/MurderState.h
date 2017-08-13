#pragma once
#include "EntityStates.h"

/*
* Class: MurderState
* ------------------
*
* this is the state used by an entity that wishes to kill all its friends
* it inherites from EntityStates
*
* Author: Callum Dunstone
*/

class MurderState :
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
	MurderState(Entity * unit);

	/*
	* Function: DeConstructer
	* ------------------------
	*
	* Default deConstructor.
	*
	*/
	~MurderState();

	/*
	* Function: onUpdate
	* ------------------
	*
	* this is the update loop to exacute the murder behaviour
	* so that the unit will go kill its buddys for food :D
	*
	* Parameters: float for the deltaTime
	*
	* returns: returns nothing as it is a void function
	*/
	void onUpdate(float deltaTime);
};

