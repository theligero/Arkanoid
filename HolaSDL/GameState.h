#ifndef GAMESTATE_H_
#define GAMESTATE_H_

#include "GameObject.h"
#include "list"
#include "Game.h"

class GameState
{
private:
	std::list<GameObject*> sceneObjects;
	Game* game;
public:
	GameState(Game* game) : game(game) {}
	virtual void update();
	virtual void render();
	virtual void handleEvent();
};

#endif /*GAMESTATE_H_*/