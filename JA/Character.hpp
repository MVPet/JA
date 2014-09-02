#ifndef _CHARACTER
#define _CHARACTER

#include <SFML/Graphics.hpp>
#include "Tags.hpp"
#include "AnimationHolder.hpp"

namespace States
{
	enum ID { Normal, Attacking, Hurt };
}

class Character
{
public:
	virtual void	update(sf::Time deltaTime)=0;
	virtual void	processEvents(sf::Keyboard::Key key, bool value)=0;
	void			render(sf::RenderWindow* window);
	void			load();
	void			applyFlip();

	int				getHealth();
	sf::FloatRect	getGroundBox();

	void			setGrounded(bool value);

protected:
	int					health;
	bool				grounded;
	States::ID			state;

	bool				moveRight;
	bool				moveLeft;

	bool				downPressed;
	bool				heldDown;

	bool				lightAttack;
	bool				heldLight;
	bool				heavyAttack;
	bool				heldHeavy;
	bool				specialAttack;
	bool				heldSpecial;

	int					flip;
	std::string			name;

	Animation*			currentAnimation;
	AnimationHolder		animations;

	sf::Vector2f		velocity;
	sf::Vector2f		position;
	sf::FloatRect		groundBox;

	sf::RectangleShape	temp;
};

#endif // Character.hpp