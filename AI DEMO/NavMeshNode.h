#pragma once
#include "MapNode.h"
#include <list>
#include <Renderer2D.h>
#include "TypesAndDefines.h"
#include "MapEdges.h"

/*
* Class: NavMeshNode
* ------------------
*
* NavMeshNode makes up the map that the everthing sits on or moves about on
*
* Author: Callum Dunstone
*/
class NavMeshNode
{
public:

	/*
	* Class: NavConnection
	* --------------------
	*
	* NavConnections are what connects the NavMeshNodes together
	* allowing the pathfinder to search through them
	*
	* Author: Callum Dunstone
	*/
    class NavConnection
    {
    public:

		/*
		* Function: Constructor
		* ---------------------
		*
		* constructor that takes in two SharedMeshPtr to set up its connection between them 
		*
		*/
        NavConnection(SharedMeshPtr nodeA, SharedMeshPtr nodeB)
        {
            p_nodeA = WeakMeshPtr(nodeA);
            p_nodeB = WeakMeshPtr(nodeB);
        };

		/*
		* Function: DeConstructer
		* ------------------------
		*
		* Default deConstructor.
		*
		*/
        ~NavConnection() {};

        WeakMeshPtr p_nodeA; /*NodeA it is connected to*/
        WeakMeshPtr p_nodeB; /*nodeB it is connect to*/

		/*
		* operator== (const NavConnection & other)
		* ----------------------------------------
		*
		* chechs if a nave connection has the same node ptr
		* returns true if they do
		*
		*/
        bool operator== (const NavConnection & other)
        {
            if (other.p_nodeA.lock() == p_nodeA.lock() && other.p_nodeB.lock() == p_nodeB.lock())
            {
                return true;
            }

            return false;
        };

		/*
		* operator== (NavMeshNode & other)
		* --------------------------------
		*
		* checks if we have a connection with the node passed in
		* returns true if we do
		*
		*/
        bool operator== (NavMeshNode & other)
        {
            if (other == p_nodeA.lock() || other == p_nodeB.lock())
            {
                return true;
            }

            return false;
        };
    };


    typedef std::shared_ptr<NavConnection> sharedNavConnectionPtr; /*smart memory type for our NavConnections*/

	/*
	* Function: Constructor
	* ---------------------
	*
	* Default constructor
	*
	*/
    NavMeshNode();

	/*
	* Function: Constructor
	* ---------------------
	*
	* sets up the cornors of the NavMesNode with all the map nodes passed into it
	*
	*/
    NavMeshNode(SharedMapNodePtr one, SharedMapNodePtr two, SharedMapNodePtr three, SharedMapNodePtr four);

	/*
	* Function: DeConstructer
	* ------------------------
	*
	* Default deConstructor.
	*
	*/
    ~NavMeshNode();

	/*
	* Function:
	* ---------
	*
	*
	*
	* Parameters: none
	*
	* returns: returns nothing as it is a void function
	*/
    void SetAllCornors(SharedMapNodePtr one, SharedMapNodePtr two, SharedMapNodePtr three, SharedMapNodePtr four);

	

	/*
	* Function:
	* ---------
	*
	*
	*
	* Parameters: none
	*
	* returns: returns nothing as it is a void function
	*/
    SharedMapNodePtr GetUpperLeft();
    SharedMapNodePtr GetLowerLeft();
    SharedMapNodePtr GetUpperRight();
    SharedMapNodePtr GetLowerRight();

	/*
	* Function: CheckIfInMeshBounds
	* -----------------------------
	*
	* this checks if the vector passed in is within the nodes mesh bounds
	* returns true if it is
	*
	* Parameters: Vector2 & worldPos position we want to check if it is inside
	*
	* returns: returns true it worldPos is within our bounds
	*/
    bool CheckIfInMeshBounds(Vector2 & worldPos);

