#pragma once
#include "Entity.h"

class PlayerUnitDecsisionTree;
class EntityStateMachine;
class VillegerUtility;
class VillagerBlackBoard;

class Villager :
    public Entity
{

public:
    Villager(VillagerBlackBoard * blackBoard);
    Villager(Vector2 pos, VillagerBlackBoard * blackBoard);
    ~Villager();

    void Update(float deltaTime);
    void Draw(aie::Renderer2D * renderer);

	VillagerBlackBoard * GetBlackBoard();
	VillegerUtility * GetUtility();
	EntityStateMachine * GetStateMachine();

	void ConsumeHunger(float DeltaTime);

private:

    PlayerUnitDecsisionTree * m_decsisionTree;
    EntityStateMachine * m_stateMachine;
	VillegerUtility * m_utility;
	VillagerBlackBoard * m_blackBoard;
};

