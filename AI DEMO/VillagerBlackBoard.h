#pragma once
#include "TypesAndDefines.h"
#include <list>

class Entity;
class Food;

class VillagerBlackBoard
{
public:
	VillagerBlackBoard();
	~VillagerBlackBoard();

	std::list<SharedFoodPtr> m_food;
	std::list<Entity *> m_entites;
	std::list<Entity *> m_murders;
};

