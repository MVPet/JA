#include "Battle.hpp"

Battle::Battle()
{
	arena = new Train(Tags::Training);
	arena->load();

	dude = new Kenshiro();
	dude->load();
}

void Battle::update(sf::Time deltaTime)
{
	arena->update(deltaTime);
	dude->update(deltaTime);
}

void Battle::render(sf::RenderWindow* window)
{
	arena->render(window);
	dude->render(window);
}

void Battle::processEvents(sf::Keyboard::Key, bool value)
{}