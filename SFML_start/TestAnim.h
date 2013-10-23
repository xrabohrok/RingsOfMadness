#pragma once
#include "animation.h"
class TestAnim :
	public Animation
{
public:

	sf::Texture texture;
	sf::Sprite sprite;

	 sf::Sprite draw(double deltaTime);

	TestAnim(void);
	~TestAnim(void);
};

