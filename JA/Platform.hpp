#ifndef _PLATFORM
#define _PLATFORM

#include "Terrain.hpp"

class Platform : public Terrain
{
public:
	Platform(std::string name, sf::Vector2f position);
};

#endif // Platform.hpp