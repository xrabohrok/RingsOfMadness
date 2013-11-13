// ResourceTracker.cpp
// Programmer: Chris Shaw
// Last Update: 10/27/13

#include "ResourceTracker.h"

ResourceTracker::ResourceTracker()
{
}

ResourceTracker& ResourceTracker::getResourceTracker()
{
	static ResourceTracker instance;
	return instance;
}

sf::Texture ResourceTracker::getTexture(std::string filename)
{
	return textureMap[filename];
}

void ResourceTracker::addTexture(std::string filename, sf::Texture texture)
{
	// Does texture need to be a new texture?  Wouldn't want all instances of a texture to be the same texture object
	textureMap[filename] = texture;
}

// Since every texture that is loaded needs to be added to the tracker, this function handles that
sf::Texture ResourceTracker::loadTexture(std::string filename)
{
	textureMap.find(filename);
	sf::Texture newTexture;

	newTexture.loadFromFile(filename);
	textureMap[filename] = newTexture;

	return newTexture;
}