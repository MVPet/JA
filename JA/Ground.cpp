#include "Ground.hpp"

Ground::Ground(std::string arenaName, sf::Vector2f position, float yBoxRatio)
{
	type = Tags::Ground;
	load(arenaName, type, position, yBoxRatio);
}