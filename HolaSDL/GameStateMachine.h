#ifndef GAMESTATEMACHINE_H_
#define GAMESTATEMACHINE_H_

#include <stack>
#include "GameState.h"

class GameStateMachine
{
private:
	std::stack<GameState*> gameStack;
public:
	GameState* currentState();
	void pushState(GameState* state);
	void changeState(GameState* state); // este ni idea
	void popState();
};

#endif /*GAMESTATEMACHINE_H_*/