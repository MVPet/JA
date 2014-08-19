#ifndef _CHARACTER
#define _CHARACTER

#include <SFML/Graphics.hpp>
#include "Tags.hpp"
#include "Animation.hpp"

class Character
{
public:
	virtual void render(sf::RenderWindow* window)=0;
	virtual void update(sf::Time deltaTime)=0;
	virtual void load()=0;
	int getHealth();

protected:
	int health;
};

#endif // Character.hpp