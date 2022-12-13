#include "GameStateMachine.h"

GameState* GameStateMachine::currentState()
{
    return gameStack.top();
}

void GameStateMachine::pushState(GameState* state)
{
    gameStack.push(state);
}

void GameStateMachine::changeState(GameState* state)
{
    while (!gameStack.empty()) {
        gameStack.pop();
    }
    gameStack.push(state);
}

void GameStateMachine::popState()
{
    if (!gameStack.empty()) 
        gameStack.pop();
}
