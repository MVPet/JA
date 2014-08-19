#include "Train.hpp"

Train::Train(std::string nam)
{
	name = nam;
}

void Train::update(sf::Time deltaTime)
{}

void Train::render(sf::RenderWindow* window)
{
	platform->render(window);
	ground->render(window);
}

void Train::load()
{
	platform = new Platform(name,sf::Vector2f(512 / 4, 256 / 2));
	ground = new Ground(name, sf::Vector2f(0, 256), .75);
}