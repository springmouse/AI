#pragma once
#include "TypesAndDefines.h"
#include <list>

class Entity;	/*forward declaration of Entity to avoid circulare depandances*/
class Food;		/*forward declaration of Food to avoid circulare depandances*/

/*
* Class: VillagerBlackBoard
* -------------------------
*
* the Villiger black board holds information about the world 
* important for the entities in the world to know about
*
* Author: Callum Dunstone
*/
class VillagerBlackBoard
{
public:

	/*
	* Function: Constructor
	* ---------------------
	*
	* Default constructor, it does nothing.
	*
	*/
	VillagerBlackBoard();

	/*
	* Function: DeConstructor
	* ---------------------
	*
	* Default deConstructor, it does nothing.
	*
	*/
	~VillagerBlackBoard();

	std::list<SharedFoodPtr> m_food;	/*List of all the food in the world*/
	std::list<Entity *> m_entites;		/*List of all the entites in the world*/
	std::list<Entity *> m_murders;		/*List of all the murders in the world*/
};

