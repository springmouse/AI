#pragma once
#include <Windows.h>
#include <Vector2.h>

#define MOUSE MouseState::GetInstanceOfMouseState() /*lets us call and use the factory*/

class MouseState
{
public:

    static MouseState * GetInstanceOfMouseState();

    enum class States { GUI, INGAME};
    enum class InteractType{ None, PlaceNode, DestroyNode};

    States mousestate = States::INGAME;
    InteractType interactype = InteractType::None;

    POINT mousePosGUI;
    Vector2 mousePosGameSpace;

    void Update(float deltaTime);

private:
    MouseState();
    ~MouseState();
};

