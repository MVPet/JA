#ifndef _ARENA
#define _ARENA

#include "Platform.hpp"
#include "Ground.hpp"

class Arena
{
public:
	virtual void	render(sf::RenderWindow* window);
	virtual void	update(sf::Time deltaTime);
	virtual void	load();

protected:
	std::string		name;
};

#endif // Arena.hpp