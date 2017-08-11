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
    CreatNavMesh();
    SetUpStartUpNodeConections();
    CreatEdges();
    GatherEdges();

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
    for each (SharedMapNodePtr nodeA in g_mapNodes)
    {
        SharedMapNodePtr one = nullptr;

        SharedMapNodePtr two = nodeA;

        SharedMapNodePtr three = nullptr;
        SharedMapNodePtr four = nullptr;

        int count = 0;
        for each (SharedMapNodePtr nodeB in g_mapNodes)
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
                g_NavNodes.push_back(SharedMeshPtr(new NavMeshNode(one, two, three, four)));
                break;
            }
        }
    }
}

void NavManager::CreatEdges()
{
    for each (SharedMeshPtr nav in g_NavNodes)
    {
        nav->DefineMapEdges();
    }
    
}

void NavManager::GatherEdges()
{
	g_mapEdges.clear();

    for each (SharedMeshPtr node in g_NavNodes)
    {
        for each (SharedEdge edge in node->GetMapEdges())
        {
            g_mapEdges.push_back(edge);
        }
    }
}

void NavManager::SetUpStartUpNodeConections()
{
    for each (SharedMeshPtr nodeA in g_NavNodes)
    {
        for each (SharedMeshPtr nodeB in g_NavNodes)
        {
            if (nodeA != nodeB)
            {
                if (nodeA->CheckIfMapNodeIsShared(nodeB->GetUpperLeft()) && nodeA->CheckIfMapNodeIsShared(nodeB->GetUpperRight()))
                {
                    if (nodeA->CheckIfConectionExists(nodeB) == false)
                    {
                        nodeA->AddConnection(nodeA, nodeB);
                    }
                }
                
                if (nodeA->CheckIfMapNodeIsShared(nodeB->GetLowerLeft()) && nodeA->CheckIfMapNodeIsShared(nodeB->GetUpperLeft()))
                {
                    if (nodeA->CheckIfConectionExists(nodeB) == false)
                    {
                        nodeA->AddConnection(nodeA, nodeB);
                    }                    
                }

                if (nodeA->CheckIfMapNodeIsShared(nodeB->GetUpperRight()) && nodeA->CheckIfMapNodeIsShared(nodeB->GetLowerRight()))
                {
                    if (nodeA->CheckIfConectionExists(nodeB) == false)
                    {
                        nodeA->AddConnection(nodeA,nodeB);
                    }                    
                }

                if (nodeA->CheckIfMapNodeIsShared(nodeB->GetLowerRight()) && nodeA->CheckIfMapNodeIsShared(nodeB->GetLowerLeft()))
                {
                    if (nodeA->CheckIfConectionExists(nodeB) == false)
                    {
                        nodeA->AddConnection(nodeA, nodeB);
                    }
                }
            }
        }
    }
}

void NavManager::MakeConnectionsToNode(SharedMeshPtr nodeA)
{
    for each (SharedMeshPtr nodeB in g_NavNodes)
    {
        if (nodeA != nodeB)
        {
            if (nodeA->CheckIfMapNodeIsShared(nodeB->GetUpperLeft()) && nodeA->CheckIfMapNodeIsShared(nodeB->GetUpperRight()))
            {
                if (nodeA->CheckIfConectionExists(nodeB) == false)
                {
                    nodeA->AddConnection(nodeA, nodeB);
                }
            }

            if (nodeA->CheckIfMapNodeIsShared(nodeB->GetLowerLeft()) && nodeA->CheckIfMapNodeIsShared(nodeB->GetUpperLeft()))
            {
                if (nodeA->CheckIfConectionExists(nodeB) == false)
                {
                    nodeA->AddConnection(nodeA, nodeB);
                }
            }

            if (nodeA->CheckIfMapNodeIsShared(nodeB->GetUpperRight()) && nodeA->CheckIfMapNodeIsShared(nodeB->GetLowerRight()))
            {
                if (nodeA->CheckIfConectionExists(nodeB) == false)
                {
                    nodeA->AddConnection(nodeA, nodeB);
                }
            }

            if (nodeA->CheckIfMapNodeIsShared(nodeB->GetLowerRight()) && nodeA->CheckIfMapNodeIsShared(nodeB->GetLowerLeft()))
            {
                if (nodeA->CheckIfConectionExists(nodeB) == false)
                {
                    nodeA->AddConnection(nodeA, nodeB);
                }
            }
        }
    }
}

