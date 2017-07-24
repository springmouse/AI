#include "GameStates.h"
#include "Factory.h"
#include "Input.h"
#include "Information.h"
#include <string>
#include <time.h>
#include "NavManager.h"

#include <iostream>

#pragma region GameStates

GameStates::GameStates()
{
}


GameStates::~GameStates()
{
}

#pragma endregion

///////////////////////////////////

#pragma region MenuState

MenuState::MenuState()
{
}

MenuState::~MenuState()
{
}

void MenuState::onUpdate(float deltaTime)
{
	//runs while state is active
    if (m_active)
    {
		//checks to see if game should run or close down
        if (INPUT->isKeyDown(aie::INPUT_KEY_1))
        {
            INFOMATION->pushInfo(eGameStateType::INGAME);
        }

        if (INPUT->isKeyDown(aie::INPUT_KEY_2))
        {
            INFOMATION->pop = true;
        }
    }
}

void MenuState::onDraw(aie::Renderer2D * m_2dRenderer, aie::Font* font)
{
	//renders the options to the screen
    if (m_active)
    {
        m_2dRenderer->setCameraPos(INFOMATION->cameraPos.x, INFOMATION->cameraPos.y);
        m_2dRenderer->drawText(font, "1: start game", INFOMATION->cameraPos.x + 500, INFOMATION->cameraPos.y + 360);
        m_2dRenderer->drawText(font, "2: close game", INFOMATION->cameraPos.x + 500, INFOMATION->cameraPos.y + 180);
    }
}

void MenuState::onPopped()
{
	//slates the programe to close down
    INFOMATION->quit = true;
}

#pragma endregion

///////////////////////////////////

#pragma region InGameState

InGameState::InGameState()
{
    INFOMATION->cameraPos = Vector2(0 - (INFOMATION->nodeSize), 0 - ( 2 * INFOMATION->nodeSize));
}


InGameState::~InGameState()
{
}

void InGameState::onEnter()
{
    
}

void InGameState::onUpdate(float deltaTime)
{
    if (m_active)
    {
        //check if we need to pop the game out
        if (INPUT->isKeyDown(aie::INPUT_KEY_ESCAPE))
        {
            INFOMATION->pop = true;
        }

        NAVMANAGER->Update(deltaTime);
    }
}

void InGameState::onDraw(aie::Renderer2D * m_2dRenderer, aie::Font* font)
{
    if (m_active)
    {
        NAVMANAGER->Draw(m_2dRenderer);
        
        m_2dRenderer->setCameraPos(INFOMATION->cameraPos.x, INFOMATION->cameraPos.y);

        m_2dRenderer->drawText(font, "press esc to go back to main menu", INFOMATION->cameraPos.x, INFOMATION->cameraPos.y + 10);
    }
}

#pragma endregion

///////////////////////////////////

