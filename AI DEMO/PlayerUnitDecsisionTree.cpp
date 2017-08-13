#include "PlayerUnitDecsisionTree.h"
#include "Entity.h"
#include "NavManager.h"
#include "GetAStarPath.h"
#include "VillegerUtility.h"
#include "VillagerBlackBoard.h"
#include "EntityStateMachine.h"
#include "Food.h";

#include <iostream>


PlayerUnitDecsisionTree::PlayerUnitDecsisionTree(Entity * unit)
{
    myUnit = unit;

    CreatNodes();
}

PlayerUnitDecsisionTree::~PlayerUnitDecsisionTree()
{
    nodes.clear();
}

void PlayerUnitDecsisionTree::Update()
{
    Node * n = start;

    while (n)
    {
        bool run = n->run();

        if (run == true)
        {
            n = n->yes;
        }
        else
        {
            n = n->no;
        }
    }
}

void PlayerUnitDecsisionTree::CreatNodes()
{
	//needed of lamda functions assigning
    Entity * unit = myUnit;

	///////////////////////////////////////////////////////////////////////////////
	/////create all the nodes add them to the list and set there comment///////////
    ///////////////////////////////////////////////////////////////////////////////

    Node * N1 = new Node();
    nodes.push_back(N1);
    N1->comment = "Is Unit Alive?";

    Node * N2 = new Node();
    nodes.push_back(N2);
    N2->comment = "Is Murder?";

    Node * N3 = new Node();
    nodes.push_back(N3);
    N3->comment = "Is murder > Gather?";

    Node * N4 = new Node();
    nodes.push_back(N4);
    N4->comment = "Does Unit have LOS to murders";

    Node * N5 = new Node();
    nodes.push_back(N5);
	N5->comment = "Does murder have target";

	Node * N6 = new Node();
	nodes.push_back(N6);
	N6->comment = "is there target with in LOS";

	Node * N7 = new Node();
	nodes.push_back(N7);
	N7->comment = "Find Nearest Target with in radius";

	Node * N8 = new Node();
	nodes.push_back(N8);
	N8->comment = "Set Murder to true";

	Node * N9 = new Node();
	nodes.push_back(N9);
	N9->comment = "Does unit have path";

	Node * N10 = new Node();
	nodes.push_back(N10);
	N10->comment = "Get Path";

	Node * N11 = new Node();
	nodes.push_back(N11);
	N11->comment = "wander";

	Node * N12 = new Node();
	nodes.push_back(N12);
	N12->comment = "is fight > wonder";

	Node * N13 = new Node();
	nodes.push_back(N13);
	N13->comment = "Get Closes murder";

	Node * N14 = new Node();
	nodes.push_back(N14);
	N14->comment = "Set path to murder";

	Node * N15 = new Node();
	nodes.push_back(N15);
	N15->comment = "fight > gather";

	Node * N16 = new Node();
	nodes.push_back(N16);
	N16->comment = "fight > gather";

	Node * N17 = new Node();
	nodes.push_back(N17);
	N17->comment = "fight > gather";

	Node * N18 = new Node();
	nodes.push_back(N18);
	N18->comment = "fight > gather";

	///////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////set start node///////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////

    start = N1;

	///////////////////////////////////////////////////////////////////////////////
	//////////////////Set up all the functions for the nodes///////////////////////
    ///////////////////////////////////////////////////////////////////////////////

    N1->run = [unit]()->bool 
    {
        if (unit->m_health > 0) 
        { 
            return true; 
        } 
        return false; 
    };

    N2->run = [unit]()->bool
    {
        if (unit->m_murder)
        {
            return true;
        }
        return false;
    };

    N3->run = [unit]()->bool 
    { 
		if (unit->GetUtility()->m_murder > unit->GetUtility()->m_getFood)
		{
			return true;
		}

		return false;
    };

    N4->run = [unit]()->bool
    {
		if (unit->GetBlackBoard()->m_murders.size() <= 0)
		{
			return false;
		}

		//check if a murder is with in LOS
        for each (Entity * n in unit->GetBlackBoard()->m_murders)
        {
			if (PATH_FINDER->LineCheck(unit->GetPos(), n->GetPos()) == false)
			{
				return true;
			}
        }

        return false;
    };

    N5->run = [unit]()->bool
    {
		if (unit->m_murderTarget == nullptr)
		{
			return false;
		}

		//see if we have target return true if we do
		for each (Entity * ent in unit->GetBlackBoard()->m_entites)
		{
			if (unit->m_murderTarget == ent)
			{
				return true;
			}
		}

		//set target to nothing then return false as we did not have target
		unit->m_murderTarget = nullptr;
		return false;
    };

	N6->run = [unit]()->bool
	{
		Entity * holder = nullptr;

		Vector2 pos = unit->GetPos();

		//trys to find target with in LOS
		for each (Entity * ent in unit->GetBlackBoard()->m_entites)
		{
			if (PATH_FINDER->LineCheck(unit->GetPos(), ent->GetPos()) == false)
			{
				//set target to first one that is not us
				if (holder == nullptr && *unit != ent)
				{
					holder = ent;
				}

				//checks if the new ent we are looking at is closer or not and if use set target to is
				if (holder != nullptr)
				{
					if (unit->GetUtility()->sprMagnatude(ent->GetPos() - pos) < unit->GetUtility()->sprMagnatude(holder->GetPos() - pos) && *unit != ent)
					{
						holder = ent;
					}
				}
			}
		}

		//if we got no target return false
		if (holder == nullptr)
		{
			return false;
		}

		unit->m_murderTarget = holder;

		return true;

	};

	N7->run = [unit]()->bool
	{
		Entity * holder = nullptr;

		Vector2 pos = unit->GetPos();

		//make sure we are not the only ones in the world
		if (unit->GetBlackBoard()->m_entites.size() <= 1)
		{
			return false;
		}

		//loop through them all and check if there is anyone near us
		for each (Entity * ent in unit->GetBlackBoard()->m_entites)
		{
			if (holder == nullptr && *unit != ent)
			{
				holder = ent;
			}

			if (holder == nullptr)
			{
				break;
			}

			else if (unit->GetUtility()->sprMagnatude(ent->GetPos() - pos) < unit->GetUtility()->sprMagnatude(holder->GetPos() - pos))
			{
				holder = ent;
			}
		}

		return true;
	};

	N8->run = [unit]()->bool
	{
		unit->m_murder = true;

		unit->GetStateMachine()->Clear();
		unit->GetStateMachine()->pushState(0); /*move state*/
		unit->GetStateMachine()->pushState(2); /*murder state*/

		unit->m_path.clear();

		unit->m_murderTarget = nullptr;

		return true;
	};

	N9->run = [unit]()->bool
	{
		//clear path if timer is over the check value
		if (unit->m_updatePathTimer > 1)
		{
			unit->m_path.clear();
			unit->m_updatePathTimer = 0;
		}

		//if the path has nothing in it return true
		if (unit->m_path.size() <= 0)
		{
			return false;
		}

		return true;
	};

	N10->run = [unit]()->bool
	{
		if (unit->m_murderTarget != nullptr)
		{
			unit->m_path = PATH_FINDER->FindPath(unit->GetPos(), unit->m_murderTarget->GetPos());
		}

		return true;
	};

	N11->run = [unit]()->bool
	{
		//if the unit has no path then we pick it a random node and let it path to it
		if (unit->m_path.size() <= 0 || unit->m_updatePathTimer > 5)
		{
			unit->m_updatePathTimer = 5;

			int count = std::rand() % NAVMANAGER->g_NavNodes.size();

			for each (SharedMeshPtr node in NAVMANAGER->g_NavNodes)
			{
				count--;
				if (count <= 0)
				{
					unit->m_target = node->GetCenter();
					break;
				}
			}

			unit->m_path = PATH_FINDER->FindPath(unit->GetPos(), unit->m_target);
		}

		unit->GetStateMachine()->Clear();
		unit->GetStateMachine()->pushState(0); /*move state*/

		return true;
	};

	N12->run = [unit]()->bool
	{
		if (unit->GetUtility()->m_fight > unit->GetUtility()->m_flee)
		{
			return true;
		}
		
		return false;
	};

	N13->run = [unit]()->bool
	{
		if (unit->GetBlackBoard()->m_murders.size() <= 0)
		{
			return false;
		}

		unit->m_attackTarget = nullptr;
		Vector2 pos = unit->GetPos();

		//finds the closes murder to try and go kill
		for each (Entity * ent in unit->GetBlackBoard()->m_murders)
		{
			if (unit->m_attackTarget == nullptr)
			{
				unit->m_attackTarget = ent;
				continue;
			}

			if (unit->GetUtility()->sprMagnatude(ent->GetPos() - pos) < unit->GetUtility()->sprMagnatude(unit->m_attackTarget->GetPos() - pos))
			{
				unit->m_attackTarget = ent;
			}
		}

		return true;
	};

	N14->run = [unit]()->bool
	{
		//get path to murder
		if (unit->m_updatePathTimer > 3)
		{
			unit->m_path.clear();
			unit->m_path = PATH_FINDER->FindPath(unit->GetPos(), unit->m_attackTarget->GetPos());
			unit->m_updatePathTimer = 0;
		}

		unit->GetStateMachine()->Clear();
		unit->GetStateMachine()->pushState(0); /*move state*/
		unit->GetStateMachine()->pushState(3); /*attack state*/

		return true;
	};

	N15->run = [unit]()->bool
	{
		if (unit->GetBlackBoard()->m_murders.size() <= 0)
		{
			return false;
		}

		if (unit->GetUtility()->m_fight > unit->GetUtility()->m_getFood)
		{
			return true;
		}

		return false;
	};

	N16->run = [unit]()->bool
	{
		if (unit->GetUtility()->m_getFood > unit->GetUtility()->m_wonder)
		{
			return true;
		}

		return false;
	};

	N17->run = [unit]()->bool
	{
		if (unit->GetBlackBoard()->m_food.size() <= 0)
		{
			return false;
		}

		Vector2	pos = unit->GetPos();
		unit->m_target = Vector2(0,0);

		//find nearest food
		for each (SharedFoodPtr food in unit->GetBlackBoard()->m_food)
		{
			if (unit->m_target == Vector2(0, 0))
			{
				unit->m_target = food->GetPos();
			}

			if (unit->GetUtility()->sprMagnatude(food->GetPos() - pos) < unit->GetUtility()->sprMagnatude(unit->m_target - pos))
			{
				unit->m_target = food->GetPos();
				unit->m_neareastFood = food;
			}
		}
		SharedMeshPtr holder;

		//get the node the food is on
		for each (SharedMeshPtr node in NAVMANAGER->g_NavNodes)
		{
			if (node->CheckIfInMeshBounds(unit->m_target))
			{
				holder = node;
				break;
			}
		}

		//find nearest nave mesh next to the food
		unit->m_target = Vector2(0, 0);
		for each(SharedMeshPtr node in NAVMANAGER->GetEdgeConnections(holder))
		{
			if (unit->m_target == Vector2(0, 0))
			{
				unit->m_target = node->GetCenter();
			}

			if (unit->GetUtility()->sprMagnatude(node->GetCenter() - pos) < unit->GetUtility()->sprMagnatude(unit->m_target - pos))
			{
				unit->m_target = node->GetCenter();
			}
		}

		unit->GetStateMachine()->Clear();
		unit->GetStateMachine()->pushState(0); /*move state*/
		unit->GetStateMachine()->pushState(1); /*gather food state*/

		return true;
	};

	N18->run = [unit]()->bool
	{
		if (unit->m_updatePathTimer > 3)
		{
			unit->m_path.clear();
			unit->m_path = PATH_FINDER->FindPath(unit->GetPos(), unit->m_target);
			unit->m_updatePathTimer = 0;
		}

		return true;
	};

	///////////////////////////////////////////////////////////////////////////////
	/////////set up what nodes the nodes are connectd to for there yes/no//////////
    ///////////////////////////////////////////////////////////////////////////////

    N1->yes = N2;
    N1->no = nullptr; //exit

    N2->yes = N5;
    N2->no = N3;

    N3->yes = N4;
    N3->no = N15;

    N4->yes = N12;
    N4->no = N8; 

    N5->yes = N9;
    N5->no = N6;

	N6->yes = N10;
	N6->no = N7;

	N7->yes = N10;
	N7->no = nullptr; //Error

	N8->yes = N5; 
	N8->no = nullptr; //Error

	N9->yes = nullptr; //exit
	N9->no = N10;

	N10->yes = nullptr; //exit
	N10->no = nullptr; //exit

	N11->yes = nullptr; //exit
	N11->no = nullptr; //exit

	N12->yes = N13;
	N12->no = N11;

	N13->yes = N14;
	N13->no = nullptr; //exit

	N14->yes = nullptr; //exit
	N14->no = nullptr; //exit

	N15->yes = N13;
	N15->no = N16;

	N16->yes = N17;
	N16->no = N11;

	N17->yes = N18;
	N17->no = N11;

	N18->yes = nullptr; //exit
	N18->no = nullptr; //exit
}
