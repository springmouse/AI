#include "NavMeshNode.h"



NavMeshNode::NavMeshNode()
{
}


NavMeshNode::NavMeshNode(SharedMapNodePtr one, SharedMapNodePtr two, SharedMapNodePtr three, SharedMapNodePtr four)
{
    m_upperLeftCornor   = one;
    m_lowerLeftCornor   = two;
    m_upperRightCornor  = three;
    m_lowerRightCornor  = four;

    CalculateCenter();

    m_isPassable = true;

    timer = 0;
    m_weightCost = 0;
    m_previousWeightCost = 0;
    m_averageWeightCost = 0;
}

NavMeshNode::~NavMeshNode()
{
    DeleteAllConections();
}

void NavMeshNode::SetAllCornors(SharedMapNodePtr one, SharedMapNodePtr two, SharedMapNodePtr three, SharedMapNodePtr four)
{
    m_upperLeftCornor   = one;
    m_lowerLeftCornor   = two;
    m_upperRightCornor  = three;
    m_lowerRightCornor  = four;
    CalculateCenter();
}

void NavMeshNode::SetRightCornors(SharedMapNodePtr upper, SharedMapNodePtr lower)
{
    m_upperRightCornor = upper;
    m_lowerRightCornor = lower;
    CalculateCenter();
}
void NavMeshNode::SetLeftCornors(SharedMapNodePtr upper, SharedMapNodePtr lower)
{
    m_upperLeftCornor = upper;
    m_lowerLeftCornor = lower;
    CalculateCenter();
}
void NavMeshNode::SetUpperCornors(SharedMapNodePtr left, SharedMapNodePtr right)
{
    m_upperLeftCornor   = left;
    m_upperRightCornor  = right;
    CalculateCenter();
}
void NavMeshNode::SetLowerCornors(SharedMapNodePtr left, SharedMapNodePtr right)
{
    m_lowerLeftCornor   = left;
    m_lowerRightCornor  = right;
    CalculateCenter();
}

SharedMapNodePtr NavMeshNode::GetUpperLeft()
{
    return m_upperLeftCornor;
}
SharedMapNodePtr NavMeshNode::GetLowerLeft()
{
    return m_lowerLeftCornor;
}
SharedMapNodePtr NavMeshNode::GetUpperRight()
{
    return m_upperRightCornor;
}
SharedMapNodePtr NavMeshNode::GetLowerRight()
{
    return m_lowerRightCornor;
}

void NavMeshNode::Update(float deltaTime)
{
    timer += deltaTime;

    if (timer >= 1)
    {
        m_averageWeightCost = (m_previousWeightCost + m_weightCost) * 0.5f;
        m_previousWeightCost = m_weightCost;
        timer = 0;
    }
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
    float num = sqrt(m_averageWeightCost * m_averageWeightCost);

    num *= 0.2;

    m_2dRenderer->setRenderColour(num, 0.5f, 0.5f, 1);

    m_2dRenderer->drawBox(m_centerPoint.x, m_centerPoint.y, 19, 19);

    m_2dRenderer->setRenderColour(0.5f, 0, 0.5f, 1);

    for each (sharedNavConnectionPtr nc in g_connections)
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

bool NavMeshNode::CheckIfMapNodeIsShared(SharedMapNodePtr mn)
{
    if (mn == m_upperLeftCornor)
    {
        return true;
    }

    if (mn == m_lowerLeftCornor)
    {
        return true;
    }

    if (mn == m_upperRightCornor)
    {
        return true;
    }

    if (mn == m_lowerRightCornor)
    {
        return true;
    }

    return false;
}

void NavMeshNode::AddConnection(SharedMeshPtr nodeB)
{
    sharedNavConnectionPtr edge = sharedNavConnectionPtr(new NavConnection(SharedMeshPtr(this), nodeB));
    g_connections.push_back(edge);
    nodeB->g_connections.push_back(edge);
}

bool NavMeshNode::CheckIfConectionExists(SharedMeshPtr nodeB)
{
    for each (sharedNavConnectionPtr navConnection in g_connections)
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
    for each (sharedNavConnectionPtr nc in g_connections)
    {
        if (nc->p_nodeA != SharedMeshPtr(this))
        {
            nc->p_nodeA->DeleteConection(nc);
        }
        else if (nc->p_nodeB != SharedMeshPtr(this))
        {
            nc->p_nodeB->DeleteConection(nc);
        }
    }

    g_connections.clear();
}

void NavMeshNode::DeleteConection(sharedNavConnectionPtr ne)
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
    float cost = (m_hCost + m_gCost + m_averageWeightCost);
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

void NavMeshNode::ModifyWeightCost(float set)
{
    m_weightCost += set;
}

SharedMeshPtr NavMeshNode::GetParent()
{
    return m_pParent;
}

void NavMeshNode::SetParent(SharedMeshPtr parent)
{
    m_pParent = parent;
}

bool NavMeshNode::operator==(const SharedMeshPtr other)
{
    if (other->GetCenter() == m_centerPoint)
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