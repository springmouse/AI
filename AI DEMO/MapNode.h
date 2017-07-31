#pragma once
#include <Vector2.h>

class MapNode
{
public:
    MapNode(Vector2 pos);
    MapNode(float x, float y);

    ~MapNode();

    bool operator== (MapNode & other);

    bool operator== (Vector2 & other);

    Vector2 m_pos;
};
