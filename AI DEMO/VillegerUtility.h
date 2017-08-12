#pragma once
#include <Vector2.h>

class Entity;

class VillegerUtility
{
public:
	VillegerUtility(Entity * entity);
	~VillegerUtility();

	void Update(float deltaTime);

	void CalculateGetFood();
	void ClaculateMurder();
	void ClaculateWander();
	void CalculateFight();

	float sprMagnatude(Vector2 pos);

	float m_getFood;
	float m_murder;
	float m_wonder;
	float m_fight;

private:
	Entity * m_myEntity;

	float m_checkRadius;
};

