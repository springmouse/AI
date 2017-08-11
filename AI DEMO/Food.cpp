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
		if (node->GetCenter() == m_pos)
		{
			return true;
		}
	}
}
