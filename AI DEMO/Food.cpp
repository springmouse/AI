#include "Food.h"
#include "NavManager.h"


Food::Food()
{
}


Food::~Food()
{
}

bool Food::CheckIFPosValid()
{

	//check that our current position is still valid
	for each (SharedMeshPtr node in NAVMANAGER->g_NavNodes)
	{
		if (node->CheckIfInMeshBounds(m_pos))
		{
			return true;
		}
	}

	return false;
}

bool Food::IsFoodLeft()
{ 
	if (m_foodStock > 0)
	{
		return true;
	}
	return false;
}
