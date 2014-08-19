#ifndef _KENSHIRO
#define _KENSHIRO

#include "Character.hpp"

class Kenshiro : public Character
{
public:
	Kenshiro();
	void update(sf::Time deltaTime);
	void render(sf::RenderWindow* window);
	void load();

private:
	std::string name;
	Animation* anim;
};

#endif // Kenshiro.hpp