#ifndef MAINMENUSTATE_H_
#define MAINMENUSTATE_H_

#include "GameState.h"
#include "MenuButton.h"

class MainMenuState : public GameState
{
public:
	MainMenuState(Game* g);

	virtual void update();
	virtual void render();
	virtual void handleEvent();

	virtual bool onEnter();
	virtual bool onExit();
};

#endif /*MAINMENUSTATE_H_*/