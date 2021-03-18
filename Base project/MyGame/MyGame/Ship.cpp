#include "Ship.h"

#include <memory>
#include "Laser.h"

const float SPEED = 0.3f;
const int FIRE_DELAY = 200;

Ship::Ship()
{
	sprite_.setTexture(GAME.getTexture("Resources/ship.png"));
	sprite_.setPosition(sf::Vector2f(100, 100));
}
void Ship::draw()
{
	GAME.getRenderWindow().draw(sprite_);
}
void Ship::update(sf::Time& elapsed)
{
	sf::Vector2f pos = sprite_.getPosition();
	float x = pos.x;
	float y = pos.y;

	int msElapsed = elapsed.asMilliseconds();
	//float acceleration = SPEED * msElapsed;
	float boost = 1;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		y -= SPEED * msElapsed * boost;	
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		y += SPEED * msElapsed * boost;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		x -= SPEED * msElapsed * boost;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		x += SPEED * msElapsed * boost;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
	{
		//boost += 10;
	}

	sprite_.setPosition(sf::Vector2f(x, y));

	if (fireTimer_ > 0)
	{
		fireTimer_ -= msElapsed;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && fireTimer_ <= 0)
	{
		fireTimer_ = FIRE_DELAY;

		sf::FloatRect bounds = sprite_.getGlobalBounds();

		//middle laser
		float laserX = x + bounds.width;
		float laserY = y + (bounds.height / 2.0f);

		LaserPtr laser = std::make_shared<Laser>(sf::Vector2f(laserX, laserY));
		GAME.getCurrentScene().addGameObject(laser);

		//top laser (4/5 laser body)
		laserX = x + bounds.width;
		laserY = y + (bounds.height / 8.0f);

		laser = std::make_shared<Laser>(sf::Vector2f(laserX, laserY));
		GAME.getCurrentScene().addGameObject(laser);

		//bottom laser (5/4 laser body) !!These may not be lined up
		laserX = x + bounds.width;
		laserY = y + (bounds.height / 1.25f);

		laser = std::make_shared<Laser>(sf::Vector2f(laserX, laserY));
		GAME.getCurrentScene().addGameObject(laser);
	}

	//movement wrap
	pos = sprite_.getPosition();
	x = pos.x;
	y = pos.y;
	if (x > 800)
	{
		sprite_.setPosition(sf::Vector2f(0, y));
	}
	else if (x < 0)
	{
		sprite_.setPosition(sf::Vector2f(800, y));
	}
	else if (y > 600)
	{
		sprite_.setPosition(sf::Vector2f(x, 0));
	}
	else if (y < 0)
	{
		sprite_.setPosition(sf::Vector2f(x, 600));
	}
	

}