#include "NavManager.h"
#include <iostream>



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

    Vector2 v = Vector2((int)INPUT->getMouseX(), (int)INPUT->getMouseY());
    v *= 0.05f;
    v = Vector2((int)v.x, (int)v.y);
    v *= 20;

    v.y -= 20;

    if (INPUT->isMouseButtonDown(0) && m_timer >= 0.2f)
    {
        CreatNewNode(v);
        m_timer = 0;
    }

    if (INPUT->isMouseButtonDown(1) && m_timer >= 0.2f)
    {
        DestroyNode(v);
        m_timer = 0;
    }

    if (INPUT->isMouseButtonDown(2))
    {
        finish = v;
    }



    m_pathTimer += deltaTime;
    if (INPUT->isKeyDown(aie::INPUT_KEY_SPACE) && m_pathTimer >= 1)
    {
		test.clear();
        test = PATH_FINDER->FindPath(start, finish);

		nodeTest.clear();

		for each (Vector2 v in test)
		{
			for each(Node * n in g_nodes)
			{
				if (*n == v)
				{
					nodeTest.push_back(n);
				}
			}
		}

        std::cout << "we ran";
        m_pathTimer = 0;
    }
}


void NavManager::CreatNewNode(Vector2 mousePos)
{
    for each (Node * n in g_nodes)
    {
        if (*n == mousePos)
        {
            return;
        }
    }

    Node * node = new Node(mousePos.x, mousePos.y);

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

void NavManager::DestroyNode(Vector2 mousePos)
{
    Node * n = nullptr;

    for each (Node * N in g_nodes)
    {
        if (*N == mousePos)
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
        m_2dRenderer->setRenderColour(n->GetRGB().x, n->GetRGB().y, n->GetRGB().z, n->GetRGB().w);
        m_2dRenderer->drawCircle(n->GetPos().x, n->GetPos().y, 5);
    }

	for each (Node * n in nodeTest)
	{
		m_2dRenderer->setRenderColour(1,0,0,1);
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