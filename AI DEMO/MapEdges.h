#pragma once
#include "MapNode.h"
#include "TypesAndDefines.h"
#include <Renderer2D.h>

/*
* Class: MapEdges
* ---------------
*
* this edges sourround each NavMeshNode and are used to figure out
* where a map edge might be
*
* Author: Callum Dunstone
*/
class MapEdges
{
public:

	/*
	* Function: Constructor
	* ---------------------
	*
	* takes in two map node ptr to set up the edges ends
	*
	*/
    MapEdges(WeakMapNodePtr one, WeakMapNodePtr two);

	/*
	* Function: DeConstructer
	* ------------------------
	*
	* Default deConstructor.
	*
	*/

    ~MapEdges();

	/*
	* operator== (const SharedEdge other)
	* -----------------------------------
	*
	* this checks to see if both SharedEdges have the same map Nodes
	* and if yes returns true else returns false
	*
	*/
    bool operator== (const SharedEdge other);

	/*
	* Function: Draw
	* --------------
	*
	* this draws out the map edge to the screen
	*
	* Parameters: aie::Renderer2D * renderer so that we can render things out
	*
	* returns: returns nothing as it is a void function
	*/
    void Draw(aie::Renderer2D * m_2dRenderer);


    WeakMapNodePtr pointOne; /*one end of the edge*/
    WeakMapNodePtr pointTwo; /*other end of the edge*/


    bool mapEdge; /*is this an edge of the map or not*/
};

