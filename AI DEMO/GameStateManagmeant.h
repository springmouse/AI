#pragma once
#include "GameStates.h"
#include "Font.h"
#include "Renderer2D.h"
#include <List>

/*
* Class: GameStateManagmeant
* --------------------------
*
* this managers our GameStates with in the game and trys to run properly
*
* Author: Callum Dunstone
* heavily based off the material from 
* https://aieeduau-my.sharepoint.com/personal/conanb_aie_edu_au/_layouts/15/WopiFrame.aspx?docid=0311e634fb60e43f49302008760699d34&authkey=AQDmZREYjRuxD3z0wvVGWU0&action=view
*/
class GameStateManagmeant
{
public:

    /*
    * Function: Constructor
    * ---------------------
    *
    * Default constructor, it does nothing.
    *
    */
    GameStateManagmeant();

    /*
    * Function: Constructor
    * ---------------------
    *
    * Default constructor, it does nothing.
    *
    */
    virtual  ~GameStateManagmeant();

    /*
    * Function: registerState
    * -----------------------
    *
    * this adds the state passed into it, in to the m_registeredStates so that they can be easily called and accessed 
    *
    * Parameters: this takes in a GameState pointer that will be added to the m_registeredStates
    *
    * returns: returns nothing as it is a null function
    */
    void registerState(GameStates * state) { m_registeredStates.push_back(state); };

	/*
	* Function: pushState
	* -------------------
	*
	* this adds the state passed into it, in to the m_registeredStates so that they can be easily called and accessed
	*
	* Parameters: this takes in a GameState pointer that will be added to the m_registeredStates
	*
	* returns: returns nothing as it is a null function
	*/
    void pushState(int id);

	/*
	* Function: Update
	* ----------------
	*
	* this will pop and push states properly and run the game states update funtions
	*
	* Parameters: this takes in float deltaTime to be passed into the game states
	*
	* returns: returns nothing as it is a void function
	*/
    void Update(float deltaTime);

	/*
	* Function: draw
	* --------------
	*
	* this calls the states draw function to draw the game to screen
	*
	* Parameters: this takes in aie::Renderer2D * m_2dRenderer so we can actually tell things to render,
	*	aie::Font * font so we can use text properly
	*
	* returns: returns nothing as it is a void function
	*/
    void draw(aie::Renderer2D * m_2dRenderer, aie::Font * font)
    {
        for (auto state : m_stateStack)
        {
            state->onDraw(m_2dRenderer, font);
        }
    }

	/*
	* Function: ActiveStateCount
	* --------------------------
	*
	* this returns how many states are currently active or about to be active
	*
	* Parameters: this takes in no parameters
	*
	* returns: returns an int of m_stateStack + m_pushedStates combined leangths
	*/
    int ActiveStateCount() { return (m_stateStack.size() + m_pushedStates.size()); };

	/*
	* Function: GetState
	* ------------------
	*
	* this gets a state from the m_registeredStates mainly to be
	* used to push the state on to m_pushedStates so it can be added to m_stateStack
	*
	* Parameters: this takes in an int to get the state from a certin location of m_registeredStates
	*
	* returns: GameStates pointer to a state being held in m_registeredStates
	*/
    GameStates * GetState(int id) 
    {
        std::list<GameStates *>::iterator it = m_registeredStates.begin();
        std::advance(it, id);

        return * it;

    };

protected:
    std::list<GameStates *> m_pushedStates; /*the states to be pushed onto m_stateStack*/

    std::list<GameStates *> m_stateStack; /*holds all states currently in use*/
    std::list<GameStates *> m_registeredStates; /*holds all states that can be used*/
};

