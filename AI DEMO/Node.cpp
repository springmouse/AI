#include "Node.h"



Node::Node()
{
    weightCost = 0;
    m_colour = Vector4(1,1,1,1);
    m_isPassable = true;
}

Node::Node(Vector2 v)
{
    m_pos = v;
    m_colour = Vector4(1, 1, 1, 1);
    weightCost = 0;
    m_isPassable = true;
}

Node::Node(float x, float y)
{
    m_pos = Vector2(x, y);
    m_colour = Vector4(1, 1, 1, 1);
    weightCost = 0;
    m_isPassable = true;
}

Node::~Node()
{
    DeleteAllEdges();
}

void Node::AddEdge(Node * nodeB)
{
    NodeEdge * edge = new NodeEdge(this, nodeB);
    g_edges.push_back(edge);
    nodeB->g_edges.push_back(edge);
}

void Node::DeleteAllEdges()
{
    for each (NodeEdge * ne in g_edges)
    {
        if (ne->p_nodeA != this)
        {
            ne->p_nodeA->DeleteEdge(ne);
        }
        else if (ne->p_nodeB != this)
        {
            ne->p_nodeB->DeleteEdge(ne);
        }
    }

    g_edges.clear();
}

void Node::DeleteEdge(NodeEdge * ne)
{
    g_edges.remove(ne);
}

bool Node::GetIsPasible() const
{
    if (m_isPassable)
    {
        return true;
    }
    else
    {
        return false;
    }
}

float Node::GetFCost() const
{
    return (m_hCost + m_gCost + weightCost);
}

float Node::GetHCost() const
{
    return m_hCost;
}

float Node::GetGCost() const
{
    return m_gCost;
}


void Node::SetGCost(float set)
{
    m_gCost = set;
}

void Node::SetHCost(float set)
{
    m_hCost = set;
}

void Node::SetWeightCost(float set)
{
    weightCost += set;
}


Node * Node::GetParent()
{
    return m_pParent;
}

void Node::SetParent(Node * parent)
{
    m_pParent = parent;
}

bool Node::operator==(const Node & other)
{
    if (other.GetPos() == m_pos)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Node::operator==(Vector2 & other)
{
    if (other == m_pos)
    {
        return true;
    }
    else
    {
        return false;
    }

}
