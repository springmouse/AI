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
    m_tileTexture[0] = new aie::Texture("./textures/Ground.png");
    m_tileTexture[1] = new aie::Texture("./textures/Wall.png");
    m_tileTexture[2] = new aie::Texture("./textures/Boarder.png");
}

NavManager::~NavManager()
{
}

void NavManager::GatherEdges()
{
	//clears the list then get all map edges
	//so we dont have doubling up or ghosts
	g_mapEdges.clear();

    for each (SharedMeshPtr node in g_NavNodes)
    {
        for each (SharedEdge edge in node->GetMapEdges())
        {
            g_mapEdges.push_back(edge);
        }
    }
}

void NavManager::MakeConnectionsToNode(SharedMeshPtr nodeA)
{
	//go through all the nodes checking their endges agains the one passed in
	//if an edge is shared check that there is not all ready a connection between them
	//if no connection we the add one
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

void NavManager::CreatNewNode()
{
	//make sure we are not trying to place a node ontop of another node
    for each (SharedMeshPtr n in g_NavNodes)
    {
        if (n->CheckIfInMeshBounds(MOUSE->mousePosGameSpace))
        {
            return;
        }
    }

	//start off gathering our cornors for the node
    SharedMapNodePtr one = nullptr;
    SharedMapNodePtr two = nullptr;
    SharedMapNodePtr three = nullptr;
    SharedMapNodePtr four = nullptr;

	////go through the g_mapNodesto see if any of our cornors already exist
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

	//if any of them dont we creat some new ones
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

	//create the new node now
    SharedMeshPtr node = SharedMeshPtr(new NavMeshNode(one, two, three, four));
    
	//find create its connections to other nodes
    MakeConnectionsToNode(node);
	
	//add it to the list of nodes
    g_NavNodes.push_back(node);
    
	//define its map edges wich also redefines and nodes map edges that it is touching
	node->DefineMapEdges();

	//gather the new map edges
	GatherEdges();

}

void NavManager::DestroyNode()
{
    SharedMeshPtr n = nullptr;

	//get the node
    for each (SharedMeshPtr N in g_NavNodes)
    {
        if (N->CheckIfInMeshBounds(MOUSE->mousePosGameSpace))
        {
            n = N;
        }
    }

	//make sure we actually have a node
    if (n != nullptr)
    {
		//delet its connections
        n->DeleteAllConections(n);
		//remove it
        g_NavNodes.remove(n);

		//go back through all the nodes and reset ones that where not passible
		//to not being passible to set all their edges to map edges (this is a bit of a cheaty way to do it)
		//we need to do this otherwise map edges are not assigned properly
		for each (SharedMeshPtr node in g_NavNodes)
		{
			if (node->GetIsPasible() == false)
			{
				node->SetPassible(false);
			}
		}

		//regather all edges
		GatherEdges();
    }

}

void NavManager::Draw(aie::Renderer2D * m_2dRenderer)
{
	//draw the NavMeshNodes
    for each (SharedMeshPtr nav in g_NavNodes)
    {
        nav->Draw(m_2dRenderer);
    }

	//draw the map edges
    for each (SharedEdge edge in g_mapEdges)
    {
        edge->Draw(m_2dRenderer);
    }

	//draw the map coursor
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