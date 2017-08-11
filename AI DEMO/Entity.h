#pragma once
#include "Object.h"
#include <list>
#include "NavMeshNode.h"

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

    float m_health;

    Vector2 m_target;

    std::list<Vector2> m_path;

	float m_colourChangeTimer;

	float m_colour;
};

