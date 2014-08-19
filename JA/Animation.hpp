#ifndef _ANIMATION
#define _ANIMATION

#include <SFML/Graphics.hpp>
#include <string>

namespace Animations
{
	extern std::string Stand;
}

class Animation
{
public:
	Animation(std::string charName, std::string animName, int frameAmount);
	void update(sf::Time deltaTime);
	void render(sf::RenderWindow* window);

private:
	void load(std::string charName);

	std::string name;
	sf::Texture texture;
	sf::Sprite sprite;

	sf::FloatRect attackBox;
	sf::FloatRect boundBox;
	int frameIndex;
	int numOfFrames;
	float updateTime;
	float frameTime;
	bool loop;
	int frameWidth;
	int frameHeight;
};

#endif // Animation.hpp