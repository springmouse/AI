#include "NavManager.h"
#include <iostream>
#include "MouseState.h"



NavManager * NavManager::GetInstanceOfNavManager()
{
    static NavManager nav;
    return & nav;
}

NavManager::NavManager()
{
    for (int x = 0; x < 40; x++)
    {
        for (int y = 0; y < 20; y++)
        {
            g_mapNodes.push_back(new MapNode(x * INFOMATION->nodeSize, y * INFOMATION->nodeSize));
        }
    }

    CreatNavMesh();
    SetUpStartUpNodeConections();

    m_timer = 0;
    m_pathTimer = 0;

    start = Vector2(0, 0);
    finish = Vector2(0, 0);

    m_tileTexture[0] = new aie::Texture("./textures/Ground.png");
    m_tileTexture[1] = new aie::Texture("./textures/Wall.png");
    m_tileTexture[2] = new aie::Texture("./textures/Boarder.png");

    m_drawToNode = true;
}


NavManager::~NavManager()
{
}


void NavManager::CreatNavMesh()
{
    for each (MapNode * nodeA in g_mapNodes)
    {
        MapNode * one = nullptr;

        MapNode * two = nodeA;

        MapNode * three = nullptr;
        MapNode * four = nullptr;

        int count = 0;
        for each (MapNode * nodeB in g_mapNodes)
        {
            //Upper Left
            if (*nodeB == Vector2(nodeA->m_pos.x, nodeA->m_pos.y + INFOMATION->nodeSize))
            {
                one = nodeB;
                count++;
            }

            //lower Right
            if (*nodeB == Vector2(nodeA->m_pos.x + INFOMATION->nodeSize, nodeA->m_pos.y))
            {
                four = nodeB;
                count++;
            }

            //upper Right
            if (*nodeB == Vector2(nodeA->m_pos.x + INFOMATION->nodeSize, nodeA->m_pos.y + INFOMATION->nodeSize))
            {
                three = nodeB;
                count++;
            }

            if (count == 3)
            {
                g_NavNodes.push_back(new NavMeshNode(*one, *two, *three, *four));
                break;
            }
        }
    }
}

void NavManager::SetUpStartUpNodeConections()
{
    for each (NavMeshNode * nodeA in g_NavNodes)
    {
        for each (NavMeshNode * nodeB in g_NavNodes)
        {
            if (nodeA != nodeB)
            {
                if (nodeA->CheckIfMapNodeIsShared(nodeB->GetUpperLeft()))
                {
                    nodeA->CheckIfConectionExists(nodeB);
                    nodeA->AddConnection(nodeB);
                }
                
                if (nodeA->CheckIfMapNodeIsShared(nodeB->GetLowerLeft()))
                {
                    nodeA->CheckIfConectionExists(nodeB);
                    nodeA->AddConnection(nodeB);
                }

                if (nodeA->CheckIfMapNodeIsShared(nodeB->GetUpperRight()))
                {
                    nodeA->CheckIfConectionExists(nodeB);
                    nodeA->AddConnection(nodeB);
                }

                if (nodeA->CheckIfMapNodeIsShared(nodeB->GetLowerRight()))
                {
                    nodeA->CheckIfConectionExists(nodeB);
                    nodeA->AddConnection(nodeB);
                }
            }
        }
    }
}

void NavManager::MakeConnectionsToNode(NavMeshNode * nodeA)
{
    for each (NavMeshNode * nodeB in g_NavNodes)
    {
        if (nodeA != nodeB)
        {
            if (nodeA->CheckIfMapNodeIsShared(nodeB->GetUpperLeft()))
            {
                nodeA->CheckIfConectionExists(nodeB);
                nodeA->AddConnection(nodeB);
            }

            if (nodeA->CheckIfMapNodeIsShared(nodeB->GetLowerLeft()))
            {
                nodeA->CheckIfConectionExists(nodeB);
                nodeA->AddConnection(nodeB);
            }

            if (nodeA->CheckIfMapNodeIsShared(nodeB->GetUpperRight()))
            {
                nodeA->CheckIfConectionExists(nodeB);
                nodeA->AddConnection(nodeB);
            }

            if (nodeA->CheckIfMapNodeIsShared(nodeB->GetLowerRight()))
            {
                nodeA->CheckIfConectionExists(nodeB);
                nodeA->AddConnection(nodeB);
            }
        }
    }
}

void NavManager::Update(float deltaTime)
{
    if (AIEINPUT->isMouseButtonDown(2))
    {
        finish = MOUSE->mousePosGameSpace;
    }

    m_pathTimer += deltaTime;
    if (AIEINPUT->isKeyDown(aie::INPUT_KEY_SPACE) && m_pathTimer >= 1)
    {
        nodeTest.clear();

        nodeTest = PATH_FINDER->FindPath(start, finish);

        m_pathTimer = 0;
    }
}


