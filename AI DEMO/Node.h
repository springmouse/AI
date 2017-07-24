#pragma once
#include <list>
#include <Vector2.h>
#include <Vector4.h>

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

        bool operator== (const NodeEdge & other)
        {
            if (other.p_nodeA == p_nodeA && other.p_nodeB == p_nodeB)
            {
                return true;
            }

            return false;
        };

        float GetGCost() { return m_dCost; }

    };

    Node();
    Node(Vector2 v);
    Node(float x, float y);
    ~Node();

    void AddEdge(Node * nodeB);

    void DeleteAllEdges();

    void DeleteEdge(NodeEdge * ne);

    float GetFCost() const;

    float GetHCost() const;

    float GetGCost() const;

    void SetGCost(float set);

    void SetHCost(float set);

    void SetWeightCost(float set);

    bool GetIsPasible() const;

    Node * GetParent();

    void SetParent(Node * parent);

    bool operator== (const Node & other);

    bool operator== (Vector2 & other);

    Vector2 GetPos() { return m_pos; };

    Vector2 GetPos() const { return m_pos; };

    Vector4 GetRGB() { return m_colour; };
    void SetRGB(Vector4 colour) { m_colour = colour; };

    std::list<NodeEdge *> g_edges = std::list<NodeEdge *> ();

private:
    Vector2 m_pos;
    Vector4 m_colour;

    float m_gCost;
    float m_hCost;

    float weightCost;

    bool m_isPassable; /*this is our static passible bool a and represents things like this tile is a wall*/

    Node * m_pParent; /*this is the tiles parent used to find the path in the A* pathfinding calculations by retracing the path of parents leading from the end tile to the start tile*/
};

