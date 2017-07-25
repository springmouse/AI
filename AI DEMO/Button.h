#pragma once
#include <Windows.h>
#include <Texture.h>
#include <Renderer2D.h>
#include <string>   
#include <memory> // For all smart pointers
#include <functional>


#define myFUNC_0(ret_)              std::function<##ret_()>
#define myBIND_0(func_, object_)    std::bind(&##func_, &##object_)

#define myFUNC_1(ret_, arg_)        std::function<##ret_(##arg_)>
#define myBIND_1(func_, object_)    std::bind(&##func_, &##object_, std::placeholders::_1)

#define myFUNC_2(ret_, arg1_, arg2_)    std::function<##ret_(##arg1_, ##arg2_)>
#define myBIND_2(func_, object_)        std::bind(&##func_, &##object_, std::placeholders::_1, std::placeholders::_2)

// All coordinates have the origin at top-left (i.e. same as Windows)
class Button
{
public:

    enum class States {Normal, Pressed, Disabled, MouseOver};

    Button() {};

    Button(int x, int y, int width, int height);

    void operator=(const Button & button) 
    {
        m_rect = button.m_rect;

        m_state = States::Normal;
        m_prevState = States::Normal;
    };

    ~Button();

    // Array of textures in order: normal, pressed, disabled, mouse-over
    void setTextures(const std::string filePaths[]);

    void update(float deltaTime);

    void draw(aie::Renderer2D *renderer);

    void enable(bool isEnabled);

    void connect(myFUNC_0(void) funcClicked);

    const RECT & rect() const { return m_rect; }

private:
    RECT m_rect;

    States m_state;

    States m_prevState;

    typedef std::unique_ptr<aie::Texture> TexturePtr;


    myFUNC_0(void) m_funcClicked;

    TexturePtr m_texNormal;
    TexturePtr m_texPressed;
    TexturePtr m_texMouseOver;
    TexturePtr m_texDisabled;

};