void NavManager::Update(float deltaTime)
{
    for each (SharedMeshPtr nav in g_NavNodes)
    {
        nav->Update(deltaTime);
    }

    m_pathTimer += deltaTime;
}


void NavManager::CreatNewNode()
{
    for each (SharedMeshPtr n in g_NavNodes)
    {
        if (n->CheckIfInMeshBounds(MOUSE->mousePosGameSpace))
        {
            return;
        }
    }

    SharedMapNodePtr one = nullptr;
    SharedMapNodePtr two = nullptr;
    SharedMapNodePtr three = nullptr;
    SharedMapNodePtr four = nullptr;

    for each (SharedMapNodePtr mn  in g_mapNodes)
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
        one = SharedMapNodePtr(new MapNode(MOUSE->mousePosGameSpace.x - 10, MOUSE->mousePosGameSpace.y + 10));
        g_mapNodes.push_back(one);
    }

    if (two == nullptr)
    {
        two = SharedMapNodePtr(new MapNode(MOUSE->mousePosGameSpace.x - 10, MOUSE->mousePosGameSpace.y - 10));
        g_mapNodes.push_back(two);
    }

    if (three == nullptr)
    {
        three = SharedMapNodePtr(new MapNode(MOUSE->mousePosGameSpace.x + 10, MOUSE->mousePosGameSpace.y + 10));
        g_mapNodes.push_back(three);
    }

    if (four == nullptr)
    {
        four = SharedMapNodePtr(new MapNode(MOUSE->mousePosGameSpace.x + 10, MOUSE->mousePosGameSpace.y - 10));
        g_mapNodes.push_back(four);
    }

    SharedMeshPtr node = SharedMeshPtr(new NavMeshNode(one, two, three, four));
    
    MakeConnectionsToNode(node);
	
    g_NavNodes.push_back(node);
    
	node->DefineMapEdges();

	GatherEdges();

}

void NavManager::DestroyNode()
{
    SharedMeshPtr n = nullptr;

    for each (SharedMeshPtr N in g_NavNodes)
    {
        if (N->CheckIfInMeshBounds(MOUSE->mousePosGameSpace))
        {
            n = N;
        }
    }

    if (n != nullptr)
    {
        n->DeleteAllConections(n);
        g_NavNodes.remove(n);
		GatherEdges();
    }

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
   

    for each (SharedMeshPtr nav in g_NavNodes)
    {
        nav->Draw(m_2dRenderer);
    }

    for each (SharedMeshPtr n in nodeTest)
    {
        m_2dRenderer->setRenderColour(1, 0, 0, 1);
        m_2dRenderer->drawCircle(n->GetCenter().x, n->GetCenter().y, 5);
    }

    for each (SharedEdge edge in g_mapEdges)
    {
        edge->Draw(m_2dRenderer);
    }

    if (MOUSE->mousestate == MouseState::States::INGAME)
    {
        m_2dRenderer->drawSprite(m_tileTexture[2], MOUSE->mousePosGameSpace.x, MOUSE->mousePosGameSpace.y, 19, 19);
    }

    m_2dRenderer->setRenderColour(1, 1, 1, 1);
}

SharedMeshPtr NavManager::GetNode(Vector2 pos)
{
    for each (SharedMeshPtr n in g_NavNodes)
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
	for each (SharedMeshPtr n in g_NavNodes)
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

std::list<SharedMeshPtr> NavManager::GetEdgeConnections(SharedMeshPtr node)
{
    std::list<SharedMeshPtr> temp = std::list<SharedMeshPtr>();

    for each (NavMeshNode::sharedNavConnectionPtr nc in node->g_connections)
    {
        if (nc->p_nodeA.lock() != node)
        {
            temp.push_back(nc->p_nodeA.lock());
        }
        else
        {
            temp.push_back(nc->p_nodeB.lock());
        }
    }

    return temp;
}