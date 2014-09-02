#ifndef _TRAIN
#define _TRAIN

#include "Arena.hpp"

class Train : public Arena
{
public:
			Train(std::string nam);
	void	render(sf::RenderWindow* window);
	void	update(sf::Time deltaTime);
	void	load();
	void	processEvents(sf::Keyboard::Key key, bool value);

private:
	void checkStageCollisions();

	Platform*	platform;
	Ground*		ground;

	Character* dude;
};

#endif // Train.hpp