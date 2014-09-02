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

	flip = 1.f;
}

void Kenshiro::update(sf::Time deltaTime)
{
	if(moveLeft)
	{
		flip = -1.f;
		velocity.x = -98.f;
	}
	else if(moveRight)
	{
		flip = 1.f;
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

	if(downPressed)
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
			//if(moveLeft || moveRight)
				//SideLight();
			//else if(moveUp)
				//UpLight();
			//else if(downPressed)
				//DownLight();
			//else
				//NeutralLight();
			}
			else
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
			else
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
			else
				//AirSpecial();
		}
	}

	position.x += (velocity.x * deltaTime.asSeconds());
	position.y += (velocity.y * deltaTime.asSeconds());

	applyFlip();

	currentAnimation->update(deltaTime, position);

	groundBox = sf::FloatRect(position.x, position.y, currentAnimation->getFrameSize().x, 1);
	groundBox.left = position.x;
	groundBox.top = position.y + currentAnimation->getFrameSize().y;

	temp.setPosition(groundBox.left, groundBox.top);
	temp.setSize(sf::Vector2f(groundBox.width, groundBox.height));
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