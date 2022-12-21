#include "Game.h"
#include "SDLError.h"
#include "FileNotFoundError.h"
#include "MainMenuState.h"
#include "PlayState.h"
#include <iostream>
#include <stdlib.h>

Game::Game()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("Arkanoid 3.0", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(renderer, 94, 186, 125, 255);
	//Creo el array de texturas sacando la información de un array con las descripciones de cda textura.
	for (int i = 0; i < NUM_TEXTURES; ++i) { 
		const TextureDescription& desc = TEXT_DESCR[i];
		arrayTex[i] = new Texture(renderer, desc.filename, desc.rows, desc.cols);
	}

	pauseRect.x = 0; pauseRect.y = 0; pauseRect.w = WINDOW_WIDTH; pauseRect.h = WINDOW_HEIGHT;

	stateMachine = new GameStateMachine();
	stateMachine->changeState(new MainMenuState(this));
}

Game::~Game() //Destruyo toda la memoria dinámica creada en el juego.
{
	for (int j = 0; j < NUM_TEXTURES; ++j) {
		arrayTex[j]->~Texture();
	}
	delete stateMachine;
	//Destruyo el render de la pantalla y la pantalla en si.
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void Game::run() //Inicio el bucle de juego.
{
	uint32_t startTime, frameTime;
	startTime = SDL_GetTicks();

	if (window == nullptr || renderer == nullptr) throw SDLError(SDL_GetError());
	else {

		//Mientras no se pierda, se salga del juego o se gane, el juego continua.
		while (!gameOver && !exit && !win && !saveGame) {
			handleEvents(); //Se maneja la E/S del juego.
			frameTime = SDL_GetTicks() - startTime;
			if (frameTime >= FRAME_RATE) { //El juego va con un Frame Rate asignado.
				update(); //Se actualizan cada una de las partes en movimiento de nuestro juego.
				startTime = SDL_GetTicks();
			}
			render();
		}
	}
}

void Game::render() //Se renderizan cada una de las partes del juego.
{
	SDL_RenderClear(renderer);

	stateMachine->render();

	SDL_RenderPresent(renderer);
}

void Game::update() //Se actualizan aquellas partes del juego que se mueven.
{
	stateMachine->update();
}

void Game::handleEvents() //Se manejan la E/S del jugador.
{
	stateMachine->currentState()->handleEvent();
}

GameStateMachine* Game::getStateMachine()
{
	return stateMachine;
}

SDL_Window* Game::getGameWindow()
{
	 return window; 
}

