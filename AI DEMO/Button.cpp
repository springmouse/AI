#include "Button.h"
#include <Input.h>
#include "MouseState.h"



Button::Button(int x, int y, int width, int height)
{
    m_rect.left = x;
    m_rect.top  = y;
    m_rect.right = x + width;
    m_rect.bottom = y + height;

    m_state = States::Normal;
    m_prevState = States::Normal;

}


Button::~Button()
{
}


void Button::update(float deltaTime)
{
    
    


    // m_texNormal.get(); returns the oringinal pointer if you need it.
    
    if (m_state == States::Disabled)
    {
        m_prevState = m_state;
        return;
    }


    if (PtInRect(&m_rect, MOUSE->mousePosGUI)) // true if mouse inside the button's rect
    {
        MOUSE->mousestate = MouseState::States::GUI;

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

    width = (m_rect.left - m_rect.right) * 0.45;
    height = (m_rect.top - m_rect.bottom) * 1.45;;
    

    switch (m_state)
    {
    case States::Normal:
        if (m_texNormal)
        {
            renderer->drawSprite(m_texNormal.get(), m_rect.left - height, m_rect.bottom + width);
        }
        break;

    case States::Pressed:
        if (m_texPressed)
        {
            renderer->drawSprite(m_texPressed.get(), m_rect.left - height, m_rect.bottom + width);
        }
        break;

    case States::Disabled:
        if (m_texDisabled)
        {
            renderer->drawSprite(m_texDisabled.get(), m_rect.left - height, m_rect.bottom + width);
        }
        break;

    case States::MouseOver:
        if (m_texMouseOver)
        {
            renderer->drawSprite(m_texMouseOver.get(), m_rect.left - height, m_rect.bottom + width);
        }
        break;
    }

}

void Button::setTextures(const std::string filePaths[])
{
    //if (m_texNormal != nullptr)
    //{
    //    delete m_texNormal;
    //}
    //m_texNormal = new aie::Texture(filePaths[0].c_str());

    m_texNormal    = TexturePtr(new aie::Texture(filePaths[0].c_str())); // Assign a new unique pointer to 'm_texNormal'
    m_texPressed   = TexturePtr(new aie::Texture(filePaths[1].c_str())); // Assign a new unique pointer to 'm_texNormal'
    m_texDisabled  = TexturePtr(new aie::Texture(filePaths[2].c_str())); // Assign a new unique pointer to 'm_texNormal'
    m_texMouseOver = TexturePtr(new aie::Texture(filePaths[3].c_str())); // Assign a new unique pointer to 'm_texNormal'



}

void Button::connect(myFUNC_0(void) funcClicked)
{
    m_funcClicked = funcClicked;
}

/***************************************************************************************

struct Foo
{
int i;

void saySomething(const std::string & something)
{
int zz = 0;

}

int add(int num1, int num2)
{
return num1 + num2;
}
};


Foo f1;
button.connect(myBIND_0(Foo::saySomething, f1));

Foo f1, f2;

f1.i = 1;
f2.i = 2;

// OR...

myFUNC_1(void, std::string) theFunc = myBIND_1(Foo::saySomething, f1);
theFunc("Hello");

theFunc = myBIND_1(Foo::saySomething, f2);
theFunc("World");

myFUNC_2(int, int, int) theFunc2 = myBIND_2(Foo::add, f1);
int total = theFunc2(3, 5);
***************************************************************************************/

