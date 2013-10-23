#include "RendererBase.h"


RendererBase::RendererBase(sf::RenderWindow* _win):spriteList(),animationList(){
	win = _win;
}
RendererBase::~RendererBase(void)
{
}
RendererBase* RendererBase::me = NULL;

void RendererBase::draw(double deltaTime)
{
	std::list<sf::Sprite*>::iterator iter = spriteList.begin();

	if(spriteList.size() > 0)
	for (std::list<sf::Sprite*>::iterator iter = spriteList.begin(); iter != spriteList.end(); ++iter)
	{
		win->draw(*(*iter));
	}

	
	if(animationList.size() > 0)
	for (std::list<Animation*>::iterator iter2 = animationList.begin(); iter2 != animationList.end(); ++iter2)
	{
		sf::Sprite temp = (*iter2)->draw(deltaTime);
		win->draw(temp);
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
RendererBase* RendererBase::getRenderer(sf::RenderWindow *win)
{
	if (RendererBase::me == NULL)
	{
		RendererBase::me = new RendererBase(win);
	}

	return RendererBase::me;

}
RendererBase* RendererBase::getRenderer()
{
	return RendererBase::me;
}
