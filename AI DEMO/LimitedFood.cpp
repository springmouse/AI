#include "LimitedFood.h"



LimitedFood::LimitedFood(Vector2 pos)
{
	m_pos = pos;
	m_foodStock = 100;
}


LimitedFood::~LimitedFood()
{
}

void LimitedFood::Update(float deltaTime)
{
}

void LimitedFood::Draw(aie::Renderer2D * m_2dRenderer)
{

	m_2dRenderer->setRenderColour(0.5, 0.5, 0, 1);
	m_2dRenderer->drawCircle(m_pos.x, m_pos.y, 8);
	m_2dRenderer->setRenderColour(1, 1, 1, 1);

}

float LimitedFood::GatherFood()
{
	m_foodStock -= 50;
	if (m_foodStock <= 0)
	{
		return 0.0f;
	}
	return 50.0f;
}
