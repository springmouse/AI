#pragma once
#include "Entity.h"

class PlayerUnitDecsisionTree;	/*forward declaration*/
class EntityStateMachine;		/*forward declaration*/
class VillegerUtility;			/*forward declaration*/
class VillagerBlackBoard;		/*forward declaration*/

/*
* Class:
* ------
*
* this is the villiger class used as the main entity in 
* the path finding
* inherits from Entity
*
* Author: Callum Dunstone
*/
class Villager :
    public Entity
{
public:

	/*
	* Function: Constructor
	* ---------------------
	*
	* constructor that takes in a refrence to a black board only
	*
	*/
    Villager(VillagerBlackBoard * blackBoard);

	/*
	* Function: Constructor
	* ---------------------
	*
	* constructor that takes in a refrence to a black board
	* and position for the unit
	*
	*/
    Villager(Vector2 pos, VillagerBlackBoard * blackBoard);

	/*
	* Function: DeConstructer
	* ------------------------
	*
	* Default deConstructor.
	*
	*/
    ~Villager();

	/*
	* Function: Update
	* ----------------
	*
	* update loop that goes through all the units 
	* decision makeing proceses
	*
	* Parameters: float deltaTime so we have the deltaTime
	*
	* returns: returns nothing as it is a void function
	*/
    void Update(float deltaTime);

	/*
	* Function: Draw
	* --------------
	*
	* this draws out the villiger to screen based on where 
	* it is in world spaces
	*
	* Parameters: aie::Renderer2D * renderer so that we can render things out
	*
	* returns: returns nothing as it is a void function
	*/
	void Draw(aie::Renderer2D * renderer);

	/*
	* Function: ConsumeHunger
	* -----------------------
	*
	* this reduces the villigers m_food mased on deltaTime
	* if the villiger has more then 75 m_food it heas and if it has
	* no food is slowly dies
	*
	* Parameters: float deltaTime so we have the deltaTime
	*
	* returns: returns nothing as it is a void function
	*/
	void ConsumeHunger(float DeltaTime);

	/*
	* Function: GetBlackBoard
	* -----------------------
	*
	* Gets the units Black Board
	*
	* Parameters: none
	*
	* returns: returns m_blackBoard
	*/
	VillagerBlackBoard * GetBlackBoard();		

	/*
	* Function: VillegerUtility
	* -------------------------
	*
	* Gets the units Utility
	*
	* Parameters: none
	*
	* returns: returns m_utility
	*/
	VillegerUtility * GetUtility();			

	/*
	* Function: EntityStateMachine
	* ----------------------------
	*
	* Gets the units State Machine
	*
	* Parameters: none
	*
	* returns: m_stateMachine
	*/
	EntityStateMachine * GetStateMachine();
private:

    PlayerUnitDecsisionTree * m_decsisionTree;	/*pointer to its descision tree*/
    EntityStateMachine * m_stateMachine;		/*pointer to state machine*/
	VillegerUtility * m_utility;				/*pointer to utility*/
	VillagerBlackBoard * m_blackBoard;			/*pointer to our black board*/
};

