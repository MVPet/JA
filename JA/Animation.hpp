#ifndef _ANIMATION
#define _ANIMATION

#include <SFML/Graphics.hpp>
#include <string>

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
					Animation(std::string charName, std::string animName, int frameAmount);
	void			update(sf::Time deltaTime, sf::Vector2f position);
	void			render(sf::RenderWindow* window);

	sf::Vector2f	getFrameSize();

	void			setScale(float x, float y);

private:
	void			load(std::string charName);

	std::string		name;
	sf::Texture		texture;
	sf::Sprite		sprite;

	sf::FloatRect	attackBox;
	sf::FloatRect	boundBox;
	int				frameIndex;
	int				numOfFrames;
	float			updateTime;
	float			frameTime;
	bool			loop;
	int				frameWidth;
	int				frameHeight;
};

#endif // Animation.hpp