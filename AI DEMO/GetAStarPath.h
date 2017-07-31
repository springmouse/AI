#pragma once
#include <list>
#include "NavMeshNode.h"
#include <Vector2.h>

#define PATH_FINDER GetAStarPath::GetInstanceOfpathFinder() /*this creates a static instance of the pathfinder that can be easily called any where*/


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
    std::list<NavMeshNode *> FindPath(Vector2 start, Vector2 end);


    bool FindInContainer(std::list<NavMeshNode *> * holder, NavMeshNode * n);

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
    int GetDistance(NavMeshNode * nodeA, NavMeshNode * nodeB);

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
    std::list<NavMeshNode *>  RetracePath(NavMeshNode * startTile, NavMeshNode * endTile);

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

