#pragma once

#include "BaseApplication.h"
#include "Node.h"
class SpriteBatch;
class Texture;
class Font;

class Application2D : public BaseApplication {
public:
	Node grid[10][10];

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