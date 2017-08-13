#include "Button.h"
#include <Input.h>
#include "MouseState.h"



Button::Button(int x, int y, int width, int height, std::string text, aie::Font * font)
{
	//set up the rec so its in the top left cornor
    m_rect.left = x;
    m_rect.top  = y;
    m_rect.right = x + width;
    m_rect.bottom = y + height;

	//set the states
    m_state = States::Normal;
    m_prevState = States::Normal;

	//set the text and font
    m_text = text;
    m_font = font;
}


Button::~Button()
{
}


void Button::update(float deltaTime)
{
    if (m_state == States::Disabled)
    {
        m_prevState = m_state;
        return;
    }

	// true if mouse inside the button's rect
    if (PtInRect(&m_rect, MOUSE->mousePosGUI)) 
    {
		//set mouse state to gui
        MOUSE->mousestate = MouseState::States::GUI;

		//if we click set state to pressed and exacute function pointer
        if (AIEINPUT->isMouseButtonDown(0))
        {
            m_state = States::Pressed;
            if (m_prevState != States::Pressed)
            {
                if (m_funcClicked)
                {
                    m_funcClicked();
                }
            }
        }
        else
        {
            m_state = States::MouseOver;
        }
    }
    else
    {
        m_state = States::Normal;
    }

    m_prevState = m_state;
}


void Button::enable(bool isEnabled)
{
    m_state = isEnabled ? States::Normal : States::Disabled;
}


void Button::draw(aie::Renderer2D *renderer)
{
    int width, height;

	//sort of finds the middle of the button for rendering purposes
    width = (m_rect.left - m_rect.right) * 0.45;
    height = (m_rect.top - m_rect.bottom) * 1.45;;
    
    renderer->setRenderColour(1, 1, 1, 1);


	//depending on the button state render out things diffrently
    switch (m_state)
    {
    case States::Normal:
        if (m_texNormal)
        {
            renderer->drawSprite(m_texNormal.get(), m_rect.left - height, m_rect.bottom + width);
            renderer->setRenderColour(0, 0, 0, 1);
            renderer->drawText(m_font, m_text.c_str(), m_rect.left - 10, (m_rect.bottom + width)- 3);
        }
        break;

    case States::Pressed:
        if (m_texPressed)
        {
            renderer->drawSprite(m_texPressed.get(), m_rect.left - height, m_rect.bottom + width);
            renderer->setRenderColour(0, 0, 0, 1);
            renderer->drawText(m_font, m_text.c_str(), m_rect.left - 10, (m_rect.bottom + width) - 4);
        }
        break;

    case States::Disabled:
        if (m_texDisabled)
        {
            renderer->drawSprite(m_texDisabled.get(), m_rect.left - height, m_rect.bottom + width);
            renderer->setRenderColour(0, 0, 0, 1);
            renderer->drawText(m_font, m_text.c_str(), m_rect.left - 10, (m_rect.bottom + width) - 3);
        }
        break;

    case States::MouseOver:
        if (m_texMouseOver)
        {
            renderer->drawSprite(m_texMouseOver.get(), m_rect.left - height, m_rect.bottom + width);
            renderer->setRenderColour(0, 0, 0, 1);
            renderer->drawText(m_font, m_text.c_str(), m_rect.left - 10, (m_rect.bottom + width) - 3);
        }
        break;
    }

    renderer->setRenderColour(1, 1, 1, 1);

}

void Button::setTextures(const std::string filePaths[])
{
    m_texNormal    = TexturePtr(new aie::Texture(filePaths[0].c_str())); // Assign a new unique pointer to 'm_texNormal'
    m_texPressed   = TexturePtr(new aie::Texture(filePaths[1].c_str())); // Assign a new unique pointer to 'm_texPressed'
    m_texDisabled  = TexturePtr(new aie::Texture(filePaths[2].c_str())); // Assign a new unique pointer to 'm_texDisabled'
    m_texMouseOver = TexturePtr(new aie::Texture(filePaths[3].c_str())); // Assign a new unique pointer to 'm_texMouseOver'
}

void Button::connect(myFUNC_0(void) funcClicked)
{
    m_funcClicked = funcClicked;
}