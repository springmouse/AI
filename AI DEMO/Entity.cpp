#include "Entity.h"



Entity::Entity()
{
    m_currLocation = nullptr;
}


Entity::~Entity()
{
    delete m_currLocation;
}
