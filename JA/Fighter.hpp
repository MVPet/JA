#ifndef _FIGHTER
#define _FIGHTER

#include "Entity.hpp"
#include "ResourceIdentifiers.hpp"

#include <SFML\Graphics\Sprite.hpp>

class Fighter : public Entity
{
public:
	enum Type
	{ Kenshiro };

public:
							Fighter(Type type, const TextureHolder& textures);
	virtual unsigned int	getCategory() const;

private:
	virtual void	drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	Type		mType;
	sf::Sprite	mSprite;
};

#endif // Fighter.hpp