#include "MouseState.h"
#include <Input.h>



MouseState * MouseState::GetInstanceOfMouseState()
{
    static MouseState ms;
    return &ms;
}

void MouseState::connect(myFUNC_0(void) setEvent)
{
    m_event = setEvent;
}

void MouseState::Update(float deltaTime)
{
    mousePosGameSpace = Vector2((int)AIEINPUT->getMouseX(), (int)AIEINPUT->getMouseY());
    mousePosGameSpace *= 0.05f;
    mousePosGameSpace = Vector2((int)mousePosGameSpace.x, (int)mousePosGameSpace.y);
    mousePosGameSpace *= 20;

    mousePosGameSpace.y -= 30;
    mousePosGameSpace.x -= 10;

    mousePosGUI.x = AIEINPUT->getMouseX();
    mousePosGUI.y = AIEINPUT->getMouseY();

    m_timer += deltaTime;

    if (mousestate == States::INGAME && AIEINPUT->isMouseButtonDown(0) && m_timer > 0.01f)
    {
        m_event();
        m_timer = 0;
    }

}

void MouseState::Nothing()
{
}



MouseState::MouseState()
{
    m_timer = 0;
    m_event = myBIND_0(MouseState::Nothing, this);
}


MouseState::~MouseState()
{
}
