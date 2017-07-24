#include "Node.h"



Node::Node()
{
}

Node::Node(Vector2 v)
{
    m_pos = v;
}

Node::Node(float x, float y)
{
    m_pos = Vector2(x, y);
}


Node::~Node()
{
    DeleteAllEdges();
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
