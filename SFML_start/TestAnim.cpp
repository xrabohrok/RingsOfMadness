#include "TestAnim.h"


TestAnim::TestAnim(void)
{
	texture.loadFromFile("Mrbones.png");
	sprite.setTexture(texture);

	sprite.setPosition(10,10);
	sprite.setScale(2,2);
	
	sprite.setTextureRect(sf::IntRect(0,0, 200, 200));
}


TestAnim::~TestAnim(void)
{
}

sf::Sprite TestAnim::draw(double deltaTime)
{
	return sprite;
}
