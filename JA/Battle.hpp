#ifndef _BATTLE
#define _BATTLE

#include "StageList.hpp"
#include "Kenshiro.hpp"
#include "Tags.hpp"

class Battle
{
public:
			Battle();
	void	update(sf::Time deltaTime);
	void	render(sf::RenderWindow* window);
	void	processEvents(sf::Keyboard::Key, bool value);

private:
	int numOfPlayers;

	Arena*	arena;
	Character* dude;
};

#endif // Battle.hpp