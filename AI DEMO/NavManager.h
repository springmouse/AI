#pragma once
#include <Renderer2D.h>
#include <Input.h>
#include <list>
#include <Vector2.h>
#include "Information.h"
#include "GetAStarPath.h"
#include "TypesAndDefines.h"
#include <Texture.h>

#include "MapNode.h"
#include "NavMeshNode.h"

#define NAVMANAGER NavManager::GetInstanceOfNavManager() /*define to acces the singleton for this class*/

/*
* Class: NavManager
* -----------------
*
* does everything related to the navmesh basically storeing it,
* building it, deleteing it, getting bits of it, you name it it probably does or helps out with it
* in some way if it is realted the the navmesh
*
* Author: Callum Dunstone
*/
class NavManager
{
public:

	/*
	* Function: GetInstanceOfNavManager
	* ---------------------------------
	*
	* returns a static pointer to an instance of the NavManager
	* to be used as it is a singleton class
	*
	* Parameters: none
	*
	* returns: returns  static NavManager *
	*/
    static NavManager * GetInstanceOfNavManager();
	
	/*
	* Function: GatherEdges
	* ---------------------
	*
	* loops through all the nodes and gets there map edges
	*
	* Parameters: none
	*
	* returns: returns nothing as it is a void function
	*/
    void GatherEdges();

	/*
	* Function:
	* ---------
	*
	* takes a node and checks it against all other nodes to make
	* a connection between it and them if the share an edge
	*
	* Parameters: SharedMeshPtr nodeA <- node to make connections to
	*
	* returns: returns nothing as it is a void function
	*/
    void MakeConnectionsToNode(SharedMeshPtr nodeA);

	/*
	* Function: CreatNewNode
	* ----------------------
	*
	* this creates a new node and places it in to the world
	*
	* Parameters: none
	*
	* returns: returns nothing as it is a void function
	*/
    void CreatNewNode();

	/*
	* Function: DestroyNode
	* ---------------------
	*
	* this destroys a node removing it from the map
	*
	* Parameters: none
	*
	* returns: returns nothing as it is a void function
	*/
    void DestroyNode();

	/*
	* Function: Draw
	* --------------
	*
	* this draws out all the nodes and there connections as well as the map edges
	*
	* Parameters: aie::Renderer2D * renderer so that we can render things out
	*
	* returns: returns nothing as it is a void function
	*/
    void Draw(aie::Renderer2D * m_2dRenderer);

	/*
	* Function: GetEdgeConnections
	* ----------------------------
	*
	* takes in a node and creates a small list with all nodes connected to it
	*
	* Parameters: SharedMeshPtr node <- the node we will find all connections with
	*
	* returns: returns nothing as it is a void function
	*/
    std::list<SharedMeshPtr> GetEdgeConnections(SharedMeshPtr node);

	/*
	* Function: GetNode
	* -----------------
	*
	* this takes in a position then checks all NavMeshNodes to find wich
	* node the position passed in is inside of then returns that node
	*
	* Parameters: Vector2 pos 
	*
	* returns: returns SharedMeshPtr wich is the node pos was inside of
	*/
    SharedMeshPtr GetNode(Vector2 pos);

    ////////////////////////////////////////////////

    std::list<SharedMapNodePtr> g_mapNodes; /*all the map nodes*/
    std::list<SharedMeshPtr>    g_NavNodes; /*all the NavMeshNodes*/
    std::list<SharedEdge>       g_mapEdges; /*all map edges*/

private:

	/*
	* Function: Constructor
	* ---------------------
	*
	* Default constructor
	*
	*/
    NavManager();

	/*
	* Function: DeConstructer
	* ------------------------
	*
	* Default deConstructor.
	*
	*/
    ~NavManager();

    aie::Texture * m_tileTexture[3]; /*bit obsalete as nodes do not have textures drawn to them now but still use it for the mose cursor*/

};

