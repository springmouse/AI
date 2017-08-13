#pragma once
#include "Food.h"

class LimitedFood : 
	public Food
{
public:
	LimitedFood(Vector2 pos);
	~LimitedFood();

	void Update(float deltaTime);

	void Draw(aie::Renderer2D * m_2dRenderer);

	float GatherFood();

private:
};

