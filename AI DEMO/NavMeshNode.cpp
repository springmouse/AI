#include "NavMeshNode.h"



NavMeshNode::NavMeshNode()
{
}


NavMeshNode::NavMeshNode(SharedMapNodePtr one, SharedMapNodePtr two, SharedMapNodePtr three, SharedMapNodePtr four)
{
	//set our cornors
    m_upperLeftCornor   = one;
    m_lowerLeftCornor   = two;
    m_upperRightCornor  = three;
    m_lowerRightCornor  = four;

	//creat our edges
    m_WestEdge = SharedEdge(new MapEdges(one, two));
    m_SouthEdge = SharedEdge(new MapEdges(two, four));
    m_EastEdge = SharedEdge(new MapEdges(four, three));
    m_NorthEdge = SharedEdge(new MapEdges(three, one));

	//calculate the centerpoint
    CalculateCenter();

	//set passible to true by default
    m_isPassable = true;
}

NavMeshNode::~NavMeshNode()
{
}

void NavMeshNode::SetAllCornors(SharedMapNodePtr one, SharedMapNodePtr two, SharedMapNodePtr three, SharedMapNodePtr four)
{
	//sets all our cornors and recaculate the center point
    m_upperLeftCornor   = one;
    m_lowerLeftCornor   = two;
    m_upperRightCornor  = three;
    m_lowerRightCornor  = four;
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
	//draw the node
    m_2dRenderer->setRenderColour(0, 0.5f, 0.5f, 1);

    m_2dRenderer->drawBox(m_centerPoint.x, m_centerPoint.y, 19, 19);

    m_2dRenderer->setRenderColour(0.5f, 0, 0.5f, 1);

	//draw the nodes connections
    for each (sharedNavConnectionPtr nc in g_connections)
    {
        m_2dRenderer->drawLine(nc->p_nodeA.lock()->GetCenter().x, nc->p_nodeA.lock()->GetCenter().y, nc->p_nodeB.lock()->GetCenter().x, nc->p_nodeB.lock()->GetCenter().y);
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

void NavMeshNode::SetEdgesToTrue()
{
	m_NorthEdge->mapEdge = true;
	m_EastEdge->mapEdge = true;
	m_SouthEdge->mapEdge = true;
	m_WestEdge->mapEdge = true;
}

void NavMeshNode::DefineMapEdges()
{
	//goes throu its connections and checks for shared edges
    for each (sharedNavConnectionPtr conector in g_connections)
    {
        if (*this == conector->p_nodeA.lock())
        {
            CheckEdge(conector->p_nodeB);
        }

        if (*this == conector->p_nodeB.lock())
        {
            CheckEdge(conector->p_nodeA);
        }
    }
}

void NavMeshNode::CheckEdge(WeakMeshPtr nodeB)
{
	//if an edge is share then it is not a map edge
    if (*m_NorthEdge == nodeB.lock()->m_SouthEdge && nodeB.lock()->GetIsPasible())
    {
        m_NorthEdge->mapEdge = false;
        nodeB.lock()->m_SouthEdge->mapEdge = false;
    }

    if (*m_EastEdge == nodeB.lock()->m_WestEdge && nodeB.lock()->GetIsPasible())
    {
        m_EastEdge->mapEdge = false;
        nodeB.lock()->m_WestEdge->mapEdge = false;
    }

    if (*m_SouthEdge == nodeB.lock()->m_NorthEdge && nodeB.lock()->GetIsPasible())
    {
        m_SouthEdge->mapEdge = false;
        nodeB.lock()->m_NorthEdge->mapEdge = false;
    }

    if (*m_WestEdge == nodeB.lock()->m_EastEdge && nodeB.lock()->GetIsPasible())
    {
        m_WestEdge->mapEdge = false;
        nodeB.lock()->m_EastEdge->mapEdge = false;
    }
}

std::list<SharedEdge> NavMeshNode::GetMapEdges()
{
	//makes list of all edges on the node that are map edges
    std::list<SharedEdge> edges;

    if (m_NorthEdge->mapEdge)
    {
        edges.push_back(m_NorthEdge);
    }

    if (m_EastEdge->mapEdge)
    {
        edges.push_back(m_EastEdge);
    }

    if (m_SouthEdge->mapEdge)
    {
        edges.push_back(m_SouthEdge);
    }

    if (m_WestEdge->mapEdge)
    {
        edges.push_back(m_WestEdge);
    }

    return edges;
}

bool NavMeshNode::CheckIfMapNodeIsShared(SharedMapNodePtr mn)
{
	//returns true if a cornor is shared
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

void NavMeshNode::AddConnection(SharedMeshPtr nodeA, SharedMeshPtr nodeB)
{
    sharedNavConnectionPtr edge = sharedNavConnectionPtr(new NavConnection(nodeA, nodeB));
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

void NavMeshNode::DeleteAllConections(SharedMeshPtr me)
{
	//goes through all its connections deleting them and telling them to recalculate there edges
    for each (sharedNavConnectionPtr nc in g_connections)
    {
        if (nc->p_nodeA.lock() != me)
        {
            nc->p_nodeA.lock()->DeleteConection(nc);
			nc->p_nodeA.lock()->SetEdgesToTrue();
			nc->p_nodeA.lock()->DefineMapEdges();
			
        }
        else if (nc->p_nodeB.lock() != me)
        {
            nc->p_nodeB.lock()->DeleteConection(nc);
			nc->p_nodeB.lock()->SetEdgesToTrue();
			nc->p_nodeB.lock()->DefineMapEdges();
        }
    }

	//clears out list of connections
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
    float cost = (m_hCost + m_gCost);
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

void NavMeshNode::SetPassible(bool seter)
{
	m_isPassable = seter;

	//if it is no loner passible then we want all of its edges to be
	//map edges so Line of sight does not act weird
	if (m_isPassable == false)
	{
		m_NorthEdge->mapEdge = true;
		m_EastEdge->mapEdge = true;
		m_SouthEdge->mapEdge = true;
		m_WestEdge->mapEdge = true;
	}
	else
	{
		DefineMapEdges();
	}
}

WeakMeshPtr NavMeshNode::GetParent()
{
    return m_pParent.lock();
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

bool NavMeshNode::operator!=(const WeakMeshPtr other)
{
    if (other.lock()->GetCenter() == m_centerPoint)
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