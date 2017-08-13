#pragma once
#include "GameStates.h"
#include "EntityStates.h"
#include "Boids.h"
#include "Entity.h"
#include <assert.h>
#include "Food.h"
#include "VillagerBlackBoard.h"

#define FACTORY Factory::GetInstanceOfFactory() /*lets us call and use the factory*/

/*
* class: Factory
* ----------------
*
* this class is our main gameObject in this programe
*
* Aurthor: Callum Dunstone, AIE
*/
class Factory
{
public:
    /*
    * Function: GetInstanceOfFactory
    * ------------------------------
    *
    * this function returns a static instance of a factory
    *
    * Parameters: it takes no parameters
    *
    * returns: a static pointer to a factory
    */
    static Factory * GetInstanceOfFactory();

	/*
	* Function: MakeState
	* -------------------
	*
	* this creates a state based on the enum passed in and passes it out as a GameState pointer
	*
	* Parameters: this takes a eGameStateType so we know what type of GameState to pass out
	*
	* returns: a pointer to a new gamestate
	*/
    GameStates * MakeState(eGameStateType type);
    
	/*
	* Function: MakeEntity
	* --------------------
	*
	* this creates a Entity based on the enum passed and set it up with a position and black board
	* in and passes it out as a Entity pointer
	*
	* Parameters: eEntityTyes type, Vector2 pos, VillagerBlackBoard * blackBoard
	*
	* returns: a pointer to a new Entity
	*/
    Entity * MakeEntity(eEntityTyes type, Vector2 pos, VillagerBlackBoard * blackBoard);

	/*
	* Function: MakeEntityState
	* -------------------------
	*
	* this creates a EntityStates based on the enum passed in and passes it out as a EntityStates pointer
	*
	* Parameters: eEntityStateType type, Entity * unit
	*
	* returns: a pointer to a new EntityStates
	*/
    EntityStates * MakeEntityState(eEntityStateType type, Entity * unit);

	/*
	* Function: MakeFood
	* ------------------
	*
	* this creates a SharedFoodPtr based on the enum passed in and passes it out as a SharedFoodPtr pointer
	*
	* Parameters: eFoodTypes type , Vector2 pos
	*
	* returns: a SharedFoodPtr to a new gamestate
	*/
	SharedFoodPtr MakeFood(eFoodTypes type , Vector2 pos);

private:
    /*
    * Function: Constructor
    * ---------------------
    *
    * this is the Default constructor of the game
    *
    */
    Factory();

    /*
    * Function: DeConstructor
    * -----------------------
    *
    * this is the default DeConstructor of the game
    *
    */
    ~Factory();
};

