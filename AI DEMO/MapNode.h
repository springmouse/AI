#pragma once
#include <Vector2.h>
#include "TypesAndDefines.h"

/*
* Class: MapNode
* --------------
*
* map node makes up all the cornors of the navMeshNodes and 
* the start and end points for map edges foundadtion of the map is
* built off of these things
*
* Author: Callum Dunstone
*/
class MapNode
{
public:

	/*
	* Function: Constructor
	* ---------------------
	*
	* make a map node with a vector to set its position
	*
	*/

    MapNode(Vector2 pos);

	/*
	* Function: Constructor
	* ---------------------
	*
	* make a map node passing in its x and y position
	*
	*/

    MapNode(float x, float y);

	/*
	* Function: DeConstructer
	* ------------------------
	*
	* Default deConstructor.
	*
	*/
    ~MapNode();

	/*
	* operator== (MapNode & other)
	* ----------------------------
	*
	* checks to see if the two map nodes have 
	* the same pos returns true if they do
	*
	*/
	bool operator== (MapNode & other);

	/*
	* operator== (SharedMapNodePtr & other)
	* -------------------------------------
	*
	* checks if the SharedMapNodePtr has the same position as it
	* returns true if they do
	*
	*/
    bool operator== (SharedMapNodePtr & other);

	/*
	* operator!= (WeakMapNodePtr & other)
	* -----------------------------------
	*
	* checks to see if they do not have the same position
	* returns true if they do not
	*
	*/
    bool operator!= (WeakMapNodePtr & other);

	/*
	* operator== (Vector2 & other)
	* ----------------------------
	*
	* returns true if the map node has the same value as the 
	* vector passed in
	*
	*/
    bool operator== (Vector2 & other);

    Vector2 m_pos; /*map nodes position in the world*/
};

