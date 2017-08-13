#pragma once
#include <list>
#include "NavMeshNode.h"
#include "TypesAndDefines.h"
#include <Vector2.h>

#define PATH_FINDER GetAStarPath::GetInstanceOfpathFinder() /*this creates a static instance of the pathfinder that can be easily called any where*/

/*
* Class: GetAStarPath
* -------------------
*
* this class finds us a path from point A to point B using the
* A* method
*
* Author: Callum Dunstone
*/
class GetAStarPath
{
public:

    /*
    * Function: FindPath
    * ------------------
    *
    * this function searches for a path from a given start and end tile using a A* pathing algorithm
    * and returns the path it has found stored in a vector
    *
    * Parameters: int startX, int startY, int endX, int endY it uses these to search for two tiles that it will use as its
    * start and end tile for its path search eg: tile at position startY and startX will be the starting tile for the search
    *
    * Return: a vector of tiles makeing up the path from the start to the end tile
    */
    std::list<Vector2> FindPath(Vector2 start, Vector2 end);

	/*
	* Function: LineCheck
	* -------------------
	*
	* this checks the line we pass in crosses over
	* and of the map edges and if it does returns true
	*
	* Parameters: Vector2 start of our line, Vector2 end of our line
	*
	* returns: returns true if two lines crose over
	*/
	bool LineCheck(Vector2 start, Vector2 end);

	/*
	* Function: FindInContainer
	* --------------------------
	*
	* checks if the item we pass in is in the container we also pass in
	*
	* Parameters: std::list<SharedMeshPtr> * holder <- the container, SharedMeshPtr n <- item we are looking for
	*
	* returns: if item is in there we return true else we return false
	*/
    bool FindInContainer(std::list<SharedMeshPtr> * holder, SharedMeshPtr n);

    /*
    * Function: GetDistance
    * ---------------------
    *
    * this function is used to get the distance between two Tiles so that it can
    * find the best path where distance moving left, right, up and down has a vlaue of 10 and
    * moving diagionaly has a movemeant cost of 14
    *
    * Parameters: Node * nodeA, Node * nodeB. these are our reference tiles that
    * we try and find the distance between
    *
    * Return: an int that is the value of the distance between the two tiles
    */
    int GetDistance(SharedMeshPtr nodeA, SharedMeshPtr nodeB);

    /*
    * Function: RetracePath
    * ---------------------
    *
    * this function retrace the path we have found starting at the end tile the working its way backwards by checking the end tiles parent then that tiles parent until it
    * gets to the start tile. once it has achieved this it will revers the vector so that the start of the vector will be the
    * start node and not the end node then returns the vector only holding the tiles for the path
    *
    * Parameters: Tiles & startTile, Tiles & endTile it uses these tiles to retrace the path we have found
    *
    * Return: a vector holding only our path tiles from start to end
    */
    std::list<Vector2>  RetracePath(SharedMeshPtr startTile, SharedMeshPtr endTile);
	
    /*
    * Function: GetInstanceOfpathFinder
    * ---------------------------------
    *
    * this function returns a static instance of the pathfinder object
    *
    * Parameters: this function has not parameters
    *
    * Return: returns a static pointer to a pathFinder instance
    */
    static GetAStarPath * GetInstanceOfpathFinder();

private:
    /*
    * Function: Constructor
    * ---------------------
    *
    * this is the Default constructor of the game
    *
    */
    GetAStarPath();

    /*
    * Function: DeConstructor
    * -----------------------
    *
    * this is the default DeConstructor of the game
    *
    */
    ~GetAStarPath();
};

