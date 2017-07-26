#pragma once
#include <Windows.h>
#include <Texture.h>
#include <Renderer2D.h>
#include <string>   
#include <memory> // For all smart pointers
#include <functional>
#include "TypesAndDefines.h"

// All coordinates have the origin at top-left (i.e. same as Windows)
class Button
{
public:

    typedef std::shared_ptr<Button> SharedPtr;

    enum class States {Normal, Pressed, Disabled, MouseOver};

    Button() {};

    Button(int x, int y, int width, int height, std::string text, aie::Font * font);

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

    std::string m_text;

    aie::Font * m_font;

    myFUNC_0(void) m_funcClicked;

    typedef std::unique_ptr<aie::Texture> TexturePtr;

    TexturePtr m_texNormal;
    TexturePtr m_texPressed;
    TexturePtr m_texMouseOver;
    TexturePtr m_texDisabled;

};

