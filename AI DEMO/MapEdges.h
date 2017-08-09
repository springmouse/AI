#pragma once
#include "MapNode.h"
#include "TypesAndDefines.h"
#include <Renderer2D.h>

class MapEdges
{
public:
    MapEdges(WeakMapNodePtr one, WeakMapNodePtr two);
    ~MapEdges();

    bool operator== (const SharedEdge other);

    void Draw(aie::Renderer2D * m_2dRenderer);

    WeakMapNodePtr pointOne;
    WeakMapNodePtr pointTwo;

    bool mapEdge;
};

