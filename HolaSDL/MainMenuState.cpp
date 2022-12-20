#include "MainMenuState.h"

MainMenuState::MainMenuState(Game* g)
{
	game = g;

	MenuButton* jugar = new MenuButton({ 50,50 }, 150, 50, game->getArrayTex(PLAY));
	MenuButton* cargar = new MenuButton({ 50,400 }, 150, 50, game->getArrayTex(EXIT));

	sceneObjects.push_back(jugar);
	sceneObjects.push_back(cargar);
}

MainMenuState::~MainMenuState()
{
	for (auto e : sceneObjects) {
		delete(e);
	}
}

void MainMenuState::update()
{
	for (auto it : sceneObjects) {
		it->update();
	}
}

void MainMenuState::render()
{
	for (auto it : sceneObjects) {
		it->render();
	}
}

void MainMenuState::handleEvent()
{
	for (auto it : sceneObjects) {
		it->handleEvent();
	}
}

bool MainMenuState::onEnter()
{
	std::cout << "entrando en MenuState\n";
	return true;
}

bool MainMenuState::onExit()
{
	std::cout << "saliendo de MenuState\n";
	return true;
}
