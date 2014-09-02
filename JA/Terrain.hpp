#ifndef _TERRAIN
#define _TERRAIN

#include <SFML/Graphics.hpp>
#include <string>
#include "Tags.hpp"

class Terrain
{
public:
	void render(sf::RenderWindow* window);

	sf::FloatRect getBoundBox();

protected:
	void load(std::string arenaName, std::string terrainType, sf::Vector2f position, float yBoxRatio);

	std::string type;
	sf::Texture texture;
	sf::Sprite sprite;
	sf::FloatRect boundBox;

	sf::RectangleShape temp;
};

#endif // Terrain.hpp