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
	for (auto gameObject : objectsList) {
		delete(gameObject);
	}
	/*blocksMap->~BlocksMap();
	delete(player);
	delete(ball);
	for (int i = 0; i < 3; ++i) {
		delete(walls[i]);
	}*/
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
		//while (menu) {
		//	handleEvents();
		//	render();
		//}
		//std::cout << "Has salido del menu" << std::endl;
		//if (cargarArchivo) {
		//	load();
		//	/*initGame();*/
		//}
		//else {
		//	initGame();
		//}

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
		//if (saveGame) {
		//	render();
		//	save();
		//}

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

bool Game::collides(SDL_Rect ball, Vector2D& normal, CollisionType colision) //Se evalúan las colisiones entre la pelota y las distintas partes del juego.
{
	switch (colision) {
	case PELOTA:
		for (auto gameObject : objectsList) {
			if (gameObject->collides(ball, normal))
				return true;
		}
		break;
	case PLAYER:
		for (auto i : rewardsVector) {
			i->collides(ball);
		}
	}
	
	
	//// paredes
	//for (int k = 0; k < 3; ++k) {
	//	if (walls[k]->collides(ball, normal))
	//		return true;
	//}
	//// jugador
	//if (player->collides(ball, normal)) return true;
	//// bloques
	//if (blocksMap->collides(ball, normal)) return true;

	return false;
	// comprobación de colisión con todos los obj
	// Vector2D pos(0, 0);
}

//void Game::resetBlockMap()
//{
//	ball->restartPosition(WINDOW_WIDTH, WINDOW_HEIGHT);
//	blocksMap->~BlocksMap();
//	blocksMap->loadFile(currentLevel, arrayTex[BRICKS], window);
//}

//void Game::save()
//{
//	string nombre;
//	cout << "\n";
//	cin >> nombre;
//	ofstream input("../saveGames/save" + nombre + ".dat");
//
//	input << currentLevel << " " << lives << "\n" << "\n";
//
//	for (auto gameObject : objectsList) {
//		gameObject->saveToFile(input);
//		input << "\n";
//	}
//
//}

//void Game::load() {
//	string nombre;
//	cout << "\n";
//	cin >> nombre;
//	string aux = "../saveGames/save" + nombre + ".dat";
//	fstream loadInput;
//
//	loadInput.open(aux);
//
//	if (!loadInput) throw FileNotFoundError(nombre + ".dat");
//	loadInput >> currentLevel >> lives;
//	
//	blocksMap = new BlocksMap(loadInput, arrayTex[BRICKS], this);
//	objectsList.push_back(blocksMap);
//	walls[0] = new Wall(loadInput, arrayTex[SIDE]);
//	objectsList.push_back(walls[0]);
//	walls[1] = new Wall(loadInput, arrayTex[TOPSIDE]);
//	objectsList.push_back(walls[1]);
//	walls[2] = new Wall(loadInput, arrayTex[SIDE]);
//	objectsList.push_back(walls[2]);
//	player = new Paddle(loadInput, arrayTex[PADDLE], this);
//	objectsList.push_back(player);
//	ball = new Ball(loadInput, arrayTex[BALL], this);
//	objectsList.push_back(ball);
//		
//	loadInput.close();
//}

//void Game::initGame()
//{
//	blocksMap = new BlocksMap(currentLevel, arrayTex[BRICKS], window, this);
//	objectsList.push_back(blocksMap);
//	walls[0] = new Wall({ 0, 15 }, 15, WINDOW_HEIGHT - 15, arrayTex[SIDE], { 1, 0 });
//	objectsList.push_back(walls[0]);
//	walls[1] = new Wall({ 0, 0 }, WINDOW_WIDTH, 15, arrayTex[TOPSIDE], { 0, 1 });
//	objectsList.push_back(walls[1]);
//	walls[2] = new Wall({ WINDOW_WIDTH - 15, 15 }, 15, WINDOW_HEIGHT - 15, arrayTex[SIDE], { -1, 0 });
//	objectsList.push_back(walls[2]);
//	player = new Paddle({ WINDOW_WIDTH / 2 - 75, WINDOW_HEIGHT - 50 }, 150, 15, arrayTex[PADDLE], this);
//	objectsList.push_back(player);
//	ball = new Ball({ WINDOW_WIDTH / 2 - 15, WINDOW_HEIGHT - 300 }, 20, 20, { 1, 1 }, arrayTex[BALL], this);
//	objectsList.push_back(ball);
//}

//void Game::addOneUp()
//{
//	lives += 1;
//}
//
//void Game::nextLevel()
//{
//	currentLevel += 1;
//	advanceLevel();
//}
//
//void Game::addPoints(const int& puntos)
//{
//	points += puntos;
//	std::cout << "Tienes un total de " << points << " puntos." << std::endl;
//}
//
//Paddle* Game::getPaddlePointer()
//{
//	return player;
//}

//void Game::createReward(Vector2D _pos, int _w, int _h, Texture* _tex) 
//{
//	numRewards++;
//	Reward* recompensa = new Reward(_pos, _w, _h, _tex, this);
//	objectsList.push_back(recompensa);
//	rewardsVector.push_back(recompensa);
//}
//
//void Game::advanceLevel() 
//{
//	if (currentLevel > MAX_LEVELS) {
//		win = true;
//		std::cout << "GANASTE" << std::endl;
//	}
//	else {
//		resetBlockMap();
//	}
//}

GameStateMachine* Game::getStateMachine()
{
	return stateMachine;
}

SDL_Window* Game::getGameWindow()
{
	 return window; 
}

