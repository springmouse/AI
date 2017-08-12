#pragma once
#include "Object.h"
#include <list>
#include "NavMeshNode.h"

class VillagerBlackBoard;

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

	virtual VillagerBlackBoard * GetBlackBoard() =0;

    float m_health;
	float m_maxHealth;

	float m_food;
	float m_maxFood;
	float m_foodDecay;

    Vector2 m_target;

    std::list<Vector2> m_path;

	float m_colourChangeTimer;

	float m_colour;

	bool m_murder;
};