	/*
	* Function: CalculateCenter
	* -------------------------
	*
	* this calculates the center of the node useing the map nodes
	* and sets m_centerPoint to it
	*
	* Parameters: none
	*
	* returns: returns nothing as it is a void function
	*/
    void CalculateCenter();

	/*
	* Function: Draw
	* --------------
	*
	* this draws out the node and its connections
	*
	* Parameters: aie::Renderer2D * renderer so that we can render things out
	*
	* returns: returns nothing as it is a void function
	*/
    void Draw(aie::Renderer2D * m_2dRenderer);

	/*
	* Function: GetCenter
	* -------------------
	*
	* returns m_centerPoint
	*
	* Parameters: none
	*
	* returns: returns m_centerPoint
	*/
    Vector2 GetCenter();

	/*
	* Function: GetCenter
	* -------------------
	*
	* returns m_centerPoint in a non modifiable way
	*
	* Parameters: none
	*
	* returns: returns m_centerPoint
	*/
    Vector2 GetCenter() const;

	/*
	* Function: SetEdgesToTrue
	* ------------------------
	*
	* sets all the nodes edges to true
	* makeing them all map edges
	*
	* Parameters: none
	*
	* returns: returns nothing as it is a void function
	*/
	void SetEdgesToTrue();

	/*
	* Function: DefineMapEdges
	* ------------------------
	*
	* this goes through and figures out what edges are map bounderies
	* and wich are no
	*
	* Parameters: none
	*
	* returns: returns nothing as it is a void function
	*/
    void DefineMapEdges();

	/*
	* Function: CheckEdge
	* -------------------
	*
	* checks to see if we share and edge with the nav mesh pointer passed in
	* is an edge is shared it is not a map edge
	*
	* Parameters: WeakMeshPtr nodeB
	*
	* returns: returns nothing as it is a void function
	*/
    void CheckEdge(WeakMeshPtr nodeB);

	/*
	* Function: GetMapEdges
	* ---------------------
	*
	* gets a list of all the map edges in the node
	*
	* Parameters: none
	*
	* returns: std::list<SharedEdge> of all of the nodes map edges
	*/
    std::list<SharedEdge> GetMapEdges();

	/*
	* Function: CheckIfMapNodeIsShared
	* --------------------------------
	*
	* Checks if a Map Node is shared or not
	*
	* Parameters: SharedMapNodePtr mn
	*
	* returns: returns true if a map node is shared
	*/
    bool CheckIfMapNodeIsShared(SharedMapNodePtr mn);

	/*
	* Function: AddConnection
	* -----------------------
	*
	* sets up a NavConnection between the two nodes passed in and stores it in
	* g_connections on both nodes
	*
	* Parameters: SharedMeshPtr nodeA, SharedMeshPtr nodeB nodes to makes a connection with
	*
	* returns: returns nothing as it is a void function
	*/
    void AddConnection(SharedMeshPtr nodeA, SharedMeshPtr nodeB);

	/*
	* Function: CheckIfConectionExists
	* --------------------------------
	*
	* checks if there is a NavConnection connecting this node
	* with the node passed in, in their g_connections
	*
	* Parameters: none
	*
	* returns: returns true if there is a NavConnection
	*/
    bool CheckIfConectionExists(SharedMeshPtr nodeB);

	/*
	* Function: DeleteAllConections
	* -----------------------------
	*
	* goes through and delets all the NavConnections it has, used when we are 
	* deleteing the node
	*
	* Parameters: SharedMeshPtr me the node we are deleteing
	*
	* returns: returns nothing as it is a void function
	*/
    void DeleteAllConections(SharedMeshPtr me);

	/*
	* Function: DeleteConection
	* -------------------------
	*
	* deletes the sharedNavConnectionPtr we pass in from it g_connections
	*
	* Parameters: sharedNavConnectionPtr ne <- NavConnection we plan to delete
	*
	* returns: returns nothing as it is a void function
	*/
    void DeleteConection(sharedNavConnectionPtr ne);

