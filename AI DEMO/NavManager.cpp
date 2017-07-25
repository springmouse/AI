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
            g_nodes.push_back(new Node(x * INFOMATION->nodeSize, y * INFOMATION->nodeSize));
        }
    }

    SetUpStartUpNodeConections();

    m_timer = 0;
    m_pathTimer = 0;

    start = Vector2(0, 0);
    finish = Vector2(0, 0);

    m_tileTexture[0] = new aie::Texture("./textures/Ground.png");
    m_tileTexture[1] = new aie::Texture("./textures/Wall.png");
    m_tileTexture[2] = new aie::Texture("./textures/Boarder.png");
}


NavManager::~NavManager()
{
}


void NavManager::SetUpStartUpNodeConections()
{
    for each (Node * nodeA in g_nodes)
    {
        int count = 0;
        for each (Node * nodeB in g_nodes)
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

void NavManager::Update(float deltaTime)
{
    m_timer += deltaTime;

    



    if (AIEINPUT->isMouseButtonDown(0) && m_timer >= 0.1f)
    {
        CreatNewNode();
        m_timer = 0;
    }

    if (AIEINPUT->isMouseButtonDown(1) && m_timer >= 0.1f)
    {
        DestroyNode();
        m_timer = 0;
    }

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
    for each (Node * n in g_nodes)
    {
        if (*n == MOUSE->mousePosGameSpace)
        {
            return;
        }
    }

    Node * node = new Node(MOUSE->mousePosGameSpace.x, MOUSE->mousePosGameSpace.y);

    for (int x = -1; x < 2; x++)
    {
        for (int y = -1; y < 2; y++)
        {
            if (x == 0 && y == 0)
            {
                continue;
            }

            for each (Node * n in g_nodes)
            {
                if (*n == Vector2(node->GetPos().x + (x * 20), node->GetPos().y + (y * 20)))
                {
                    node->AddEdge(n);
                }
            }
        }
    }

    g_nodes.push_back(node);
}

void NavManager::DestroyNode()
{
    Node * n = nullptr;

    for each (Node * N in g_nodes)
    {
        if (*N == MOUSE->mousePosGameSpace)
        {
            n = N;
        }
    }

    g_nodes.remove(n);

    delete n;
}

void NavManager::Draw(aie::Renderer2D * m_2dRenderer)
{
    for each (Node * n in g_nodes)
    {
        m_2dRenderer->drawSprite(m_tileTexture[0], n->GetPos().x, n->GetPos().y, 19, 19);
    }

    for each (Node * n in g_nodes)
    {
        m_2dRenderer->setRenderColour(n->GetRGB().x, n->GetRGB().y, n->GetRGB().z, n->GetRGB().w);
        m_2dRenderer->drawCircle(n->GetPos().x, n->GetPos().y, 5);
    }
    
    for each (Node * n in g_nodes)
    {
        for each(Node::NodeEdge * ne in n->g_edges)
        {
			m_2dRenderer->setRenderColour(1, 1, 1, 1);
            m_2dRenderer->drawLine(ne->p_nodeA->GetPos().x, ne->p_nodeA->GetPos().y, ne->p_nodeB->GetPos().x, ne->p_nodeB->GetPos().y, 1);
        }
    }

    for each (Node * n in nodeTest)
    {
        m_2dRenderer->setRenderColour(1, 0, 0, 1);
        m_2dRenderer->drawCircle(n->GetPos().x, n->GetPos().y, 5);
    }

    if (MOUSE->mousestate == MouseState::States::INGAME)
    {
        m_2dRenderer->drawSprite(m_tileTexture[2], MOUSE->mousePosGameSpace.x, MOUSE->mousePosGameSpace.y, 19, 19);
    }

    m_2dRenderer->setRenderColour(1, 1, 1, 1);
}

Node * NavManager::GetNode(Vector2 pos)
{
    for each (Node * n in g_nodes)
    {
        if (* n == pos) 
        {
            return n;
        }
    }

    
    return nullptr;
}

void NavManager::ClearParents()
{
	for each (Node * n in g_nodes)
	{
		n->SetParent(nullptr);
	}
}

std::list<Node *> NavManager::GetEdgeConnections(Node * node)
{
    std::list<Node *> temp = std::list<Node *>();

    for each (Node::NodeEdge * ne in node->g_edges)
    {
        if (ne->p_nodeA != node)
        {
            temp.push_back(ne->p_nodeA);
        }
        else
        {
            temp.push_back(ne->p_nodeB);
        }
    }

    return temp;
}