#include "Train.hpp"

Train::Train(std::string nam)
{
	name = nam;

	dude = new Kenshiro(sf::Vector2f(100.f,100.f));
	dude->load();
}

void Train::update(sf::Time deltaTime)
{
	checkStageCollisions();
	dude->update(deltaTime);
}

void Train::render(sf::RenderWindow* window)
{
	window->draw(background);

	platform->render(window);
	ground->render(window);

	dude->render(window);
}

void Train::load()
{
	platform = new Platform(name,sf::Vector2f(512 / 4, 256 / 2));
	ground = new Ground(name, sf::Vector2f(0, 256), .65);

	std::string filename = "Assets/Stages/" + name + "/Background.png";

	if(!backgroundTex.loadFromFile(filename))
		throw std::runtime_error("Train::load - Failed to load " + filename);

	background.setTexture(backgroundTex);
}

void Train::processEvents(sf::Keyboard::Key key, bool value)
{
	dude->processEvents(key, value);
}

void Train::checkStageCollisions()
{
	if(platform->getBoundBox().intersects(dude->getGroundBox()))
		dude->setGrounded(true);

	if(ground->getBoundBox().intersects(dude->getGroundBox()))
		dude->setGrounded(true);
}