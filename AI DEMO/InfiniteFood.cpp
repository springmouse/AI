#include "InfiniteFood.h"



InfiniteFood::InfiniteFood(Vector2 pos)
{
	m_pos = pos;
	m_foodStock = 100;
}


InfiniteFood::~InfiniteFood()
{
}

void InfiniteFood::Update(float deltaTime)
{
}

void InfiniteFood::Draw(aie::Renderer2D * m_2dRenderer)
{
	m_2dRenderer->setRenderColour(0.75, 0.4, 0, 1);
	m_2dRenderer->drawCircle(m_pos.x, m_pos.y, 8);
	m_2dRenderer->setRenderColour(1, 1, 1, 1);
}

float InfiniteFood::GatherFood()
{
	return 50.0f;
}
