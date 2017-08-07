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

    std::list<SharedMeshPtr> m_path;

    SharedMeshPtr m_currLocation;

    SharedMeshPtr m_previousLocation;

	float m_colourChangeTimer;

	float m_colour;
};

