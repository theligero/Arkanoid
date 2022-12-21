#include "PauseState.h"

#include "MainMenuState.h"

PauseState::PauseState(Game* g)
{
	game = g;

	//MenuButton* jugar = new MenuButton({ 50,50 }, 150, 50, game->getArrayTex(PLAY));
	MenuButton* resumeGame = new MenuButton({ 50,50 }, 150, 50, game->getArrayTex(RESUME), backToGame, game);
	MenuButton* mainMenu = new MenuButton({ 50,400 }, 150, 50, game->getArrayTex(MAIN), backToGame, game);

	sceneObjects.push_back(resumeGame);
	sceneObjects.push_back(mainMenu);
}

PauseState::~PauseState()
{
	for (auto e : sceneObjects) {
		delete(e);
	}
}

void PauseState::update()
{
	for (auto it : sceneObjects) {
		it->update();
	}
}

void PauseState::render()
{
	for (auto it : sceneObjects) {
		it->render();
	}
}

void PauseState::handleEvent()
{
	for (auto it : sceneObjects) {
		auto objeto = dynamic_cast<MenuButton*>(it);
		objeto->handleEvent();
		if (objeto->getPressed()) {
			std::cout << "hola bitch \n";
			break;
		}
	}

}

bool PauseState::onEnter()
{
	std::cout << "entrando en PauseState\n";
	return true;
}

bool PauseState::onExit()
{
	std::cout << "saliendo de PauseState\n";
	return true;
}

void PauseState::backToGame(Game* game)
{
	game->getStateMachine()->changeState(new PlayState(game));
	//std::cout << "hola";
}