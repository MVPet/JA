#include "Animation.hpp"

std::string Animations::Stand = "Stand";

Animation::Animation(std::string charName, std::string animName, int frameAmount) : updateTime(0.0), frameIndex(0), frameTime(.5)
{
	numOfFrames = frameAmount;
	name = animName;
	load(charName);
}

void Animation::update(sf::Time deltaTime)
{
	updateTime += deltaTime.asSeconds();

	if(updateTime >= frameTime)
	{
		frameIndex++;
		updateTime = 0.0f;

		if(frameIndex >= numOfFrames)
		{
			frameIndex = 0;
		}

		sprite.setTextureRect(sf::IntRect(frameIndex * frameWidth, 0, frameWidth, frameHeight));
	}
}

void Animation::render(sf::RenderWindow* window)
{
	window->draw(sprite);
}

void Animation::load(std::string charName)
{
	std::string filename = "Assets/Fighter/" + charName + "/" + name + ".png";

	if(!texture.loadFromFile(filename))
		throw std::runtime_error("Animation::load - Failed to load " + filename);

	frameWidth = texture.getSize().x / numOfFrames;
	frameHeight = texture.getSize().y;

	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, frameWidth, frameHeight));
	sprite.setPosition(100.f, 100.f);
	//sprite.setOrigin();
}