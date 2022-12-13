#include <stack>
#include "GameState.h"

class GameStateMachine
{
private:
	std::stack<GameState*> gameStack;
public:
	void currentState();
	void pushState();
	void changeState();
	void popState();
};

