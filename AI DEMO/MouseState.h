#pragma once
#include <Windows.h>
#include <Vector2.h>
#include <memory>
#include "TypesAndDefines.h"

#define MOUSE MouseState::GetInstanceOfMouseState() /*lets us call and use the MouseState*/

class MouseState
{
public:

    static MouseState * GetInstanceOfMouseState();

    enum class States { GUI, INGAME};

    States mousestate = States::INGAME;
    
    POINT mousePosGUI;
    Vector2 mousePosGameSpace;
    Vector2 mousePosExact;

    void connect(myFUNC_0(void) setEvent);

    void Update(float deltaTime);

    void Nothing();

private:

    myFUNC_0(void)  m_event;

    float m_timer;

    MouseState();
    ~MouseState();
};

