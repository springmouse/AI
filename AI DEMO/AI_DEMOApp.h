#pragma once

#include "Application.h"
#include "Renderer2D.h"

class AI_DEMOApp : public aie::Application {
public:

	AI_DEMOApp();
	virtual ~AI_DEMOApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
};