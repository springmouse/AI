#include "GameStates.h"
#include "Factory.h"
#include "Input.h"
#include "Information.h"
#include <string>
#include <time.h>

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
    for (int x = 0; x < 40; x++)
    {
        for (int y = 0; y < 20; y++)
        {
            m_nodes.push_back(new Node(x * INFOMATION->nodeSize, y * INFOMATION->nodeSize));
        }
    }

    INFOMATION->cameraPos = Vector2(0 - (INFOMATION->nodeSize), 0 - ( 2 * INFOMATION->nodeSize));
}

InGameState::~InGameState()
{
}

void InGameState::onEnter()
{
    for each (Node * nodeA in m_nodes)
    {
        int count = 0;
        for each (Node * nodeB in m_nodes)
        {
            if (*nodeB == Vector2(nodeA->GetPos().x, nodeA->GetPos().y + INFOMATION->nodeSize))
            {
                nodeA->AddEdge(nodeB);
                count++;
            }

            if (*nodeB == Vector2(nodeA->GetPos().x + INFOMATION->nodeSize, nodeA->GetPos().y - INFOMATION->nodeSize))
            {
                nodeA->AddEdge(nodeB);
                count++;
            }

            if (*nodeB == Vector2(nodeA->GetPos().x + INFOMATION->nodeSize, nodeA->GetPos().y))
            {
                nodeA->AddEdge(nodeB);
                count++;
            }

            if (*nodeB == Vector2(nodeA->GetPos().x + INFOMATION->nodeSize, nodeA->GetPos().y + INFOMATION->nodeSize))
            {
                nodeA->AddEdge(nodeB);
                count++;
            }

            if (count == 4)
            {
                break;
            }
        }
    }
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
    }
}

void InGameState::onDraw(aie::Renderer2D * m_2dRenderer, aie::Font* font)
{
    if (m_active)
    {
        for each (Node * n in m_nodes)
        {
            m_2dRenderer->drawCircle(n->GetPos().x, n->GetPos().y, 5);
        }

        for each (Node * n in m_nodes)
        {
            for each(Node::NodeEdge * ne in n->g_edges)
            {
                m_2dRenderer->drawLine(ne->p_nodeA->GetPos().x, ne->p_nodeA->GetPos().y, ne->p_nodeB->GetPos().x, ne->p_nodeB->GetPos().y, 1);
            }
        }

        m_2dRenderer->setCameraPos(INFOMATION->cameraPos.x, INFOMATION->cameraPos.y);

        m_2dRenderer->drawText(font, "press esc to go back to main menu", INFOMATION->cameraPos.x, INFOMATION->cameraPos.y + 10);
    }
}

#pragma endregion

///////////////////////////////////

