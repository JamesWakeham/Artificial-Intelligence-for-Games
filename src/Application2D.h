#pragma once

#include "BaseApplication.h"
#include "Graph.h"

#include "Agent.h"

#include <glm\mat3x3.hpp>
#include <glm\glm.hpp>
#include <glm\gtc\type_ptr.hpp>

class SpriteBatch;
class Texture;
class Font;

class Application2D : public BaseApplication {
public:

	Agent agent;

	Application2D();
	virtual ~Application2D();


	virtual bool startup();
	virtual void shutdown();

	virtual bool update(float deltaTime);
	virtual void draw();

protected:

	SpriteBatch*	m_spriteBatch;
	Texture*		m_texture;
	Font*			m_font;
};