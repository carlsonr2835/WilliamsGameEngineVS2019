#pragma once
#include "Engine/GameEngine.h"

class Lives : public GameObject
{
public:
	//creates the score instance
	Lives(sf::Vector2f pos);

	//functions overriden from gameobject:
	void draw();
	void update(sf::Time& elsapsed);

private:
	sf::Text text_;
};

typedef std::shared_ptr<Lives> LivesPtr;