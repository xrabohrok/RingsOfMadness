#include "RendererBase.h"


RendererBase::RendererBase(sf::Window *_win):spriteList(),animationList(){

}


RendererBase::~RendererBase(void)
{
}

void RendererBase::draw(double deltaTime)
{
	std::list<sf::Sprite*>::iterator iter = spriteList.begin();

	for (int i = 0; i < spriteList.size(); i++)
	{
		win->draw(*(*iter));
		iter++;
	}

	std::list<sf::Animation*>::iterator iter2 = animationList.begin();

	for (int i = 0; i < animationList.size(); i++)
	{
		sf::Sprite temp = (*iter2)->draw(deltaTime);
		win->draw(*(*iter2));
		iter++;
	}
}

void RendererBase::registerSprite(sf::Sprite* spr)
{
	spriteList.push_back(spr);
}


void RendererBase::registerAnimation(Animation* anim)
{
	animationList.push_back(anim);
}

RendererBase* RendererBase::getRenderer(sf::RenderWindow *windown)
{
	if (me == NULL)
	{
		me = new RendererBase(win);
	}

	return me;

}

RendererBase* RendererBase::getRenderer()
{
	return me;
}


