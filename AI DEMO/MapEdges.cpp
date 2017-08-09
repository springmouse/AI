#include "MapEdges.h"

MapEdges::MapEdges(WeakMapNodePtr one, WeakMapNodePtr two)
{
    pointOne = one;
    pointTwo = two;

    mapEdge = true;
}

MapEdges::~MapEdges()
{
}

bool MapEdges::operator==(const SharedEdge other)
{
    int count = 0;
    if ((*pointOne.lock() == other->pointOne.lock() || *pointOne.lock() == other->pointTwo.lock()))
    {
        count++;
    }

    if ((*pointTwo.lock() == other->pointOne.lock() || *pointTwo.lock() == other->pointTwo.lock()))
    {
        count++;
    }

    if (count == 2)
    {
        return true;
    }

    return false;

}

void MapEdges::Draw(aie::Renderer2D * m_2dRenderer)
{
    if (mapEdge)
    {
        m_2dRenderer->setRenderColour(0, 1, 0, 1);
        m_2dRenderer->drawLine(pointOne.lock()->m_pos.x, pointOne.lock()->m_pos.y, pointTwo.lock()->m_pos.x, pointTwo.lock()->m_pos.y);
        m_2dRenderer->setRenderColour(1, 1, 1, 1);
    }
}
