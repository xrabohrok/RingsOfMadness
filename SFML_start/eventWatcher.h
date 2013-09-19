
/*OK.  Listen Up.  While you don't need to worry about HOW the event watcher is working, You should mind how it works 
Becuase views will play into it.

EW does two things:
It registers what should recieve events
and
Dispatches those events to registrees

register to the appropriate event handler to make things happen
There is:
Mouse Down (mouse coords)
Mouse Up (mouse coords)
Mouse moves (mouse coords) *takes a float threshold 
key Up(button)
key Down(button)


The callback provided to the register function will be called should this event happen.
*/
#pragma once

#include <list>
#include "SFML\Window.hpp"

using namespace std;

class eventWatcher
{
public:
	
	//EW is a singleton
	static eventWatcher* getEventWatcherInstance(sf::Window *currentWindow);
	~eventWatcher(void);

	//called in main
	void update();
	
	//The second argument is the key that will fire action()
	void registerKeyDownEvent(void *action(), sf::Keyboard::Key);
	void registerKeyUpEvent(void *action(), sf::Keyboard::Key);

	//looking for the address of a function that is ready to take a mouse position Vector
	void registerMouseDownEvent(void *action(sf::Vector2f));
	void registerMouseUpEvent(void *action(sf::Vector2f));

	//called if the mouse moves, the float is the threshold distance one of the dimmensions has to move to be fired
	void mouseMoved(void *action(sf::Vector2f), float);


private:
	eventWatcher(sf::Window *currentWindow);

	void cycleMouseEvents();
	void cycleKeyboardEvents();
};

