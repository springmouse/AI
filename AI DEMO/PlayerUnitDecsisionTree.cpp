#include "PlayerUnitDecsisionTree.h"
#include "Entity.h"
#include "NavManager.h"
#include "GetAStarPath.h"


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
    N2->comment = "Does Unit Have Path?";

    Node * N3 = new Node();
    nodes.push_back(N3);
    N3->comment = "Is Player At target?";

    Node * N4 = new Node();
    nodes.push_back(N4);
    N4->comment = "Set New Target";

    Node * N5 = new Node();
    nodes.push_back(N5);
    N4->comment = "Get New Path";

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
        if (unit->m_path.size() > 0)
        {
            return true;
        }
        return false;
    };

    N3->run = [unit]()->bool 
    { 
        return unit->m_currLocation->CheckIfInMeshBounds(unit->m_target); 
    };

    N4->run = [unit]()->bool
    {
        int random = std::rand() % NAVMANAGER->g_NavNodes.size();

        for each (SharedMeshPtr n in NAVMANAGER->g_NavNodes)
        {
            random--;
            if (random == 0)
            {
                unit->m_target = n->GetCenter();
            }
        }

        return true;
    };

    N5->run = [unit]()->bool
    {
        unit->m_path.clear();
        unit->m_path = PATH_FINDER->FindPath(unit->GetPos(), unit->m_target);

        return true;
    };

    ///////////////////////////////////////////////////////////////////////////////

    N1->yes = N2;
    N1->no = nullptr; //exit

    N2->yes = N3;
    N2->no = N4;

    N3->yes = N4;
    N3->no = nullptr; //exit

    N4->yes = N5;
    N4->no = nullptr; //error!!!

    N5->yes = nullptr; //exit
    N5->no = nullptr; //exit

}
