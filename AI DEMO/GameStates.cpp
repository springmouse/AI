#include "GameStates.h"
#include "Factory.h"
#include "Input.h"
#include "Information.h"
#include <string>
#include <time.h>
#include "NavManager.h"
#include "RenderToMesh.h"
#include "MouseState.h"

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

        if (AIEINPUT->isKeyDown(aie::INPUT_KEY_3))
        {
            INFOMATION->pushInfo(eGameStateType::FLOCKING);
        }

        if (AIEINPUT->isKeyDown(aie::INPUT_KEY_2))
        {
            INFOMATION->pushInfo(eGameStateType::INGAME);
        }

        if (AIEINPUT->isKeyDown(aie::INPUT_KEY_1))
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
        m_2dRenderer->drawText(font, "3: start Flocking and Sterring Behaviours", INFOMATION->cameraPos.x + (500 - 252), INFOMATION->cameraPos.y + 360);
        m_2dRenderer->drawText(font, "2: start Path Finding and Desciscions", INFOMATION->cameraPos.x + (500 - 228), INFOMATION->cameraPos.y + 300);
        m_2dRenderer->drawText(font, "1: close game", INFOMATION->cameraPos.x + 500, INFOMATION->cameraPos.y + 180);
    }
}

void MenuState::onPopped()
{
	//slates the programe to close down
    INFOMATION->quit = true;
}

#pragma endregion

///////////////////////////////////

#pragma region Flocking

InGameFlockStake::InGameFlockStake()
{
    m_boidsBlackBoard = new BoidsBlackBoard();

    for (int i = 0; i <= 25; i++)
    {
        m_boids.push_back(ShareBoidPtr(new Boids(m_boidsBlackBoard, INFOMATION->cameraPos)));
    }

    m_boidsBlackBoard->m_boids = m_boids;
}

InGameFlockStake::~InGameFlockStake()
{
}

void InGameFlockStake::onUpdate(float deltaTime)
{
    if (m_active)
    {
        //check if we need to pop the game out
        if (AIEINPUT->isKeyDown(aie::INPUT_KEY_ESCAPE))
        {
            INFOMATION->pop = true;
        }

        MOUSE->Update(deltaTime);

        for each (ShareBoidPtr boid in m_boids)
        {
            boid->Update(deltaTime);
        }

        m_boidsBlackBoard->Update(deltaTime);
    }
}

void InGameFlockStake::onDraw(aie::Renderer2D * m_2dRenderer, aie::Font * font)
{
    if (m_active)
    {  
        for each (ShareBoidPtr boid in m_boids)
        {
            boid->Draw(m_2dRenderer);
        }

        m_2dRenderer->drawText(font, "Flocking", INFOMATION->cameraPos.x + 25, INFOMATION->cameraPos.y + 25);

    }
}

void InGameFlockStake::onPopped()
{
}

#pragma endregion

///////////////////////////////////

#pragma region InGameState

InGameState::InGameState()
{
    INFOMATION->cameraPos = Vector2(0 - (INFOMATION->nodeSize), 0 - ( 2 * INFOMATION->nodeSize));

    std::string buttonTexPaths[4];

    buttonTexPaths[0] = "./textures/ButtonNormal.png";
    buttonTexPaths[1] = "./textures/ButtonPressed.png";
    buttonTexPaths[2] = "./textures/ButtonDisabled.png";
    buttonTexPaths[3] = "./textures/ButtonHover.png";


    Button::SharedPtr button(new Button((INFOMATION->cameraPos.x + 32), (INFOMATION->cameraPos.y + (2 * INFOMATION->nodeSize) + 675), 128, 32, "Creat Node Tool", new aie::Font("./font/consolas.ttf", 12)));
    button->connect(myBIND_0(InGameState::ButtonAssignBuildMode, this));
    button->setTextures(buttonTexPaths);
    m_buttons.push_back(button);

    Button::SharedPtr button2(new Button((INFOMATION->cameraPos.x + 32), (INFOMATION->cameraPos.y + (2 * INFOMATION->nodeSize) + 640), 128, 32, "Destroy Node Tool", new aie::Font("./font/consolas.ttf", 12)));
    button2->connect(myBIND_0(InGameState::ButtonAssignDestroyMode, this));
    button2->setTextures(buttonTexPaths);
    m_buttons.push_back(button2);

    Button::SharedPtr button3(new Button((INFOMATION->cameraPos.x + 32), (INFOMATION->cameraPos.y + (2 * INFOMATION->nodeSize) + 605), 128, 32, "Swap Draw To Node", new aie::Font("./font/consolas.ttf", 12)));
    button3->connect(myBIND_0(NavManager::SwapDrawToNode, NAVMANAGER));
    button3->setTextures(buttonTexPaths);
    m_buttons.push_back(button3);
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
        if (AIEINPUT->isKeyDown(aie::INPUT_KEY_ESCAPE))
        {
            INFOMATION->pop = true;
        }

        MOUSE->Update(deltaTime);

        MOUSE->mousestate = MouseState::States::INGAME;

        for (auto btn : m_buttons)
        {
            btn->update(deltaTime);
        }

        NAVMANAGER->Update(deltaTime);

        /////////////////////////////////////////////////////////

        timmer += deltaTime;
        if (AIEINPUT->isMouseButtonDown(1) && timmer > 1)
        {
            m_units.push_back(FACTORY->MakeEntity(eEntityTyes::VILLAGER, MOUSE->mousePosGameSpace));
        }
        for each (Entity * e in m_units)
        {
            e->Update(deltaTime);
        }
    }
}

void InGameState::onDraw(aie::Renderer2D * m_2dRenderer, aie::Font* font)
{
    if (m_active)
    {
        RENDER->Draw(m_2dRenderer, font);

        for (auto btn : m_buttons)
        {
            btn->draw(m_2dRenderer);
        }

        m_2dRenderer->setCameraPos(INFOMATION->cameraPos.x, INFOMATION->cameraPos.y);

        m_2dRenderer->drawText(font, "press esc to go back to main menu", INFOMATION->cameraPos.x, INFOMATION->cameraPos.y + 10);

        //////////////////////////////////////
        for each (Entity * e in m_units)
        {
            e->Draw(m_2dRenderer);
        }
    }
}

void InGameState::ButtonAssignBuildMode()
{
    MOUSE->connect(myBIND_0(NavManager::CreatNewNode, NAVMANAGER));
}

void InGameState::ButtonAssignDestroyMode()
{
    MOUSE->connect(myBIND_0(NavManager::DestroyNode, NAVMANAGER));
}

#pragma endregion

///////////////////////////////////

