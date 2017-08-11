#pragma once
#include "Food.h"

class InfiniteFood :
	public Food
{
public:
	InfiniteFood(Vector2 pos);
	~InfiniteFood();

	void Update(float deltaTime);

	void Draw(aie::Renderer2D * m_2dRenderer);
};