	/*
	* Function: GetFCost
	* ------------------
	*
	* returns the m_gCost + m_hCost
	*
	* Parameters: none
	*
	* returns: returns m_gCost + m_hCost
	*/
    float GetFCost() const;
	
	/*
	* Function: GetHCost
	* ------------------
	*
	* returns m_hCost
	*
	* Parameters: none
	*
	* returns: returns m_hCost
	*/
    float GetHCost() const;

	/*
	* Function: GetGCost
	* ------------------
	*
	* returns m_gCost
	*
	* Parameters: none
	*
	* returns: returns m_gCost
	*/
    float GetGCost() const;

	/*
	* Function: SetGCost
	* ------------------
	*
	* sets the m_gCost to the value passed in
	*
	* Parameters: float set <- value we plan to set the m_gCost to
	*
	* returns: returns nothing as it is a void function
	*/
    void SetGCost(float set);

	/*
	* Function: SetHCost
	* ------------------
	*
	* Sets the m_hCost to the value passed in
	*
	* Parameters: float set <- value we plan to set the m_hCost to
	*
	* returns: returns nothing as it is a void function
	*/
    void SetHCost(float set);

	/*
	* Function: SetPassible
	* ---------------------
	*
	* set m_isPassable to the value passed in
	*
	* Parameters: bool seter
	*
	* returns: returns nothing as it is a void function
	*/
	void SetPassible(bool seter);

	/*
	* Function: GetIsPasible
	* ----------------------
	*
	* returns m_isPassable
	*
	* Parameters: none
	*
	* returns: returns m_isPassable
	*/
    bool GetIsPasible() const;

	/*
	* Function: GetParent
	* -------------------
	*
	* returns the parent of this class used for pathfinding
	*
	* Parameters: none
	*
	* returns: m_pParent that is our parent
	*/
    WeakMeshPtr GetParent();

	/*
	* Function: SetParent
	* -------------------
	*
	* sets the parent of the node to the one passed in
	*
	* Parameters: SharedMeshPtr parent our new parent
	*
	* returns: returns nothing as it is a void function
	*/
    void SetParent(SharedMeshPtr parent);

	/*
	* operator== (const SharedMeshPtr other)
	* --------
	*
	* checks if we have the same center point and if we do
	* return true
	*
	*/
    bool operator== (const SharedMeshPtr other);

	/*
	* operator!= (const WeakMeshPtr other)
	* --------
	*
	* checks if we do not have the same center point and if we dont
	* return true
	*
	*/
    bool operator!= (const WeakMeshPtr other);

	/*
	* operator== (Vector2 & other)
	* --------
	*
	* checks if the vector passed in has the same value as our center point and if we do
	* return true
	*
	*/
    bool operator== (Vector2 & other);

    std::list<sharedNavConnectionPtr> g_connections; /*list of all  the nodes connections to other nodes*/

private:
    
    SharedMapNodePtr m_upperLeftCornor;		/*our upper Left Cornor*/
    SharedMapNodePtr m_lowerLeftCornor;		/*our lower Left Cornor*/
    SharedMapNodePtr m_upperRightCornor;	/*our upper Right Cornor*/
    SharedMapNodePtr m_lowerRightCornor;	/*our lower Right Cornor*/

    SharedEdge m_NorthEdge;	/*our North Edge*/
    SharedEdge m_EastEdge;	/*our East Edge*/
    SharedEdge m_SouthEdge;	/*our South Edge*/
    SharedEdge m_WestEdge;	/*our West Edge*/

    Vector2 m_centerPoint;	/*our center point of the Nav Mesh*/

    float m_gCost;	/*our g cost*/
    float m_hCost;	/*our h cost*/

    bool m_isPassable; /*this is our static passible bool a and represents things like this tile is a wall*/

    WeakMeshPtr m_pParent; /*this is the tiles parent used to find the path in the A* pathfinding calculations by retracing the path of parents leading from the end tile to the start tile*/
};

