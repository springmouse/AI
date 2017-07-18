#pragma once
#include "Application.h"
#include "Renderer2D.h"
#include "GameStateManagmeant.h"
#include "Factory.h"
#include "Information.h"

/*
* class: AI_DEMOApp
* ------------------
*
* this class is the one that will run out programe in this programe
*
* Aurthor: Callum Dunstone, AIE
*/
class AI_DEMOApp : public aie::Application {
public:

    /*
    * Function: Constructor
    * ---------------------
    *
    * this is the Default constructor of the class
    *
    */
	AI_DEMOApp();

    /*
    * Function: DeConstructor
    * ---------------------
    *
    * this is the Default Deconstructor of the class
    *
    */
	virtual ~AI_DEMOApp();

    /*
    *  runs at start up and initilizs things
    */
    virtual bool startup();

    /*
    *	that safely deletes the pointers of the class
    */
    virtual void shutdown();

    /*
    * Function: update
    * ----------------
    *
    * this runs every fram of the programe
    *
    * Parameters: this takes in a float, which is the delta time between the frames
    *
    * returns: returns nothing as it is a void function
    */
    virtual void update(float deltaTime);

    /*
    * Function: PushFront
    * -------------------
    *
    * this draws things to the screen each frame
    *
    * Parameters: this takes in no parameters
    *
    * returns: returns nothing as it is a null function
    */
    virtual void draw();

protected:

    GameStateManagmeant  m_gameSM; /*this managers the game states and lets them run*/

    aie::Renderer2D*	m_2dRenderer; /*this is the renderer that will rendere things to the screen*/
    aie::Font*			m_font; /*this is the font that is used when we want text to show up on screen*/
};