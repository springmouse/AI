#include "PlayerUnitDecsisionTree.h"
#include "Entity.h"
#include "NavManager.h"
#include "GetAStarPath.h"
#include "VillegerUtility.h"
#include "VillagerBlackBoard.h"
#include "EntityStateMachine.h"


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
    Entity * unit = myUnit;

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
    N4->comment = "Does murder have target";

	Node * N6 = new Node();
	nodes.push_back(N6);
	N4->comment = "is there target with in LOS";

	Node * N7 = new Node();
	nodes.push_back(N7);
	N4->comment = "Find Nearest Target with in radius";

	Node * N8 = new Node();
	nodes.push_back(N8);
	N4->comment = "Set Murder to true";

	Node * N9 = new Node();
	nodes.push_back(N9);
	N4->comment = "Does unit have path";

	Node * N10 = new Node();
	nodes.push_back(N10);
	N4->comment = "Get Path";

	Node * N11 = new Node();
	nodes.push_back(N11);
	N4->comment = "wander";

    ///////////////////////////////////////////////////////////////////////////////

    start = N1;

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

		for each (Entity * ent in unit->GetBlackBoard()->m_entites)
		{
			if (unit->m_murderTarget == ent)
			{
				return true;
			}
		}

		unit->m_murderTarget = nullptr;
		return false;
    };

	N6->run = [unit]()->bool
	{
		Entity * holder = nullptr;

		Vector2 pos = unit->GetPos();

		for each (Entity * ent in unit->GetBlackBoard()->m_entites)
		{
			if (PATH_FINDER->LineCheck(unit->GetPos(), ent->GetPos()) == false)
			{
				if (holder == nullptr && *unit != ent)
				{
					holder = ent;
				}

				if (holder != nullptr)
				{
					if (unit->GetUtility()->sprMagnatude(ent->GetPos() - pos) < unit->GetUtility()->sprMagnatude(holder->GetPos() - pos) && *unit != ent)
					{
						holder = ent;
					}
				}
			}
		}

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

		if (unit->GetBlackBoard()->m_entites.size() <= 1)
		{
			return false;
		}

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
		unit->GetStateMachine()->pushState(0);
		unit->GetStateMachine()->pushState(2);

		unit->m_path.clear();

		unit->m_murderTarget = nullptr;

		return true;
	};

	N9->run = [unit]()->bool
	{
		if (unit->m_updatePathTimer > 1)
		{
			unit->m_path.clear();
			unit->m_updatePathTimer = 0;
		}

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
		if (unit->m_path.size() <= 0)
		{
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

		return true;
	};

    ///////////////////////////////////////////////////////////////////////////////

    N1->yes = N2;
    N1->no = nullptr; //exit

    N2->yes = N5;
    N2->no = N3;

    N3->yes = N4;
    N3->no = N11; //exit

    N4->yes = N11; //exit
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
}
