// This stores all the resources the game has loaded
// There may need to be a limit placed on this to avoid overflow

// ResourceTracker.h
// Programmer: Chris Shaw
// Last Update: 10/27/13

// Whenever a resource is loaded, it gets added to this object
// Whenever that resource is needed again, it is pulled from here

#include "SFML/Graphics.hpp"

class ResourceTracker
{
	private:

		ResourceTracker();
		ResourceTracker(ResourceTracker const& copy);

		std::map <std::string, sf::Texture> textureMap; // The key is the filename since that will be 100% unique

		ResourceTracker& operator=(ResourceTracker const& copy);

	public:
		static ResourceTracker& getResourceTracker();

		sf::Texture getTexture(std::string filename);
		void addTexture(std::string filename, sf::Texture texture);
		sf::Texture loadTexture(std::string filename);
};