void NavManager::CreatNewNode()
{
    for each (NavMeshNode * n in g_NavNodes)
    {
        if (n->CheckIfInMeshBounds(MOUSE->mousePosGameSpace))
        {
            return;
        }
    }

    MapNode * one = nullptr;
    MapNode * two = nullptr;
    MapNode * three = nullptr;
    MapNode * four = nullptr;

    for each (MapNode * mn  in g_mapNodes)
    {
        if (*mn == Vector2(MOUSE->mousePosGameSpace.x - 10, MOUSE->mousePosGameSpace.y + 10))
        {
            one = mn;
        }

        if (*mn == Vector2(MOUSE->mousePosGameSpace.x - 10, MOUSE->mousePosGameSpace.y - 10))
        {
            two = mn;
        }

        if (*mn == Vector2(MOUSE->mousePosGameSpace.x + 10, MOUSE->mousePosGameSpace.y + 10))
        {
            three = mn;
        }

        if (*mn == Vector2(MOUSE->mousePosGameSpace.x + 10, MOUSE->mousePosGameSpace.y - 10))
        {
            four = mn;
        }
    }

    if (one == nullptr)
    {
        one = new MapNode(MOUSE->mousePosGameSpace.x - 10, MOUSE->mousePosGameSpace.y + 10);
        g_mapNodes.push_back(one);
    }

    if (two == nullptr)
    {
        two = new MapNode(MOUSE->mousePosGameSpace.x - 10, MOUSE->mousePosGameSpace.y - 10);
        g_mapNodes.push_back(two);
    }

    if (three == nullptr)
    {
        three = new MapNode(MOUSE->mousePosGameSpace.x + 10, MOUSE->mousePosGameSpace.y + 10);
        g_mapNodes.push_back(three);
    }

    if (four == nullptr)
    {
        four = new MapNode(MOUSE->mousePosGameSpace.x + 10, MOUSE->mousePosGameSpace.y - 10);
        g_mapNodes.push_back(four);
    }

    NavMeshNode * node = new NavMeshNode(*one, *two, *three, *four);
    
    MakeConnectionsToNode(node);

    g_NavNodes.push_back(node);
}

void NavManager::DestroyNode()
{
    NavMeshNode * n = nullptr;

    for each (NavMeshNode * N in g_NavNodes)
    {
        if (N->CheckIfInMeshBounds(MOUSE->mousePosGameSpace))
        {
            n = N;
        }
    }

    g_NavNodes.remove(n);

    delete n;
}

void NavManager::SwapDrawToNode()
{
    if (m_drawToNode == true)
    {
        m_drawToNode = false;
    }
    else
    {
        m_drawToNode = true;
    }
}

void NavManager::Draw(aie::Renderer2D * m_2dRenderer)
{
    for each (NavMeshNode * nav in g_NavNodes)
    {
        nav->Draw(m_2dRenderer);
    }


    for each (NavMeshNode * n in nodeTest)
    {
        m_2dRenderer->setRenderColour(1, 0, 0, 1);
        m_2dRenderer->drawCircle(n->GetCenter().x, n->GetCenter().y, 5);
    }

    if (MOUSE->mousestate == MouseState::States::INGAME)
    {
        m_2dRenderer->drawSprite(m_tileTexture[2], MOUSE->mousePosGameSpace.x, MOUSE->mousePosGameSpace.y, 19, 19);
    }

    m_2dRenderer->setRenderColour(1, 1, 1, 1);
}

NavMeshNode * NavManager::GetNode(Vector2 pos)
{
    for each (NavMeshNode * n in g_NavNodes)
    {
        if (n->CheckIfInMeshBounds(pos)) 
        {
            return n;
        }
    }

    return nullptr;
}

void NavManager::ClearParents()
{
	for each (NavMeshNode * n in g_NavNodes)
	{
		n->SetParent(nullptr);
	}
}

void NavManager::Slect()
{

}

void NavManager::Nothing()
{
}

std::list<NavMeshNode *> NavManager::GetEdgeConnections(NavMeshNode * node)
{
    std::list<NavMeshNode *> temp = std::list<NavMeshNode *>();

    for each (NavMeshNode::NavConnection * nc in node->g_connections)
    {
        if (nc->p_nodeA != node)
        {
            temp.push_back(nc->p_nodeA);
        }
        else
        {
            temp.push_back(nc->p_nodeB);
        }
    }

    return temp;
}