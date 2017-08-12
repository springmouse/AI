#pragma once
#include "Object.h"
#include <list>
#include "NavMeshNode.h"

class VillagerBlackBoard;
class VillegerUtility;
class EntityStateMachine;

enum eEntityTyes
{
    VILLAGER
};

class Entity :
    public Object
{
protected:

public:
    Entity();
    ~Entity();

    void Update(float delatTime) {};

    void Draw(aie::Renderer2D * renderer) {};

	bool operator==(Entity * other);
	bool operator!=(Entity * other);

	virtual VillagerBlackBoard * GetBlackBoard() =0;

	virtual VillegerUtility * GetUtility() = 0;

	virtual EntityStateMachine * GetStateMachine() = 0;

	void TakeDamage(float damage);

	bool IsAlive();

    float m_health;
	float m_maxHealth;

	float m_food;
	float m_maxFood;
	float m_foodDecay;

	float m_moveSpeed;
	float m_attack;
	float m_attackSpeed;
	float m_attckCoolDown;

	Entity * m_attackTarget;

	float m_updatePathTimer;

    Vector2 m_target;

    std::list<Vector2> m_path;

	float m_colourChangeTimer;

	float m_colour;

	bool m_murder;



#pragma region murder
	float m_murderHealth;
	float m_maxMurderHealth;

	float m_murderMoveSpeed;
	float m_murderAttack;
	float m_murderAttackSpeed;

	Entity * m_murderTarget;
#pragma endregion

};

