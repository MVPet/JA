#include "AnimFrame.hpp"

AnimFrame::AnimFrame(sf::IntRect hBox, sf::IntRect aBox, float fTime)
{
	hurtBox = hBox;
	hasAttackBox = true;
	attackBox = aBox;
	frameTime = fTime;
}

AnimFrame::AnimFrame(sf::IntRect hBox, float fTime)
{
	hurtBox = hBox;
	hasAttackBox = false;
	attackBox = sf::IntRect(5000, 5000, 5000, 5000);
	frameTime = fTime;
}

float AnimFrame::getFrameTime()
{ return frameTime; }