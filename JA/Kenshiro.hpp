#ifndef _KENSHIRO
#define _KENSHIRO

#include "Character.hpp"

class Kenshiro : public Character
{
public:
			Kenshiro(sf::Vector2f spawn);
	void	update(sf::Time deltaTime);
	void	processEvents(sf::Keyboard::Key key, bool value);
	void	load();

protected:
	void	NeutralLight();
	void	SideLight();
	void	DownLight();
	void	UpLight();
};

#endif // Kenshiro.hpp