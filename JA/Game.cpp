#include "Game.hpp"

Game::Game() : window(sf::VideoMode(512,256), "JA"), timePerFrame(sf::seconds(1.f/60.f))
{
	battle = new Battle();
}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	while (window.isOpen())
	{
		processEvents();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents();
			update(timePerFrame);
		}
		render();
	}
}

void Game::processEvents()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		switch(event.type)
		{
		case sf::Event::KeyPressed:
			battle->processEvents(event.key.code, true);
			break;

		case sf::Event::KeyReleased:
			battle->processEvents(event.key.code, false);
			break;

		case sf::Event::Closed:
			window.close();
			break;
		}
	}
}

void Game::update(sf::Time deltaTime)
{
	battle->update(deltaTime);
}

void Game::render()
{
	window.clear();
	battle->render(&window);
	window.display();
}