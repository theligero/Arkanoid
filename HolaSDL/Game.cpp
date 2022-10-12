#include "Game.h"

Game::Game()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); // Check Memory Leaks
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("First test with SDL", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	arrayTex = new Texture(renderer)*[3];
	blocksMap = new BlocksMap;
	wall = new Wall;
	ball = new Ball;
	player = new Paddle;
	//if (window == nullptr || renderer == nullptr)
	//	std::cout << "Error cargando SDL" << std::endl;
	//else {
	//	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	//	SDL_RenderClear(renderer);
	//	SDL_RenderPresent(renderer);
	//	SDL_Delay(5000);
	//}
}

Game::~Game()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	arrayTex->~Texture();
	blocksMap->~BlocksMap();
	delete wall;
	delete ball;
	delete player;
	SDL_Quit();
}

void Game::run()
{
}

void Game::render()
{
}

void Game::update()
{
}

void Game::handleEvents()
{
}

void Game::collides()
{
}
