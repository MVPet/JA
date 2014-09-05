#include "Kenshiro.hpp"

Kenshiro::Kenshiro(sf::Vector2f spawn)
{
	name = Tags::Kenshiro;
	position = spawn;
	grounded = false;
	state = States::Normal;

	moveLeft = false;
	moveRight = false;

	downPressed = false;
	heldDown = false;

	lightAttack = false;
	heldLight = false;

	heavyAttack = false;
	heldHeavy = false;

	specialAttack = false;
	heldSpecial = false;

	flip = 1;
}

void Kenshiro::update(sf::Time deltaTime)
{
	if(state == States::Normal)
	{
		if(moveLeft)
		{
			flip = -1;
			velocity.x = -98.f;
		}
		else if(moveRight)
		{
			flip = 1;
			velocity.x = 98.f;
		}
		else
			velocity.x = 0;

		if(!grounded)
			velocity.y = 98.f;

		if(velocity.x != 0)
			currentAnimation = animations.get(Animations::Run);
		else
			currentAnimation = animations.get(Animations::Stand);

		if(downPressed && grounded)
		{
			velocity = sf::Vector2f(0,0);
			currentAnimation = animations.get(Animations::Guard);
		}

		if(state != States::Attacking || state != States::Hurt)
		{
			if(lightAttack)
			{
				if(grounded)
				{
					if(moveLeft || moveRight)
						SideLight();
					//else if(moveUp)
					//UpLight();
					//else if(downPressed)
					//DownLight();
					else
						NeutralLight();
				}
				//else
				//AirLight();
			}
			else if(heavyAttack)
			{
				if(grounded)
				{
					//if(moveLeft || moveRight)
					//SideHeavy();
					//else if(moveUp)
					//UpHeavy();
					//else if(downPressed)
					//DownHeavy();
					//else
					//NeutralHeavy();
				}
				//else
				//AirHeavy();
			}
			else if(specialAttack)
			{
				if(grounded)
				{
					//if(moveLeft || moveRight)
					//SideSpecial();
					//else if(moveUp)
					//UpSpecial();
					//else if(downPressed)
					//DownSpecial();
					//else
					//NeutralSpecial();
				}
				//else
				//AirSpecial();
			}
		}

		position.x += (velocity.x * deltaTime.asSeconds());
		position.y += (velocity.y * deltaTime.asSeconds());
	}
	else
	{
		if(currentAnimation->getIsDone())
		{
			state = States::Normal;
			currentAnimation = animations.get(Animations::Stand);
		}
	}

	applyFlip();

	currentAnimation->update(deltaTime, position);

	groundBox = sf::FloatRect(position.x, position.y, currentAnimation->getFrameSize().x, 1);
	groundBox.left = position.x;
	groundBox.top = position.y + currentAnimation->getFrameSize().y;
}

void Kenshiro::processEvents(sf::Keyboard::Key key, bool value)
{

	if(key == sf::Keyboard::Right)
		moveRight = value;
	else if(key == sf::Keyboard::Left)
		moveLeft = value;

	if(key == sf::Keyboard::Down)
		downPressed = value;

	if(key == sf::Keyboard::Q)
		lightAttack = value;
	else if(key == sf::Keyboard::W)
		heavyAttack = value;
	else if(key == sf::Keyboard::E)
		specialAttack = value;
}

void Kenshiro::NeutralLight()
{
	state = States::Attacking;

	currentAnimation = animations.get(Animations::NLight);
	currentAnimation->reset();
}

void Kenshiro::SideLight()
{
	state = States::Attacking;

	currentAnimation = animations.get(Animations::SLight);
	currentAnimation->reset();
}

void Kenshiro::DownLight()
{}

void Kenshiro::UpLight()
{}

void Kenshiro::load()
{
	std::vector<AnimFrame*> temp;
	temp.push_back(new AnimFrame(sf::IntRect(8,0,24,60), .3f));
	temp.push_back(new AnimFrame(sf::IntRect(8,0,24,60), .3f));
	temp.push_back(new AnimFrame(sf::IntRect(8,0,24,60), .3f));
	temp.push_back(new AnimFrame(sf::IntRect(8,0,24,60), .3f));

	animations.load(name, Animations::Stand, temp, true);

	temp.clear();

	temp.push_back(new AnimFrame(sf::IntRect(12,2,29,55), .1f));
	temp.push_back(new AnimFrame(sf::IntRect(12,2,29,55), .1f));
	temp.push_back(new AnimFrame(sf::IntRect(12,2,29,55), .1f));
	temp.push_back(new AnimFrame(sf::IntRect(12,2,29,55), .1f));
	temp.push_back(new AnimFrame(sf::IntRect(12,2,29,55), .1f));
	temp.push_back(new AnimFrame(sf::IntRect(12,2,29,55), .1f));
	temp.push_back(new AnimFrame(sf::IntRect(12,2,29,55), .1f));
	temp.push_back(new AnimFrame(sf::IntRect(12,2,29,55), .1f));

	animations.load(name, Animations::Run, temp, true);

	temp.clear();

	temp.push_back(new AnimFrame(sf::IntRect(5,0,24,60), .3f));
	temp.push_back(new AnimFrame(sf::IntRect(5,0,24,60), .3f));
	temp.push_back(new AnimFrame(sf::IntRect(5,0,24,60), .3f));

	animations.load(name, Animations::Guard, temp, false);

	currentAnimation = animations.get(Animations::Stand);

	temp.clear();

	temp.push_back(new AnimFrame(sf::IntRect(6,0, 22, 60), sf::IntRect(28, 9, 10, 18), .1f));
	temp.push_back(new AnimFrame(sf::IntRect(6,0, 22, 60), sf::IntRect(28, 9, 17, 19), .1f));
	temp.push_back(new AnimFrame(sf::IntRect(6,0, 22, 60), sf::IntRect(35, 13, 24, 12), .1f));
	temp.push_back(new AnimFrame(sf::IntRect(6,0, 22, 60), sf::IntRect(39, 13, 20, 12), .1f));
	temp.push_back(new AnimFrame(sf::IntRect(6,0, 22, 60), .1f));

	animations.load(name, Animations::NLight, temp, false);

	temp.clear();

	temp.push_back(new AnimFrame(sf::IntRect(6,0,22,60), .1f));
	temp.push_back(new AnimFrame(sf::IntRect(6,0,22,60), .1f));
	temp.push_back(new AnimFrame(sf::IntRect(6,0,22,60), .1f));
	temp.push_back(new AnimFrame(sf::IntRect(6,0,22,60), sf::IntRect(22,22,14,10),.1f));
	temp.push_back(new AnimFrame(sf::IntRect(6,0,22,60), sf::IntRect(34,13,30,21),.1f));
	temp.push_back(new AnimFrame(sf::IntRect(6,0,22,60), sf::IntRect(41,17,23,13),.1f));
	temp.push_back(new AnimFrame(sf::IntRect(6,0,22,60), .1f));
	temp.push_back(new AnimFrame(sf::IntRect(6,0,22,60), .1f));

	animations.load(name, Animations::SLight, temp, false);
}