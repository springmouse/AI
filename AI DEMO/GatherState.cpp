#include "GatherState.h"
#include "Entity.h"


GatherState::GatherState(Entity * unit)
{
	m_myEntity = unit;
}


GatherState::~GatherState()
{
}

void GatherState::onUpdate(float deltaTime)
{
}
