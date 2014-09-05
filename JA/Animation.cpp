#include "Animation.hpp"

const std::string Animations::SLight = "SLight";
const std::string Animations::ULight = "ULight";
const std::string Animations::DLight = "DLight";
const std::string Animations::NLight = "NLight";
const std::string Animations::Guard = "Guard";
const std::string Animations::Stand = "Stand";
const std::string Animations::Run = "Run";

Animation::Animation(std::string charName, std::string animName, std::vector<AnimFrame*> fData, bool repeat) : updateTime(0.0), frameIndex(0), isDone(false)
{
	frameData = fData;
	numOfFrames = frameData.size();
	name = animName;
	loop = repeat;
	load(charName);
}

void Animation::update(sf::Time deltaTime, sf::Vector2f position)
{
	updateTime += deltaTime.asSeconds();

	if(!isDone && updateTime >= frameData[frameIndex]->getFrameTime())
	{
		frameIndex++;
		updateTime = 0.0f;

		if(frameIndex >= numOfFrames)
		{
			if(loop)
				frameIndex = 0;
			else
			{
				isDone = true;
				frameIndex--;
			}
		}
			
		sprite.setTextureRect(sf::IntRect(frameIndex * frameWidth, 0, frameWidth, frameHeight));
	}

	sprite.setPosition(position);
}

void Animation::render(sf::RenderWindow* window)
{ window->draw(sprite); }

void Animation::reset()
{
	updateTime = 0.0;
	frameIndex = 0;
	isDone = false;
}

sf::Vector2i Animation::getFrameSize()
{ return sf::Vector2i(frameWidth, frameHeight); }

bool Animation::getIsDone()
{ return isDone; }

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