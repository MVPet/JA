#ifndef _ANIMATION
#define _ANIMATION

#include <string>
#include "AnimFrame.hpp"

namespace Animations
{
	extern const std::string NLight;
	extern const std::string DLight;
	extern const std::string SLight;
	extern const std::string ULight;
	extern const std::string Guard;
	extern const std::string Stand;
	extern const std::string Run;
}

class Animation
{
public:
					Animation(std::string charName, std::string animName, std::vector<AnimFrame*> frameData, bool repeat);
	void			update(sf::Time deltaTime, sf::Vector2f position);
	void			render(sf::RenderWindow* window);
	void			reset();

	sf::Vector2i	getFrameSize();
	bool			getIsDone();

	void			setScale(float x, float y);

private:
	void			load(std::string charName);

	std::string				name;
	std::vector<AnimFrame*> frameData;
	sf::Texture				texture;
	sf::Sprite				sprite;

	int						frameIndex;
	int						numOfFrames;
	float					updateTime;
	bool					loop;
	bool					isDone;
	int						frameWidth;
	int						frameHeight;
};

#endif // Animation.hpp