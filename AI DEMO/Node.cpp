#include "Node.h"



Node::Node()
{
}

Node::Node(float x, float y)
{
    m_pos = Vector2(x, y);
}


Node::~Node()
{
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
