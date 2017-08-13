#include "LimitedFood.h"



LimitedFood::LimitedFood(Vector2 pos)
{
	m_pos = pos;
	m_foodStock = 400;
}


LimitedFood::~LimitedFood()
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
	//you cant gather food if there is non
	if (m_foodStock <= 0)
	{
		return 0.0f;
	}

	m_foodStock -= 20.0f;
	return 20.0f;
}
