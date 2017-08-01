#pragma once
#include <Vector2.h>
#include <Renderer2D.h>

class Object
{
protected:
    
    virtual void Update(float deltaTime) {};

    virtual void Draw(aie::Renderer2D * m_2dRenderer) {};

    Vector2 m_pos;
    

public:

    Vector2 GetPos() { return m_pos; };

    Object();
    ~Object();
};

