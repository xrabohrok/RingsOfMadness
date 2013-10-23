#pragma once

#include "SFML\Graphics.hpp"
#include "SFML\Window.hpp"
#include "Animation.h"
#include <list>

using namespace std;

class RendererBase
{
public:

	static RendererBase* getRenderer(sf::RenderWindow *win);
	static RendererBase* getRenderer();

	void registerSprite(sf::Sprite* spr);
	void registerAnimation(Animation* anim);

	void draw(double deltaTime);

	~RendererBase(void);

private:
	RendererBase(sf::RenderWindow* _win);
	static RendererBase* me;

	sf::RenderWindow *win;

	list<sf::Sprite*> spriteList;
	list<Animation*> animationList;
			

};




