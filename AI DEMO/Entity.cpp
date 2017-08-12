#include "Entity.h"



Entity::Entity()
{
}


Entity::~Entity()
{
}

bool Entity::operator==(Entity * other)
{
	if (other->GetPos() == m_pos)
	{
		return true;
	}

	return false;
}

bool Entity::operator!=(Entity * other)
{
	if (other->GetPos() != m_pos)
	{
		return true;
	}

	return false;
}

void Entity::TakeDamage(float damage)
{
	if (m_murder)
	{
		m_murderHealth -= damage;
	}
	else
	{
		m_health -= damage;
	}
}

bool Entity::IsAlive()
{
	if (m_health > 0 && m_murder == false)
	{
		return true;
	}

	if (m_murderHealth > 0 && m_murder)
	{
		return true;
	}

	return false;
}
