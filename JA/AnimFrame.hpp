#ifndef _ANIMFRAME
#define _ANIMFRAME

#include <SFML/Graphics.hpp>

class AnimFrame
{
public:
			AnimFrame(sf::IntRect hBox, sf::IntRect aBox, float fTime);
			AnimFrame(sf::IntRect hBox, float fTime);
	float	getFrameTime();

private:
	sf::IntRect hurtBox;
	sf::IntRect attackBox;
	float frameTime;

	bool hasAttackBox;
};

#endif // AnimFrame.hpp