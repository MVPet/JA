#include "Character.hpp"

void Character::render(sf::RenderWindow* window)
{
	currentAnimation->render(window);
}

/*void Character::load()
{
	//anim = new Animation(name, Animations::Stand, 4);
	animations.load(name, Animations::Stand, 4);
	animations.load(name, Animations::Run, 8);
	animations.load(name, Animations::Guard, 3);
	animations.load(name, Animations::NLight, 5);
	animations.load(name, Animations::SLight, 8);
	animations.load(name, Animations::ULight, 8);
	animations.load(name, Animations::DLight, 8);

	currentAnimation = animations.get(Animations::Stand);

	groundBox = sf::FloatRect(0, currentAnimation->getFrameSize().y, currentAnimation->getFrameSize().x, 10);
}*/

int Character::getHealth()
{ return health; }

sf::FloatRect Character::getGroundBox()
{ return groundBox; }

void Character::setGrounded(bool value)
{ 
	grounded = value;
	velocity.y = 0;
}

void Character::applyFlip()
{
	currentAnimation->setScale((float)flip, 1.f);
}