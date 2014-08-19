#ifndef _GAME
#define _GAME

#include "Battle.hpp"

class Game 
{
public:
			Game();
	void	run();

protected:
	void	processEvents();
	void	update(sf::Time deltaTime);
	void	render();

private:
	Battle*				battle;
	sf::RenderWindow	window;
	sf::Time			timePerFrame;
};

#endif // Game.hpp