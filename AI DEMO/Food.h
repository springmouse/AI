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

	virtual void Draw(aie::Renderer2D * m_2dRenderer) {};
};

