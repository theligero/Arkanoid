#include "PlayState.h"

void PlayState::update()
{
	//for (auto it : sceneObjects) {
	//	it->update();
	//}
}

void PlayState::render()
{
	//for (auto it : sceneObjects) {
	//	it->render();
	//}
}

void PlayState::handleEvent()
{
	//for (auto it : sceneObjects) {
	//	it->handleEvents();
	//}
}

bool PlayState::onEnter()
{
	std::cout << "entrando en PlayState\n";
	return true;
}

bool PlayState::onExit()
{
	std::cout << "Saliendo de PlayState\n";
	return true;
}
