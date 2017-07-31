#include "NavMeshNode.h"



NavMeshNode::NavMeshNode()
{
}


NavMeshNode::NavMeshNode(MapNode & one, MapNode & two, MapNode & three, MapNode & four)
{
    m_upperLeftCornor   = & one;
    m_lowerLeftCornor   = & two;
    m_upperRightCornor  = & three;
    m_lowerRightCornor  = & four;

    CalculateCenter();

    m_isPassable = true;
}

NavMeshNode::~NavMeshNode()
{
    DeleteAllConections();
}

void NavMeshNode::SetAllCornors(MapNode & one, MapNode & two, MapNode & three, MapNode & four)
{
    m_upperLeftCornor = &one;
    m_lowerLeftCornor = &two;
    m_upperRightCornor = &three;
    m_lowerRightCornor = &four;

    CalculateCenter();
}

void NavMeshNode::SetRightCornors(MapNode & upper, MapNode & lower)
{
    m_upperRightCornor = & upper;
    m_lowerRightCornor = & lower;
    CalculateCenter();
}

void NavMeshNode::SetLeftCornors(MapNode & upper, MapNode & lower)
{
    m_upperLeftCornor = & upper;
    m_lowerLeftCornor = & lower;
    CalculateCenter();
}

void NavMeshNode::SetUpperCornors(MapNode & left, MapNode & right)
{
    m_upperLeftCornor   = & left;
    m_upperRightCornor  = & right;
    CalculateCenter();
}

void NavMeshNode::SetLowerCornors(MapNode & left, MapNode & right)
{
    m_lowerLeftCornor   = & left;
    m_lowerRightCornor  = & right;
    CalculateCenter();
}

MapNode * NavMeshNode::GetUpperLeft()
{
    return m_upperLeftCornor;
}

MapNode * NavMeshNode::GetLowerLeft()
{
    return m_lowerLeftCornor;
}

MapNode * NavMeshNode::GetUpperRight()
{
    return m_upperRightCornor;
}

MapNode * NavMeshNode::GetLowerRight()
{
    return m_lowerRightCornor;
}

bool NavMeshNode::CheckIfInMeshBounds(Vector2 & worldPos)
{
    if (worldPos.x >= m_lowerLeftCornor->m_pos.x && worldPos.x <= m_upperRightCornor->m_pos.x
        && worldPos.y >= m_lowerLeftCornor->m_pos.y && worldPos.y <= m_upperRightCornor->m_pos.y)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void NavMeshNode::CalculateCenter()
{
    m_centerPoint.x = (m_lowerLeftCornor->m_pos.x + m_upperRightCornor->m_pos.x) * 0.5f;
    m_centerPoint.y = (m_lowerLeftCornor->m_pos.y + m_upperRightCornor->m_pos.y) * 0.5f;
}

void NavMeshNode::Draw(aie::Renderer2D * m_2dRenderer)
{
    m_2dRenderer->setRenderColour(0, 0.5f, 0.5f, 1);

    m_2dRenderer->drawBox(m_centerPoint.x, m_centerPoint.y, 19, 19);

    m_2dRenderer->setRenderColour(0.5f, 0, 0.5f, 1);

    for each (NavConnection * nc in g_connections)
    {
        m_2dRenderer->drawLine(nc->p_nodeA->GetCenter().x, nc->p_nodeA->GetCenter().y, nc->p_nodeB->GetCenter().x, nc->p_nodeB->GetCenter().y);
    }

    m_2dRenderer->setRenderColour(1, 1, 1, 1);
}

Vector2 NavMeshNode::GetCenter()
{
    return m_centerPoint;
}

Vector2 NavMeshNode::GetCenter() const
{
    return m_centerPoint;
}

bool NavMeshNode::CheckIfMapNodeIsShared(MapNode * mn)
{
    if (*mn == *m_upperLeftCornor)
    {
        return true;
    }

    if (*mn == *m_lowerLeftCornor)
    {
        return true;
    }

    if (*mn == *m_upperRightCornor)
    {
        return true;
    }

    if (*mn == *m_lowerRightCornor)
    {
        return true;
    }

    return false;
}

void NavMeshNode::AddConnection(NavMeshNode * nodeB)
{
    NavConnection * edge = new NavConnection(this, nodeB);
    g_connections.push_back(edge);
    nodeB->g_connections.push_back(edge);
}

bool NavMeshNode::CheckIfConectionExists(NavMeshNode * nodeB)
{
    for each (NavConnection * navConnection in g_connections)
    {
        if (*navConnection == *nodeB)
        {
            return true;
        }
    }
    
    return false;
}

void NavMeshNode::DeleteAllConections()
{
    for each (NavConnection * nc in g_connections)
    {
        if (nc->p_nodeA != this)
        {
            nc->p_nodeA->DeleteConection(nc);
        }
        else if (nc->p_nodeB != this)
        {
            nc->p_nodeB->DeleteConection(nc);
        }
    }

    g_connections.clear();
}

void NavMeshNode::DeleteConection(NavConnection * ne)
{
    g_connections.remove(ne);
}

bool NavMeshNode::GetIsPasible() const
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

float NavMeshNode::GetFCost() const
{
    float cost = (m_hCost + m_gCost + weightCost);
    return cost;
}

float NavMeshNode::GetHCost() const
{
    return m_hCost;
}

float NavMeshNode::GetGCost() const
{
    return m_gCost;
}

void NavMeshNode::SetGCost(float set)
{
    m_gCost = set;
}

void NavMeshNode::SetHCost(float set)
{
    m_hCost = set;
}

void NavMeshNode::SetWeightCost(float set)
{
    weightCost += set;
}

NavMeshNode * NavMeshNode::GetParent()
{
    return m_pParent;
}

void NavMeshNode::SetParent(NavMeshNode * parent)
{
    m_pParent = parent;
}

bool NavMeshNode::operator==(const NavMeshNode & other)
{
    if (other.GetCenter() == m_centerPoint)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool NavMeshNode::operator==(Vector2 & other)
{
    if (other == m_centerPoint)
    {
        return true;
    }
    else
    {
        return false;
    }

}