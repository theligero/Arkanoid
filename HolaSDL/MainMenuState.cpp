#include "MainMenuState.h"

void MainMenuState::beginGame(Game* game)
{
	 game->getStateMachine()->changeState(new PlayState(game));
	//std::cout << "hola";
}

MainMenuState::MainMenuState(Game* g)
{
	game = g;

	//MenuButton* jugar = new MenuButton({ 50,50 }, 150, 50, game->getArrayTex(PLAY));
	MenuButton* jugar = new MenuButton({ 50,50 }, 150, 50, game->getArrayTex(PLAY), beginGame, game);
	MenuButton* cargar = new MenuButton({ 50,400 }, 150, 50, game->getArrayTex(EXIT), beginGame, game);

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
		if(it != nullptr)
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