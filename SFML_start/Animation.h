#pragma once

#include "SFML\Graphics.hpp"


class Animation
{
public:

	
	virtual sf::Sprite draw(double deltaTime);

	Animation(void);
	~Animation(void);

	
};

