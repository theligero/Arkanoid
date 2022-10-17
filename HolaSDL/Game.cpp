#include "Game.h"

Game::Game()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); // Check Memory Leaks
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("First test with SDL", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	Texture* arrayTex[NUM_TEXTURES];
	blocksMap = new BlocksMap;
	wall = new Wall;
	ball = new Ball(Vector2D(100, 100), Vector2D(0, 1), arrayTex[BALL]->getW(), arrayTex[BALL]->getH(), arrayTex[BALL], this);
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
	while (!gameOver && !exit && !win) {
		handleEvents();
		update();
		render();
	}
}

void Game::render()
{
	SDL_RenderClear(renderer);
	wall->render();
	ball->render();
	player->render();
}

void Game::update()
{
	ball->update();
	player->update();
}

void Game::handleEvents()
{
	player->handleEvents();
}

bool Game::collides()
{

}
