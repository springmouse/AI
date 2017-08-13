#pragma once
#include "Object.h"

enum eFoodTypes
{
	FOOD_LIMITED,
	FOOD_INFINITE
};

class Food :
	public Object
{
public:
	Food();
	~Food();

	void Update(float deltaTime) {};

	virtual float GatherFood() = 0;

	bool CheckIFPosValid();

	virtual void Draw(aie::Renderer2D * m_2dRenderer) {};

	bool IsFoodLeft();

protected:
	float m_foodStock;
};

