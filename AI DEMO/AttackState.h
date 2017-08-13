#pragma once
#include "EntityStates.h"

/*
* Class:
* ------
*
* used to make the entity it belongs to Attack
* any filth murderes near it assuming it has the health
* inhearits from EntityStates
*
* Author: Callum Dunstone
*/
class AttackState :
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
	AttackState(Entity * unit);

	/*
	* Function: DeConstructer
	* ------------------------
	*
	* Default deConstructor.
	*
	*/
	~AttackState();

	/*
	* Function:
	* ---------
	*
	* this is the update loop for the attack state used
	* to see if there is someone within range to brutlly kill
	*
	* Parameters: float deltaTime so it has the delta time to do things
	*
	* returns: returns nothing as it is a void function
	*/
	void onUpdate(float deltaTime);
};

