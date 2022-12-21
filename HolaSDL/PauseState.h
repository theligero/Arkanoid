#ifndef PAUSESTATE_H_
#define PAUSESTATE_H_

#include "GameState.h"
#include "PlayState.h"
#include "MenuButton.h"
#include "Game.h"

class Game;

class PauseState : public GameState
{

public:
	PauseState(Game* g);
	virtual ~PauseState();

	virtual void update();
	virtual void render();
	virtual void handleEvent();

	virtual bool onEnter();
	virtual bool onExit();
	static void backToGame(Game* game);
private:

};

#endif /*MAINMENUSTATE_H_*/
