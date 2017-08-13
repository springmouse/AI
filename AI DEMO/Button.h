#pragma once
#include <Windows.h>
#include <Texture.h>
#include <Renderer2D.h>
#include <string>   
#include <memory>
#include <functional>
#include "TypesAndDefines.h"

// All coordinates have the origin at top-left (i.e. same as Windows)

/*
* Class:
* ------
*
* this is the button clas so we have buttons
* eeeeeeeeeeeee
*
* Author: Callum Dunstone
*/
class Button
{
public:

    typedef std::shared_ptr<Button> SharedPtr; /*smart memory type for buttons*/

    enum class States {Normal, Pressed, Disabled, MouseOver}; /*enum states for the button*/

	/*
	* Function: Constructor
	* ---------------------
	*
	* Default constructor
	*
	*/
    Button() {};

	/*
	* Function: Constructor
	* ---------------------
	*
	* this constructor set the buttons text size, what text to display and the RECT
	* bounding box for it
	*
	*/
    Button(int x, int y, int width, int height, std::string text, aie::Font * font);

	/*
	* Function: DeConstructer
	* ------------------------
	*
	* Default deConstructor.
	*
	*/
    ~Button();

	/*
	* Function: setTextures
	* ---------------------
	*
	* set the Array of textures in order: normal, pressed, disabled, mouse-over
	*
	* Parameters: const std::string filePaths[] the file path to all textures
	*
	* returns: returns nothing as it is a void function
	*/
    void setTextures(const std::string filePaths[]);

	/*
	* Function: Update
	* ----------------
	*
	* update loop for the button to check if it has been pressed or
	* hovered over, just relised excetra.
	*
	* Parameters: float deltaTime so we have the deltaTime
	*
	* returns: returns nothing as it is a void function
	*/
    void update(float deltaTime);
	
	/*
	* Function: Draw
	* --------------
	*
	* this draws out the button to the screen
	*
	* Parameters: aie::Renderer2D * renderer so that we can render things out
	*
	* returns: returns nothing as it is a void function
	*/
    void draw(aie::Renderer2D *renderer);

	/*
	* Function: enable
	* ----------------
	*
	* sets if the button is enabled or not based on the bool passed in
	*
	* Parameters: bool isEnabled <- what we are setting the buttons enable to
	*
	* returns: returns nothing as it is a void function
	*/
    void enable(bool isEnabled);

	/*
	* Function: connect
	* -----------------
	*
	* this connects the buttons function pointer up the the function info passed in
	*
	* Parameters: myFUNC_0(void) funcClicked <- the function info passed in
	*
	* returns: returns nothing as it is a void function
	*/
    void connect(myFUNC_0(void) funcClicked);


private:

    RECT m_rect;		/*the rect of the button*/
		
    States m_state;		/*the current state of the button press, MouseOver ectra*/

    States m_prevState;	/*the previous state of the button*/

    std::string m_text;	/*text of the button*/

    aie::Font * m_font;	/*the font of the button*/

    myFUNC_0(void) m_funcClicked;	/*the function pointer for the function we want to exacute when we press the button*/

    typedef std::unique_ptr<aie::Texture> TexturePtr; /**/

    TexturePtr m_texNormal;		/*texture pointer to normal button texture*/
    TexturePtr m_texPressed;	/*texture pointer to pressed button texture*/
    TexturePtr m_texMouseOver;	/*texture pointer to mouseOver button texture*/
    TexturePtr m_texDisabled;	/*texture pointer to disabled button texture*/

};

