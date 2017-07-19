#pragma once
#include <list>
#include <Vector2.h>

class Node
{
public:

    class NodeEdge
    {
    private:
        float m_dCost;

    public:
        NodeEdge() {};

        NodeEdge(Node * nodeA, Node * nodeB) 
        { 
            p_nodeA = nodeA;
            p_nodeB = nodeB; 
        };

        ~NodeEdge() {};

        Node * p_nodeA;
        Node * p_nodeB;

        float GetGCost() { return m_dCost; }

    };

    Node();
    Node(float x, float y);
    ~Node();

    void AddEdge(Node * nodeB)
    {
        NodeEdge * edge = new NodeEdge(this, nodeB);
        g_edges.push_back(edge);
        nodeB->g_edges.push_back(edge);
    };

    bool operator== (const Node & other);
    bool operator== (Vector2 & other);

    Vector2 GetPos() { return m_pos; };

    Vector2 GetPos() const { return m_pos; };

    std::list<NodeEdge *> g_edges = std::list<NodeEdge *> ();

private:
    Vector2 m_pos;

    float m_gcost;
    float m_hcost;
};

