#include "Kenshiro.hpp"

Kenshiro::Kenshiro()
{
	name = Tags::Kenshiro;
}

void Kenshiro::update(sf::Time deltaTime)
{
	anim->update(deltaTime);
}

void Kenshiro::render(sf::RenderWindow* window)
{
	anim->render(window);
}

void Kenshiro::load()
{
	anim = new Animation(name, Animations::Stand, 4);
}