#include "Animation.hpp"

const std::string Animations::SLight = "SLight";
const std::string Animations::ULight = "ULight";
const std::string Animations::DLight = "DLight";
const std::string Animations::NLight = "NLight";
const std::string Animations::Guard = "Guard";
const std::string Animations::Stand = "Stand";
const std::string Animations::Run = "Run";

Animation::Animation(std::string charName, std::string animName, int frameAmount) : updateTime(0.0), frameIndex(0), frameTime(.3f)
{
	numOfFrames = frameAmount;
	name = animName;
	load(charName);
}

void Animation::update(sf::Time deltaTime, sf::Vector2f position)
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

	sprite.setPosition(position);
}

void Animation::render(sf::RenderWindow* window)
{
	window->draw(sprite);
}

sf::Vector2f Animation::getFrameSize()
{ return sf::Vector2f(frameWidth, frameHeight); }

void Animation::load(std::string charName)
{
	std::string filename = "Assets/Fighter/" + charName + "/" + name + ".png";

	if(!texture.loadFromFile(filename))
		throw std::runtime_error("Animation::load - Failed to load " + filename);

	frameWidth = texture.getSize().x / numOfFrames;
	frameHeight = texture.getSize().y;

	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, frameWidth, frameHeight));
	sprite.setPosition(0,0);
	//sprite.setOrigin();
}

void Animation::setScale(float x, float y)
{ sprite.setScale(x, y); }