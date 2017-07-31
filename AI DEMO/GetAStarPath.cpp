#include "GetAStarPath.h"
#include "NavManager.h"
#include <iostream>

GetAStarPath::GetAStarPath()
{
}

GetAStarPath::~GetAStarPath()
{
}

//get a static instance pointer to a pathFinder
GetAStarPath * GetAStarPath::GetInstanceOfpathFinder()
{
    static GetAStarPath pathFinder;

    return &pathFinder;
}

//finds us a path between two nodes
std::list<NavMeshNode *> GetAStarPath::FindPath(Vector2 start, Vector2 end)
{
    //the start Node
    NavMeshNode * startNode = NAVMANAGER->GetNode(start);

    //the target node we are trying to get to
    NavMeshNode * targetNode = NAVMANAGER->GetNode(end);

    //if the start or target node does not exist we escape
    if (startNode == nullptr || targetNode == nullptr)
    {
        std::list<NavMeshNode *> temp = std::list<NavMeshNode *>();
        return temp;
    }

    //tiles we can look at
    std::list<NavMeshNode *> openSet;
    //tiles we have looked at
    std::list<NavMeshNode *> closedSet;

    //we add the start node to the open set so we can begin the search
    openSet.push_back(startNode);

    while (openSet.size() > 0)
    {
        //sets the node we are currently looking at
        NavMeshNode * currentNode = openSet.front();

        //look through the open set to see if there is a better tile with a lower cost wich equal closer too the target (sort of)
        for (std::list<NavMeshNode *>::iterator it = openSet.begin(); it != openSet.end(); it++)
        {
            if ((*it)->GetFCost() < currentNode->GetFCost())
            {
                currentNode = *it;
            }
            else if ((*it)->GetFCost() == currentNode->GetFCost() && (*it)->GetHCost() < currentNode->GetHCost())
            {
                currentNode = *it;
            }
        }

        //we remove the tile from the open set as it has been claimed for the path
        openSet.remove(currentNode);

        //we add the tile to the closed set of nodes
        closedSet.push_back(currentNode);

        //if the current tile is equal to the target tile we have reached the end of the path
        if (*currentNode == *targetNode)
        {
            //we retrace the path add that to a new vector only holding the path tiles and return that
            return RetracePath(startNode, currentNode);;
        }

        //else we get the naiughbours of the current node and add them to the open set
        for each (NavMeshNode * N in NAVMANAGER->GetEdgeConnections(currentNode))
        {
            //if we cant move on the tile we skip over it
            if (N->GetIsPasible() == false || FindInContainer(& closedSet, N))
            {
                continue;
            }

            int newMovemeantCostToNeighbour = currentNode->GetGCost() + GetDistance(currentNode, N);
            //if the tile we are looking at is not allready in the openset we add it into it
            //else if it already is but the new path has a lower movmeant cost to get to it we update it in the openset
            //and we set its parent to the current node as that path is the curent path with the lowest cost
            if (newMovemeantCostToNeighbour < N->GetGCost() || FindInContainer(& openSet, N) == false)
            {
                N->SetGCost(newMovemeantCostToNeighbour);
                N->SetHCost(GetDistance(N, targetNode));
                N->SetParent(currentNode);

                if (std::find(openSet.begin(), openSet.end(), N) == openSet.end())
                {
                    openSet.push_back(N);
                }
            }
        }
    }

    //this was added to avoid bad evil crashes where no path could be found
    std::list<NavMeshNode *> empty = std::list<NavMeshNode *>();
    return empty;
}

bool GetAStarPath::FindInContainer(std::list<NavMeshNode *> * holder, NavMeshNode * node)
{
    for each (NavMeshNode * n in *holder)
    {
        if (n == node)
        {
            return true;
        }
    }

    return false;
}

//we retrace the path by following the parents of each node starting at the end moving all the way to the begining
std::list<NavMeshNode *>  GetAStarPath::RetracePath(NavMeshNode * startTile, NavMeshNode * endTile)
{
    std::list<NavMeshNode *> path;
    NavMeshNode * currentTile = endTile;

    //we keep looping while the current tile
    //dose not equal the stat tile
    while (currentTile != startTile)
    {
        path.push_back(currentTile);
        currentTile = currentTile->GetParent();
    }

    //we reverse the path so that it goes from start Tile to end tile
    //and not end tile to start tile
    std::reverse(path.begin(), path.end());

	//makes sure the nodes dont have random loss paths
	//NAVMANAGER->ClearParents();

    //we return the path
    return path;
}

//this finds the distance between two tile were left right up and down have a cost of 10
//and diaginoals have a cost of 14
int GetAStarPath::GetDistance(NavMeshNode * nodeA, NavMeshNode * nodeB)
{
    int disX = std::abs(nodeA->GetCenter().x - nodeB->GetCenter().x);
    int disY = std::abs(nodeA->GetCenter().y - nodeB->GetCenter().y);

    if (disX > disY)
    {
        return 14 * disY + 10 * (disX - disY);
    }
    else
    {
        return 14 * disX + 10 * (disY - disX);
    }
}
