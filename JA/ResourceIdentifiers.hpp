#ifndef _RESOURCEIDENTIFIERS
#define _RESOURCEIDENTIFIERS

namespace sf
{
	class Texture;
	class Font;
}

namespace Textures
{
	enum ID
	{ Kenshiro, TitleScreen };
}

namespace Fonts
{
	enum ID
	{ Main };
}

// Forward declarations and a few type definitions
template <typename Resource, typename Identifier>
class ResourceHolder;

typedef ResourceHolder<sf::Texture, Textures::ID>	TextureHolder;
typedef ResourceHolder<sf::Font, Fonts::ID>			FontHolder;

#endif // ResourceIdentifiers.hpp