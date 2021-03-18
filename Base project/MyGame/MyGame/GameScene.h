#pragma once

#include "Engine/GameEngine.h"

class GameScene : public Scene {
 public:
	 // Creates our Scene.
	GameScene();

	//get current score
	int getScore();

	//Increase the score
	void increaseScore();

	//get the number of lives
	int getLives();

	//decrease the number of lives
	void decreaseLives();

private:
	int score_ = 0;
	int lives_ = 3;
};

typedef std::shared_ptr<GameScene> GameScenePtr;
