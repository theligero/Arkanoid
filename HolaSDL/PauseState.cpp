#include "PauseState.h"
#include "MainMenuState.h"

PauseState::PauseState(Game* g)
{
	game = g;

	MenuButton* resumeGame = new MenuButton({ 50,50 }, 150, 50, game->getArrayTex(RESUME), backToGame, game);
	MenuButton* mainMenu = new MenuButton({ 50,400 }, 150, 50, game->getArrayTex(MAIN), backToMenu, game);

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
	SDL_Event ev;

	while (SDL_PollEvent(&ev)) {
		switch (ev.type) {
		case SDL_MOUSEBUTTONDOWN:
			switch (ev.button.button) {
			case SDL_BUTTON_LEFT:
				for (auto it : sceneObjects) {
					auto objeto = dynamic_cast<MenuButton*>(it);
					objeto->handleEvent();
					if (objeto->getPressed()) {
						std::cout << "prueba \n";
						break;
					}
				}
				break;
			}
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
	game->getStateMachine()->popState();
}

void PauseState::backToMenu(Game* game)
{
	game->getStateMachine()->changeState(new MainMenuState(game));
}