#include "Platform.hpp"

Platform::Platform(std::string arenaName, sf::Vector2f position)
{
	type = Tags::Platform;
	load(arenaName, type, position, 1);
}