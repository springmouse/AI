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
std::list<Vector2> GetAStarPath::FindPath(Vector2 start, Vector2 end)
{
    //the start Node
    SharedMeshPtr startNode = NAVMANAGER->GetNode(start);

    //the target node we are trying to get to
    SharedMeshPtr targetNode = NAVMANAGER->GetNode(end);

    //if the start or target node does not exist we escape
    if (startNode == nullptr || targetNode == nullptr)
    {
        std::list<Vector2> temp = std::list<Vector2>();
        return temp;
    }

	//check if there is line of sight first
	if (LineCheck(start, end) == false)
	{
		std::list<Vector2> tempPath;
		tempPath.push_back(end);
		return tempPath;
	}

    //tiles we can look at
    std::list<SharedMeshPtr> openSet;
    //tiles we have looked at
    std::list<SharedMeshPtr> closedSet;

    //we add the start node to the open set so we can begin the search
    openSet.push_back(startNode);

    while (openSet.size() > 0)
    {
        //sets the node we are currently looking at
        SharedMeshPtr currentNode = openSet.front();

        //look through the open set to see if there is a better tile with a lower cost wich equal closer too the target (sort of)
        for (std::list<SharedMeshPtr>::iterator it = openSet.begin(); it != openSet.end(); it++)
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
        if (currentNode == targetNode)
        {
            //we retrace the path add that to a new vector only holding the path tiles and return that
            return RetracePath(startNode, currentNode);;
        }

        //else we get the naiughbours of the current node and add them to the open set
        for each (SharedMeshPtr N in NAVMANAGER->GetEdgeConnections(currentNode))
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
    std::list<Vector2> empty = std::list<Vector2>();
    return empty;
}

bool GetAStarPath::LineCheck(Vector2 start, Vector2 end)
{
	//Based on concept from https://stackoverflow.com/a/1968345

	double p0_x = start.x;
	double p0_y = start.y;
	double p1_x = end.x;
	double p1_y = end.y;

	double p2_x = 0;
	double p2_y = 0;
	double p3_x = 0;
	double p3_y = 0;

	double s1_x, s1_y, s2_x, s2_y;

	double s, t, b;

	//check every edge for a collision
	for each (SharedEdge edge  in NAVMANAGER->g_mapEdges)
	{
		p2_x = edge->pointOne.lock()->m_pos.x;
		p2_y = edge->pointOne.lock()->m_pos.y;
		p3_x = edge->pointTwo.lock()->m_pos.x;
		p3_y = edge->pointTwo.lock()->m_pos.y;

		s1_x = p1_x - p0_x;
		s1_y = p1_y - p0_y;
		s2_x = p3_x - p2_x;
		s2_y = p3_y - p2_y;

		b = (-s2_x * s1_y + s1_x * s2_y);

		//Avoid divide by 0 error.
		if (b != 0)
		{
			s = (-s1_y * (p0_x - p2_x) + s1_x * (p0_y - p2_y)) / b;
			t = (s2_x * (p0_y - p2_y) - s2_y * (p0_x - p2_x)) / b;
		}
		else
		{
			//No collision
			break;
		}

		if (s >= 0 && s <= 1 && t >= 0 && t <= 1)
		{
			//Collision detected
			return true;
		}

	}

	//No collision
	return false;
}

bool GetAStarPath::FindInContainer(std::list<SharedMeshPtr> * holder, SharedMeshPtr node)
{
	//loop through container see if node is in there
    for each (SharedMeshPtr n in *holder)
    {
        if (n == node)
        {
            return true;
        }
    }

    return false;
}

//we retrace the path by following the parents of each node starting at the end moving all the way to the begining
std::list<Vector2>  GetAStarPath::RetracePath(SharedMeshPtr startTile, SharedMeshPtr endTile)
{
    std::list<Vector2> path;

	SharedMeshPtr startPos = endTile;
    SharedMeshPtr currentTile = endTile->GetParent().lock();
	SharedMeshPtr holder = currentTile;

    //we keep looping while the current tile
    //dose not equal the stat tile
    while (currentTile != startTile)
    {
        path.push_back(startPos->GetCenter());
		
		while (LineCheck(startPos->GetCenter(), currentTile->GetCenter())== false && currentTile != startTile)
		{
			holder = currentTile;
			currentTile = currentTile->GetParent().lock();
		}

		startPos = holder;
		currentTile = startPos->GetParent().lock();
	}

    //we reverse the path so that it goes from start Tile to end tile
    //and not end tile to start tile
    std::reverse(path.begin(), path.end());
	
    //we return the path
    return path;
}

//this finds the distance between two tile were left right up and down have a cost of 10
//and diaginoals have a cost of 14
int GetAStarPath::GetDistance(SharedMeshPtr nodeA, SharedMeshPtr nodeB)
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
