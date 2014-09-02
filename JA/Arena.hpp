#ifndef _ARENA
#define _ARENA

#include "Platform.hpp"
#include "Ground.hpp"
#include "Kenshiro.hpp"

class Arena
{
public:
	virtual void	render(sf::RenderWindow* window)=0;
	virtual void	update(sf::Time deltaTime)=0;
	virtual void	load()=0;
	virtual void	processEvents(sf::Keyboard::Key key, bool value)=0;

protected:
	std::string		name;

	sf::Texture backgroundTex;
	sf::Sprite background;
};

#endif // Arena.hpp