#include "MouseState.h"
#include <Input.h>



MouseState * MouseState::GetInstanceOfMouseState()
{
    static MouseState ms;
    return &ms;
}

void MouseState::Update(float deltaTime)
{
    mousePosGameSpace = Vector2((int)AIEINPUT->getMouseX(), (int)AIEINPUT->getMouseY());
    mousePosGameSpace *= 0.05f;
    mousePosGameSpace = Vector2((int)mousePosGameSpace.x, (int)mousePosGameSpace.y);
    mousePosGameSpace *= 20;

    mousePosGameSpace.y -= 20;

    mousePosGUI.x = AIEINPUT->getMouseX();
    mousePosGUI.y = AIEINPUT->getMouseY();
}

MouseState::MouseState()
{
}


MouseState::~MouseState()
{
}
