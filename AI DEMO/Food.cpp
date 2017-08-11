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
	for each (SharedMeshPtr node in NAVMANAGER->g_NavNodes)
	{
		if (node->CheckIfInMeshBounds(m_pos))
		{
			return true;
		}
	}

	return false;
}
