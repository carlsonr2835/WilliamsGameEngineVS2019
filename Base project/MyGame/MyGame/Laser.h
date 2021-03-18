#pragma once

#include "Engine/GameEngine.h";

class Laser : public GameObject
{
public:
	//creates our lazer
	Laser(sf::Vector2f pos);

	//functions ovverridden by game objects:
	void draw();
	void update(sf::Time& elapsed);
	sf::FloatRect getCollisionRect();
private:
	sf::Sprite sprite_;

	sf::Sound shoot_;
};

typedef std::shared_ptr<Laser> LaserPtr;