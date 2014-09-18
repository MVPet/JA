#include "Fighter.hpp"
#include "ResourceHolder.hpp"
#include "Utility.hpp"

#include <SFML\Graphics\RenderTarget.hpp>
#include <SFML\Graphics\RenderStates.hpp>

Textures::ID toTextureID(Fighter::Type type)
{
	switch (type)
	{
	case Fighter::Kenshiro:
		return Textures::Kenshiro;
	}
}

Fighter::Fighter(Type type, const TextureHolder& textures)
	: mType(type)
	, mSprite(textures.get(toTextureID(type)))
{ centerOrigin(mSprite); }

void Fighter::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{ target.draw(mSprite, states); }

/*unsigned int Fighter::getCategory() const
{
	switch (mType)
	{
	case Kenshiro:
		return Category::;
	}
}*/