#ifndef _GROUND
#define _GROUND

#include "Terrain.hpp"

class Ground : public Terrain
{
public:
	Ground(std::string name, sf::Vector2f position, float yBoxRatio);
};

#endif // Ground.hpp