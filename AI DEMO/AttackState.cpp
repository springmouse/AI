#include "AttackState.h"
#include "Entity.h"


AttackState::AttackState(Entity * unit)
{
	m_myEntity = unit;
}


AttackState::~AttackState()
{
}

void AttackState::onUpdate(float deltaTime)
{
}
