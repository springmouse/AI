#include "GameStates.h"
#include "Factory.h"
#include "Input.h"
#include "Information.h"
#include <string>
#include <time.h>
#include "NavManager.h"
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

	//places down all the boids
    for (int i = 0; i <= 100; i++)
    {
        m_boids.push_back(ShareBoidPtr(new Boids(m_boidsBlackBoard)));
    }

	//gives it the list of all the boids
    m_boidsBlackBoard->m_boids = m_boids;
}

InGameFlockStake::~InGameFlockStake()
{
	delete m_boidsBlackBoard;
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

	m_villigerBlackBoard = new VillagerBlackBoard();
	
	//gets the path to all the button textures
    std::string buttonTexPaths[4];

    buttonTexPaths[0] = "./textures/ButtonNormal.png";
    buttonTexPaths[1] = "./textures/ButtonPressed.png";
    buttonTexPaths[2] = "./textures/ButtonDisabled.png";
    buttonTexPaths[3] = "./textures/ButtonHover.png";

	//sets up all the buttons with there functions and textures
    Button::SharedPtr button(new Button((INFOMATION->cameraPos.x + 32), (INFOMATION->cameraPos.y + (2 * INFOMATION->nodeSize) + 675), 128, 32, "Creat Node Tool", new aie::Font("./font/consolas.ttf", 12)));
    button->connect(myBIND_0(InGameState::ButtonAssignBuildMode, this));
    button->setTextures(buttonTexPaths);
    m_buttons.push_back(button);

    Button::SharedPtr button2(new Button((INFOMATION->cameraPos.x + 32), (INFOMATION->cameraPos.y + (2 * INFOMATION->nodeSize) + 640), 128, 32, "Destroy Node Tool", new aie::Font("./font/consolas.ttf", 12)));
    button2->connect(myBIND_0(InGameState::ButtonAssignDestroyMode, this));
    button2->setTextures(buttonTexPaths);
    m_buttons.push_back(button2);

    Button::SharedPtr button3(new Button((INFOMATION->cameraPos.x + 32), (INFOMATION->cameraPos.y + (2 * INFOMATION->nodeSize) + 605), 128, 32, "Limited Food", new aie::Font("./font/consolas.ttf", 12)));
    button3->connect(myBIND_0(InGameState::ButtonAssignLimitedFood, this));
    button3->setTextures(buttonTexPaths);
    m_buttons.push_back(button3);

	Button::SharedPtr button4(new Button((INFOMATION->cameraPos.x + 32), (INFOMATION->cameraPos.y + (2 * INFOMATION->nodeSize) + 570), 128, 32, "Infinite Food", new aie::Font("./font/consolas.ttf", 12)));
	button4->connect(myBIND_0(InGameState::ButtonAssignInfiniteFood, this));
	button4->setTextures(buttonTexPaths);
	m_buttons.push_back(button4);
}

InGameState::~InGameState()
{
	delete m_villigerBlackBoard;
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

		//check if a button has been pressed
        for (auto btn : m_buttons)
        {
            btn->update(deltaTime);
        }

        /////////////////////////////////////////////////////////

		//places down a new unit
        timmer += deltaTime;
        if (AIEINPUT->isMouseButtonDown(1) && timmer > 1)
        {
            for each (SharedMeshPtr mesh in NAVMANAGER->g_NavNodes)
            {
                if (mesh->CheckIfInMeshBounds(MOUSE->mousePosGameSpace) == true)
                {
                    m_units.push_back(FACTORY->MakeEntity(eEntityTyes::VILLAGER,Vector2(MOUSE->mousePosGameSpace.x + (std::rand() % 10 - 5), MOUSE->mousePosGameSpace.y + (std::rand() % 10 - 5)), m_villigerBlackBoard));
                }
            }
        }

		//check if we need to remove anything before updateing units
		CheckToRemoveFood();
		CheckUnitsToRemove();

		//update the blackboards lists
		m_villigerBlackBoard->m_entites = m_units;
		m_villigerBlackBoard->m_food = m_food;

		//update the units
        for each (Entity * e in m_units)
        {
            e->Update(deltaTime);
        }

		//get all the murders
		GatherMurders();
    }
}

