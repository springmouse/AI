#pragma once
#include <Vector2.h>

class Entity;  /*forward declaration of Entity*/

/*
* Class:
* ------
*
* this is the villiger Utility class used to
* evaluate what is the best course of action for us is
*
* Author: Callum Dunstone
*/
class VillegerUtility
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
	VillegerUtility(Entity * entity);

	/*
	* Function: DeConstructer
	* ------------------------
	*
	* Default deConstructor.
	*
	*/
	~VillegerUtility();

	/*
	* Function: Update
	* ----------------
	*
	* runs through the update loop of this class claculating the values
	* for the diffrent actions the entity can make
	*
	* Parameters: float deltaTime so we have access to deltaTime
	*
	* returns: returns nothing as it is a void function
	*/
	void Update(float deltaTime);

	/*
	* Function: CalculateGetFood
	* --------------------------
	*
	* this calculate the value of Getting food to see if
	* the unit should Get food based of how hungery it is
	*
	* Parameters: none
	*
	* returns: returns nothing as it is a void function
	*/
	void CalculateGetFood();

	/*
	* Function: ClaculateMurder
	* -------------------------
	*
	* this calculate the value of Murdering to see if
	* the unit should go murder its friends for food
	* based of how hunger and low on health it is
	*
	* Parameters: none
	*
	* returns: returns nothing as it is a void function
	*/
	void ClaculateMurder();

	/*
	* Function: ClaculateWander
	* -------------------------
	*
	* this calculate the value of wandering to see if
	* the unit should wander around
	*
	* Parameters: none
	*
	* returns: returns nothing as it is a void function
	*/
	void ClaculateWander();

	/*
	* Function: CalculateFight
	* ------------------------
	*
	* this calculate the value of Fighting to see if
	* the unit should Fight or not based on how many friends are near it
	*
	* Parameters: none
	*
	* returns: returns nothing as it is a void function
	*/
	void CalculateFight();

	/*
	* Function: CalculateFlee
	* -----------------------
	*
	* this calculate the value of Flee to see if
	* the unit should flee based on how low its health is
	*
	* Parameters: none
	*
	* returns: returns nothing as it is a void function
	*/
	void CalculateFlee();

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

	float m_getFood;	/*value of getting food*/
	float m_murder;		/*value of killing for food*/
	float m_wonder;		/*value of just walking around*/
	float m_fight;		/*value of fighting someone who is trying to kill you*/
	float m_flee;		/*value of running... well walking away from someone who is trying to kill you*/

private:
	Entity * m_myEntity; /*our entity we belong to*/

	float m_checkRadius; /*the radius to check around if we want to see who is near by*/
};

