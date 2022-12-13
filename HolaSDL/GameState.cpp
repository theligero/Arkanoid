#include "GameState.h"

void GameState::update()
{
	for (auto it : sceneObjects) {
		it->update();
	}
}

void GameState::render()
{
	for (auto it : sceneObjects) {
		it->render();
	}
}

void GameState::handleEvent()
{
	for (auto it : sceneObjects) {
		it->handleEvents();
	}
}
