#ifndef MAINMENUSTATE_H_
#define MAINMENUSTATE_H_

#include "GameState.h"
#include "PlayState.h"
#include "MenuButton.h"
#include "Game.h"

class Game;

class MainMenuState : public GameState
{

public:
	static void beginGame(Game* game);
	MainMenuState(Game* g);
	virtual ~MainMenuState();

	virtual void update();
	virtual void render();
	virtual void handleEvent();

	virtual bool onEnter();
	virtual bool onExit();

	

private:
	//CallBack *funcHello;
	//funcHello(
	};

#endif /*MAINMENUSTATE_H_*/