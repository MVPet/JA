#include "Terrain.hpp"

void Terrain::render(sf::RenderWindow* window)
{
	window->draw(sprite);
}

void Terrain::load(std::string arenaName, std::string terrainType, sf::Vector2f position, float yBoxRatio)
{
	std::string filename = "Assets/Stages/" + arenaName + "/" + terrainType + ".png";

	if(!texture.loadFromFile(filename))
		throw std::runtime_error("Terrain::load - Failed to load " + filename);

	sprite.setTexture(texture);
	sprite.setOrigin(0, texture.getSize().y);
	sprite.setPosition(position);

	boundBox = sf::FloatRect(position.x, position.y - ((float)texture.getSize().y * yBoxRatio),  (float)texture.getSize().x, (float)texture.getSize().y * yBoxRatio);
}

sf::FloatRect Terrain::getBoundBox()
{ return boundBox; }