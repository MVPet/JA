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

private:
	Platform*	platform;
	Ground*		ground;
};

#endif // Train.hpp