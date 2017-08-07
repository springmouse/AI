#pragma once
#include <Vector2.h>
#include <Renderer2D.h>
#include "TypesAndDefines.h"

class Object
{
protected:
    
    virtual void Update(float deltaTime) {};

    virtual void Draw(aie::Renderer2D * m_2dRenderer) {};

    Vector2 m_pos;
    

public:

    void UpdatePos(Vector2 pos) { m_pos += pos; };

    Vector2 GetPos() { return m_pos; };

    Object();
    ~Object();
};

