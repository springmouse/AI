#pragma once
#include "Entity.h"

class PlayerUnitDecsisionTree;



class Villager :
    public Entity
{

public:
    Villager();
    Villager(Vector2 pos);
    ~Villager();

    void Update(float deltaTime);
    void Draw(aie::Renderer2D * renderer);

private:

    PlayerUnitDecsisionTree * m_decsisionTree;

};

