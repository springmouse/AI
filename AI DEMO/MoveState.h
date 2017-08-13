#pragma once
#include "EntityStates.h"
#include <Vector2.h>

/*
* Class:
* ------
*
* used to make the entity it belongs to seek
* towards a target chosen by the decision tree
* inhearits from EntityStates
*
* Author: Callum Dunstone
*/
class MoveState :
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
    MoveState(Entity * ent);

	/*
	* Function: DeConstructer
	* ------------------------
	*
	* Default deConstructor.
	*
	*/
    ~MoveState();


	/*
	* Function: onUpdate
	* ------------------
	*
	* this runs the Update loop and moves the entity to its target of choice
	*
	* Parameters: float deltaTime so we have the deltaTime
	*
	* returns: returns nothing as it is a void function
	*/
    void onUpdate(float deltaTime);
	

	/*
	* Function: sprMagnatude
	* ----------------------
	*
	* this function is used to get the sprMagnatude of a vector used for distance checks
	*
	* Parameters: vector2 so we can get its sprMagnatude
	*
	* returns: float of the sprMagnatude from the vector passed in
	*/
	float sprMagnatude(Vector2 pos);
};

