#include "MapNode.h"

MapNode::MapNode(Vector2 pos)
{
    m_pos = pos;
}

MapNode::MapNode(float x, float y)
{
    m_pos = Vector2(x, y);
}

MapNode::~MapNode()
{
}

bool MapNode::operator==(MapNode & other)
{
    if (other.m_pos == m_pos)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool MapNode::operator==(Vector2 & other)
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