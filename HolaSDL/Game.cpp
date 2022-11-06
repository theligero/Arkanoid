#include "Game.h"
#include <iostream>

Game::Game()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); // Check Memory Leaks
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("Arkanoid 1.0", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	Texture* arrayTex[NUM_TEXTURES];
	for (int i = 0; i < NUM_TEXTURES; ++i) {
		const TextureDescription& desc = TEXT_DESCR[i];
		arrayTex[i] = new Texture(renderer, desc.filename, desc.rows, desc.cols);
	}
	blocksMap = new BlocksMap(1, arrayTex[BRICKS], window);
	walls[0] = new Wall(Vector2D(0, 15), 15, WINDOW_HEIGHT - 15, arrayTex[SIDE], Vector2D(1, 0));
	walls[1] = new Wall(Vector2D(0, 0), WINDOW_WIDTH, 15, arrayTex[TOPSIDE], Vector2D(0, 1));
	walls[2] = new Wall(Vector2D(WINDOW_WIDTH - 15, 15), 15, WINDOW_HEIGHT - 15, arrayTex[SIDE], Vector2D(-1, 0));
	player = new Paddle(Vector2D(WINDOW_WIDTH / 2 - 75, WINDOW_HEIGHT - 50), 150, 15, arrayTex[PADDLE]);
	ball = new Ball(Vector2D(WINDOW_WIDTH / 2 - 15, WINDOW_HEIGHT - 300), 20, 20, Vector2D(1, 1), arrayTex[BALL], this);
	//Vector2D(WINDOW_WIDTH / 2 - 15, WINDOW_HEIGHT - 300)
}

Game::~Game()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	arrayTex->~Texture();
	blocksMap->~BlocksMap();
	delete(player);
	delete(ball);
	delete(blocksMap);
	for (int i = 0; i < 3; ++i) {
		delete(walls[i]);
	}
	SDL_Quit();
}

void Game::run()
{
	uint32_t startTime, frameTime;
	startTime = SDL_GetTicks();


	while (!gameOver && !exit && !win) {
		handleEvents();
		frameTime = SDL_GetTicks() - startTime;
		if (frameTime >= FRAME_RATE) {
			update();
			startTime = SDL_GetTicks();
		}
		render();
	}

	//if (window == nullptr || renderer == nullptr) std::cout << "ERROR CARGANDO SDL" << std::endl;
	//else {

	//}

	//if (window == nullptr || renderer == nullptr)
	//	std::cout << "Error cargando SDL" << std::endl;
	//else {
	//	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	//	SDL_Delay(5000);
	//}
}

void Game::render()
{
	SDL_RenderClear(renderer);
	for (int i = 0; i < 3; ++i) {
		walls[i]->render();
	}
	ball->render();
	player->render();
	blocksMap->render();
	SDL_RenderPresent(renderer);
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

bool Game::collides(SDL_Rect ball, Vector2D& normal)
{
	// paredes
	for (int k = 0; k < 3; ++k) {
		if (walls[k]->collides(ball, normal))
			return true;
	}
	// jugador
	if (player->collides(ball, normal)) return true;
	// bloques
	 if (blocksMap->collides(ball, normal)) return true;


	return false;
	// comprobación de colisión con todos los obj
	// Vector2D pos(0, 0);
}
