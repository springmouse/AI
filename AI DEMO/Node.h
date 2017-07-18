#pragma once
#include <list>
#include <Vector2.h>

class Node
{
public:

    class NodeEdge
    {
    private:
        float m_gCost;

    public:
        NodeEdge() {};
        ~NodeEdge() {};

        Node * p_nodeA;
        Node * p_nodeB;

        float GetGCost() { return m_gCost; }

    };

    Node();
    ~Node();

    std::list<NodeEdge *> g_edges = std::list<NodeEdge *> ();

};

