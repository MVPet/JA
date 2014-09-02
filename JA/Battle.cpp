#include "Battle.hpp"

Battle::Battle()
{
	arena = new Train(Tags::Training);
	arena->load();
}

void Battle::update(sf::Time deltaTime)
{
	arena->update(deltaTime);
}

void Battle::render(sf::RenderWindow* window)
{
	arena->render(window);
}

void Battle::processEvents(sf::Keyboard::Key key, bool value)
{
	arena->processEvents(key, value);
}