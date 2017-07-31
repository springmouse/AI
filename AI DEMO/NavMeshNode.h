#pragma once
#include "MapNode.h"
#include <list>
#include <Renderer2D.h>

class NavMeshNode
{
public:

    class NavConnection
    {
    private:
        float m_dCost;

    public:
        NavConnection() {};

        NavConnection(NavMeshNode * nodeA, NavMeshNode * nodeB)
        {
            p_nodeA = nodeA;
            p_nodeB = nodeB;
        };

        ~NavConnection() {};

        NavMeshNode * p_nodeA;
        NavMeshNode * p_nodeB;

        bool operator== (const NavConnection & other)
        {
            if (other.p_nodeA == p_nodeA && other.p_nodeB == p_nodeB)
            {
                return true;
            }

            return false;
        };

        bool operator== (NavMeshNode & other)
        {
            if (other == *p_nodeA || other == *p_nodeB)
            {
                return true;
            }

            return false;
        };

        float GetDCost() 
        { 
            m_dCost = p_nodeA->m_centerPoint.magnitude() - p_nodeB->m_centerPoint.magnitude();
            
            m_dCost = (m_dCost * m_dCost) * 0.5f;

            return  m_dCost;
        }

    };

    NavMeshNode();
    NavMeshNode(MapNode & one, MapNode & two, MapNode & three, MapNode & four);

    ~NavMeshNode();

    void SetAllCornors(MapNode & one, MapNode & two, MapNode & three, MapNode & four);

    void SetRightCornors(MapNode & upper, MapNode & lower);
    void SetLeftCornors(MapNode & upper, MapNode & lower);
    void SetUpperCornors(MapNode & left, MapNode & right);
    void SetLowerCornors(MapNode & left, MapNode & right);

    MapNode * GetUpperLeft();
    MapNode * GetLowerLeft();
    MapNode * GetUpperRight();
    MapNode * GetLowerRight();

    bool CheckIfInMeshBounds(Vector2 & worldPos);

    void CalculateCenter();

    void Draw(aie::Renderer2D * m_2dRenderer);

    Vector2 GetCenter();

    Vector2 GetCenter() const;

    bool CheckIfMapNodeIsShared(MapNode * mn);

    void AddConnection(NavMeshNode * nodeB);

    bool CheckIfConectionExists(NavMeshNode * nodeB);

    void DeleteAllConections();

    void DeleteConection(NavConnection * ne);

    float GetFCost() const;

    float GetHCost() const;

    float GetGCost() const;

    void SetGCost(float set);

    void SetHCost(float set);

    void SetWeightCost(float set);

    bool GetIsPasible() const;

    NavMeshNode * GetParent();

    void SetParent(NavMeshNode * parent);

    bool operator== (const NavMeshNode & other);

    bool operator== (Vector2 & other);

    std::list<NavConnection *> g_connections;

private:
    
    MapNode * m_upperLeftCornor;
    MapNode * m_lowerLeftCornor;
    MapNode * m_upperRightCornor;
    MapNode * m_lowerRightCornor;

    Vector2 m_centerPoint;

    float m_gCost;
    float m_hCost;

    float weightCost;

    bool m_isPassable; /*this is our static passible bool a and represents things like this tile is a wall*/

    NavMeshNode * m_pParent; /*this is the tiles parent used to find the path in the A* pathfinding calculations by retracing the path of parents leading from the end tile to the start tile*/
};

