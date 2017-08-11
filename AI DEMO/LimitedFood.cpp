#include "LimitedFood.h"



LimitedFood::LimitedFood(Vector2 pos)
{
	m_pos = pos;
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