void InGameState::onDraw(aie::Renderer2D * m_2dRenderer, aie::Font* font)
{
    if (m_active)
    {
		NAVMANAGER->Draw(m_2dRenderer);

		//draw buttons
        for (auto btn : m_buttons)
        {
            btn->draw(m_2dRenderer);
        }

        m_2dRenderer->setCameraPos(INFOMATION->cameraPos.x, INFOMATION->cameraPos.y);

        m_2dRenderer->drawText(font, "press esc to go back to main menu", INFOMATION->cameraPos.x, INFOMATION->cameraPos.y + 10);

        //////////////////////////////////////
		for each (SharedFoodPtr food in m_food)
		{
			food->Draw(m_2dRenderer);
		}

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

void InGameState::ButtonAssignLimitedFood()
{
	MOUSE->connect(myBIND_0(InGameState::CreatLimitedFood, this));
}

void InGameState::ButtonAssignInfiniteFood()
{
	MOUSE->connect(myBIND_0(InGameState::CreatInfiniteFood, this));
}

void InGameState::CreatLimitedFood()
{
	//check that position is valid then places the food
	for each (SharedMeshPtr mesh in NAVMANAGER->g_NavNodes)
	{
		if (mesh->CheckIfInMeshBounds(MOUSE->mousePosGameSpace) == true && mesh->GetIsPasible())
		{
			m_food.push_back(FACTORY->MakeFood(eFoodTypes::FOOD_LIMITED, MOUSE->mousePosGameSpace));
			mesh->SetPassible(false);
			NAVMANAGER->GatherEdges();
		}
	}
}

void InGameState::CreatInfiniteFood()
{
	//check that position is valid then places the food
	for each (SharedMeshPtr mesh in NAVMANAGER->g_NavNodes)
	{
		if (mesh->CheckIfInMeshBounds(MOUSE->mousePosGameSpace) == true && mesh->GetIsPasible())
		{
			m_food.push_back(FACTORY->MakeFood(eFoodTypes::FOOD_INFINITE, MOUSE->mousePosGameSpace));
			mesh->SetPassible(false);
			NAVMANAGER->GatherEdges();
		}
	}
}

void InGameState::CheckToRemoveFood()
{
	for each (SharedFoodPtr food in m_food)
	{
		//checks positon is still valid
		if (food->CheckIFPosValid() == false)
		{
			m_foodToRemove.push_back(food); 
			continue;
		}

		//checks if we have run out of food
		if (food->IsFoodLeft() == false)
		{
			m_foodToRemove.push_back(food);
			for each (SharedMeshPtr mesh in NAVMANAGER->g_NavNodes)
			{
				if (mesh->CheckIfInMeshBounds(food->GetPos()) == true)
				{
					mesh->SetPassible(true);
					NAVMANAGER->GatherEdges();
					continue;
				}
			}
		}
	}

	//remove the food from the main list
	for each (SharedFoodPtr food in m_foodToRemove)
	{
		m_food.remove(food);
	}

	//clears the list
	m_foodToRemove.clear();
}

void InGameState::CheckUnitsToRemove()
{
	//finds all dead units
	for each (Entity * unit in m_units)
	{
		if (unit->IsAlive() == false)
		{
			m_unitsToRemove.push_back(unit);
		}
	}

	//removes all dead units from the list
	for each (Entity * unit in m_unitsToRemove)
	{
		m_units.remove(unit);
	}

	m_unitsToRemove.clear();
}

void InGameState::GatherMurders()
{
	m_villigerBlackBoard->m_murders.clear();

	//loop through all the units and find the murderers
	for each (Entity * unit in m_units)
	{
		if (unit->m_murder == true)
		{
			m_villigerBlackBoard->m_murders.push_back(unit);
		}
	}

}

#pragma endregion

///////////////////////////////////

