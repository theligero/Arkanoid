#include "Game.h"
#include <iostream>

Game::Game()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("Arkanoid 1.0", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	//Texture* arrayTex[NUM_TEXTURES];
	//Creo el array de texturas sacando la información de un array con las descripciones de cda textura.
	for (int i = 0; i < NUM_TEXTURES; ++i) { 
		const TextureDescription& desc = TEXT_DESCR[i];
		arrayTex[i] = new Texture(renderer, desc.filename, desc.rows, desc.cols);
	}
	//Creo los diversos elementos que se representan por pantalla.
	blocksMap = new BlocksMap(currentLevel, arrayTex[BRICKS], window);
	walls[0] = new Wall(Vector2D(0, 15), 15, WINDOW_HEIGHT - 15, arrayTex[SIDE], Vector2D(1, 0));
	walls[1] = new Wall(Vector2D(0, 0), WINDOW_WIDTH, 15, arrayTex[TOPSIDE], Vector2D(0, 1));
	walls[2] = new Wall(Vector2D(WINDOW_WIDTH - 15, 15), 15, WINDOW_HEIGHT - 15, arrayTex[SIDE], Vector2D(-1, 0));
	player = new Paddle(Vector2D(WINDOW_WIDTH / 2 - 75, WINDOW_HEIGHT - 50), 150, 15, arrayTex[PADDLE]);
	ball = new Ball(Vector2D(WINDOW_WIDTH / 2 - 15, WINDOW_HEIGHT - 300), 20, 20, Vector2D(1, 1), arrayTex[BALL], this);
	//Vector2D(WINDOW_WIDTH / 2 - 15, WINDOW_HEIGHT - 300)
}

Game::~Game() //Destruyo toda la memoria dinámica creada en el juego.
{
	for (int j = 0; j < NUM_TEXTURES; ++j) {
		arrayTex[j]->~Texture();
	}
	//delete(arrayTex);
	// arrayTex->~Texture();
	blocksMap->~BlocksMap();
	delete(player);
	delete(ball);
	// delete(blocksMap);
	for (int i = 0; i < 3; ++i) {
		delete(walls[i]);
	}
	//Destruyo el render de la pantalla y la pantalla en si.
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void Game::run() //Inicio el bucle de juego.
{
	uint32_t startTime, frameTime;
	startTime = SDL_GetTicks();

	if (window == nullptr || renderer == nullptr) throw "Error cargando SDL";
	else {
		//Mientras no se pierda, se salga del juego o se gane, el juego continua.
		while (!gameOver && !exit && !win) {
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
	for (int i = 0; i < 3; ++i) {
		walls[i]->render();
	}
	ball->render();
	player->render();
	blocksMap->render();
	SDL_RenderPresent(renderer);
}

void Game::update() //Se actualizan aquellas partes del juego que se mueven.
{
	ball->update();
	player->update();
	if (ball->getRect().y > WINDOW_HEIGHT) {
		--lives;
		if (lives < 0) { gameOver = true; std::cout << "FIN DE LA PARTIDA" << std::endl; }
		else {
			ball->restartPosition(WINDOW_WIDTH,WINDOW_HEIGHT);
			std::cout << "Te quedan " << lives << " vida(s)" << std::endl;
		}
	}
	if (blocksMap->getNumBlocks() == 0) {
		currentLevel++;
		if (currentLevel > MAX_LEVELS) {
			win = true;
			std::cout << "GANASTE" << std::endl;
		}
		else {
			ball->restartPosition(WINDOW_WIDTH, WINDOW_HEIGHT);
			blocksMap->loadFile(currentLevel, arrayTex[BRICKS], window);
		}
	}
}

void Game::handleEvents() //Se manejan la E/S del jugador.
{
	player->handleEvents();
}

bool Game::collides(SDL_Rect ball, Vector2D& normal) //Se evalúan las colisiones entre la pelota y las distintas partes del juego.
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
