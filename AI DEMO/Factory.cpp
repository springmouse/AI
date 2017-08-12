#include "Factory.h"
#include "MoveState.h"
#include "Villager.h"
#include "LimitedFood.h"
#include "InfiniteFood.h"



Factory::Factory()
{
}


Factory::~Factory()
{
}

//returns a pointer to a static factory 
//this helps to ensure that there can only be one factory instance
Factory * Factory::GetInstanceOfFactory()
{
    static Factory factory;

    return & factory;
}

//this makes a new GameState to pass out
GameStates * Factory::MakeState(eGameStateType type)
{
    GameStates * p = nullptr;

    switch (type)
    {
    case eGameStateType::MENU:
        p = new MenuState;
        break;

    case eGameStateType::INGAME:
        p = new InGameState;
        break;

    case eGameStateType::FLOCKING:
        p = new InGameFlockStake;
        break;

    default:
        assert(false && "Factory was passed an invalid Game State type to try and create or type does not yet exist in factory.");
        break;
    }

    return p;
}

Entity * Factory::MakeEntity(eEntityTyes type, Vector2 pos, VillagerBlackBoard * blackBoard)
{
    switch (type)
    {
    case VILLAGER:
        return new Villager(pos, blackBoard);
    default:
        return nullptr;
    }

}

EntityStates * Factory::MakeEntityState(eEntityStateType type, Entity * unit)
{
    switch (type)
    {
    case MOVE:
        return new MoveState(unit);

    default:
        return nullptr;
    }
}

SharedFoodPtr Factory::MakeFood(eFoodTypes type, Vector2 pos)
{
	switch (type)
	{
	case FOOD_LIMITED:
		return SharedFoodPtr(new LimitedFood(pos));
	case FOOD_INFINITE:
		return SharedFoodPtr(new InfiniteFood(pos));
	}
}
