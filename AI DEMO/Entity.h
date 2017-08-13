#pragma once
#include "Object.h"
#include <list>
#include "NavMeshNode.h"

class VillagerBlackBoard;	/*foreward declaration*/
class VillegerUtility;		/*foreward declaration*/
class EntityStateMachine;	/*foreward declaration*/

//enum of all the classes that inherit from this one
enum eEntityTyes
{
    VILLAGER
};

/*
* Class: Entity
* -------------
*
* this is the entity class 
*
* Author: Callum Dunstone
*/
class Entity :
    public Object
{
protected:

public:

	/*
	* Function: Constructor
	* ---------------------
	*
	* Default constructor
	*
	*/
    Entity();

	/*
	* Function: DeConstructer
	* ------------------------
	*
	* Default deConstructor.
	*
	*/
    ~Entity();

	/*
	* Function: Update
	* ----------------
	*
	* update loop for the entity
	*
	* Parameters: float deltaTime so we have the deltaTime
	*
	* returns: returns nothing as it is a void function
	*/
    void Update(float delatTime) {};

	/*
	* Function: Draw
	* --------------
	*
	* this draws out the Entity to screen based on where
	* it is in world spaces
	*
	* Parameters: aie::Renderer2D * renderer so that we can render things out
	*
	* returns: returns nothing as it is a void function
	*/
    void Draw(aie::Renderer2D * renderer) {};

	/*
	* operator==(Entity * other)
	* --------------------------
	*
	* checks if two units are the same by checking there position in world space
	*
	*/
	bool operator==(Entity * other);

	/*
	* operator!=(Entity * other)
	* --------------------------
	*
	* checks if two units are not the same by checking there position in world space
	*
	*/
	bool operator!=(Entity * other);

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
	virtual VillagerBlackBoard * GetBlackBoard() =0;

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
	virtual VillegerUtility * GetUtility() = 0;

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
	virtual EntityStateMachine * GetStateMachine() = 0;

	/*
	* Function: TakeDamage
	* --------------------
	*
	* deals damage to the entitys health on how much is passed in
	*
	* Parameters: float damage amount of damage the unit will take
	*
	* returns: returns nothing as it is a void function
	*/
	void TakeDamage(float damage);

	/*
	* Function: IsAlive
	* -----------------
	*
	* checks to see if the entity health is greater then 0 and it is not dead
	*
	* Parameters: none
	*
	* returns: returns true if health > 0 else false
	*/
	bool IsAlive();

	/////////////////////////////////////////////////////////////

    float m_health;			/*units current health*/
	float m_maxHealth;		/*units max health*/

	float m_food;			/*how much food it has*/
	float m_maxFood;		/*its max food*/
	float m_foodDecay;		/*how quickly it loses food*/

	float m_moveSpeed;		/*its move speed*/
	float m_attack;			/*attack value*/
	float m_attackSpeed;	/*how quickly it can attack*/
	float m_attckCoolDown;	/*timer for when it can attack again*/

	Entity * m_attackTarget;	/*murder to hunt down and kill*/

	float m_updatePathTimer;	/*timer for when we need to update the path*/

    Vector2 m_target;			/*generic move to this position target*/
	WeakFoodPtr m_neareastFood;	/*pointer to the nearest food to the unit*/

    std::list<Vector2> m_path;	/*units current path*/

	float m_colourChangeTimer;	/*timer for when to change to a diffrent shade of yellow*/

	float m_colour;				/*current shade of yellow*/

	bool m_murder;				/*are we a murder or not*/



#pragma region murder
	float m_murderHealth;		/*murderers health*/
	float m_maxMurderHealth;	/*murders max health*/

	float m_murderMoveSpeed;	/*murders movmeant speed*/
	float m_murderAttack;		/*murders attack value*/
	float m_murderAttackSpeed;	/*murder attack speed*/

	Entity * m_murderTarget;	/*target to murder*/
#pragma endregion

};

