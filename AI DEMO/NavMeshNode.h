#pragma once
#include "MapNode.h"
#include <list>
#include <Renderer2D.h>
#include "TypesAndDefines.h"

class NavMeshNode
{
public:


    class NavConnection
    {
    private:
        float m_dCost;

    public:
        NavConnection() {};

        NavConnection(SharedMeshPtr nodeA, SharedMeshPtr nodeB)
        {
            p_nodeA = nodeA;
            p_nodeB = nodeB;
        };

        ~NavConnection() {};

        SharedMeshPtr p_nodeA;
        SharedMeshPtr p_nodeB;

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
            if (other == p_nodeA || other == p_nodeB)
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


    typedef std::shared_ptr<NavConnection> sharedNavConnectionPtr;

    NavMeshNode();
    NavMeshNode(SharedMapNodePtr one, SharedMapNodePtr two, SharedMapNodePtr three, SharedMapNodePtr four);

    ~NavMeshNode();

    void SetAllCornors(SharedMapNodePtr one, SharedMapNodePtr two, SharedMapNodePtr three, SharedMapNodePtr four);

    void SetRightCornors(SharedMapNodePtr upper, SharedMapNodePtr lower);
    void SetLeftCornors(SharedMapNodePtr upper, SharedMapNodePtr lower);
    void SetUpperCornors(SharedMapNodePtr left, SharedMapNodePtr right);
    void SetLowerCornors(SharedMapNodePtr left, SharedMapNodePtr right);

    SharedMapNodePtr GetUpperLeft();
    SharedMapNodePtr GetLowerLeft();
    SharedMapNodePtr GetUpperRight();
    SharedMapNodePtr GetLowerRight();

    void Update(float deltaTime);

    bool CheckIfInMeshBounds(Vector2 & worldPos);

    void CalculateCenter();

    void Draw(aie::Renderer2D * m_2dRenderer);

    Vector2 GetCenter();

    Vector2 GetCenter() const;

    bool CheckIfMapNodeIsShared(SharedMapNodePtr mn);

    void AddConnection(SharedMeshPtr nodeB);

    bool CheckIfConectionExists(SharedMeshPtr nodeB);

    void DeleteAllConections();

    void DeleteConection(sharedNavConnectionPtr ne);

    float GetFCost() const;

    float GetHCost() const;

    float GetGCost() const;

    void SetGCost(float set);

    void SetHCost(float set);

    void ModifyWeightCost(float set);

    bool GetIsPasible() const;

    SharedMeshPtr GetParent();

    void SetParent(SharedMeshPtr parent);

    bool operator== (const SharedMeshPtr other);

    bool operator== (Vector2 & other);

    std::list<sharedNavConnectionPtr> g_connections;

private:
    
    SharedMapNodePtr m_upperLeftCornor;
    SharedMapNodePtr m_lowerLeftCornor;
    SharedMapNodePtr m_upperRightCornor;
    SharedMapNodePtr m_lowerRightCornor;

    Vector2 m_centerPoint;

    float m_gCost;
    float m_hCost;

    float timer;

    float m_weightCost;
    float m_previousWeightCost;
    float m_averageWeightCost;

    bool m_isPassable; /*this is our static passible bool a and represents things like this tile is a wall*/

    SharedMeshPtr m_pParent; /*this is the tiles parent used to find the path in the A* pathfinding calculations by retracing the path of parents leading from the end tile to the start tile*/
};

