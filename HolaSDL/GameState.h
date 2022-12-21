#ifndef GAMESTATE_H_
#define GAMESTATE_H_

#include "GameObject.h"
#include "list"
#include "Game.h"

class Game;

class GameState
{
protected:
	std::list<GameObject*> sceneObjects;
	Game* game = nullptr;
public:
	virtual void update() = 0;
	virtual void render() = 0;
	virtual void handleEvent() = 0;

	virtual bool onEnter() = 0;
	virtual bool onExit() = 0;

	list<GameObject*>* getObjectList() { return &sceneObjects; };
};

#endif /*GAMESTATE_H_*/