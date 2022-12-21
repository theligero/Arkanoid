#include "PlayState.h"
#include "EndState.h"

PlayState::PlayState(Game* g)
{
	game = g;
	window = game->getGameWindow();

	blocksMap = new BlocksMap(currentLevel, game->getArrayTex(BRICKS), window, this);
	sceneObjects.push_back(blocksMap);
	walls[0] = new Wall({ 0, 15 }, 15, WINDOW_HEIGHT - 15, game->getArrayTex(SIDE), { 1, 0 });
	sceneObjects.push_back(walls[0]);
	walls[1] = new Wall({ 0, 0 }, WINDOW_WIDTH, 15, game->getArrayTex(TOPSIDE), { 0, 1 });
	sceneObjects.push_back(walls[1]);
	walls[2] = new Wall({ WINDOW_WIDTH - 15, 15 }, 15, WINDOW_HEIGHT - 15, game->getArrayTex(SIDE), { -1, 0 });
	sceneObjects.push_back(walls[2]);
	player = new Paddle({ WINDOW_WIDTH / 2 - 75, WINDOW_HEIGHT - 50 }, 150, 15, game->getArrayTex(PADDLE), this);
	sceneObjects.push_back(player);
	ball = new Ball({ WINDOW_WIDTH / 2 - 15, WINDOW_HEIGHT - 150 }, 20, 20, { 1, 1 }, game->getArrayTex(BALL), this);
	sceneObjects.push_back(ball);

}

PlayState::PlayState(Game* g, fstream& input)
{
	game = g;
	window = game->getGameWindow();

	input >> currentLevel >> lives;

	blocksMap = new BlocksMap(input, game->getArrayTex(BRICKS), this);
	sceneObjects.push_back(blocksMap);
	walls[0] = new Wall(input, game->getArrayTex(SIDE));
	sceneObjects.push_back(walls[0]);
	walls[1] = new Wall(input, game->getArrayTex(TOPSIDE));
	sceneObjects.push_back(walls[1]);
	walls[2] = new Wall(input, game->getArrayTex(SIDE));
	sceneObjects.push_back(walls[2]);
	player = new Paddle(input, game->getArrayTex(PADDLE), this);
	sceneObjects.push_back(player);
	ball = new Ball(input, game->getArrayTex(BALL), this);
	sceneObjects.push_back(ball);

	input.close();
}

void PlayState::update()
{
	for (auto it : sceneObjects) {
		it->update();
	}

	if (ball->isUnderDeadline(WINDOW_HEIGHT)) {
		--lives;
		if (lives < 0) { 
			game->getStateMachine()->changeState(new EndState(game)); 
			std::cout << "FIN DE LA PARTIDA" << std::endl; 
		}
		else {
			ball->restartPosition(WINDOW_WIDTH, WINDOW_HEIGHT);
			std::cout << "Te quedan " << lives << " vida(s)" << std::endl;
		}
	}
	else if (points >= 5000) { 
		game->getStateMachine()->changeState(new EndState(game));
		std::cout << "FIN DE LA PARTIDA" << std::endl; 
	}
	else if (blocksMap->getNumBlocks() == 0) {
		currentLevel++;
		advanceLevel();
	}
}

void PlayState::render()
{
	for (auto it : sceneObjects) {
		it->render();
	}
}

void PlayState::handleEvent()
{
	for (auto it : sceneObjects) {
		it->handleEvent();
	}
}

bool PlayState::onEnter()
{
	std::cout << "entrando en PlayState\n";
	return true;
}

bool PlayState::onExit()
{
	std::cout << "Saliendo de PlayState\n";
	return true;
}

void PlayState::resetBlockMap()
{
	ball->restartPosition(WINDOW_WIDTH, WINDOW_HEIGHT);
	blocksMap->~BlocksMap();
	blocksMap->loadFile(currentLevel, game->getArrayTex(BRICKS), window);
}

void PlayState::createReward(Vector2D _pos, int _w, int _h, Texture* _tex)
{
	numRewards++;
	Reward* recompensa = new Reward(_pos, _w, _h, _tex, this);
	sceneObjects.push_back(recompensa);
	rewardsVector.push_back(recompensa);
}

void PlayState::addOneUp()
{
	lives += 1;
}

void PlayState::nextLevel()
{
	currentLevel += 1;
	advanceLevel();
}

void PlayState::addPoints(const int& puntos)
{
	points += puntos;
	std::cout << "Tienes un total de " << points << " puntos." << std::endl;
}

Paddle* PlayState::getPaddlePointer()
{
	return player;
}

void PlayState::advanceLevel()
{
	if (currentLevel > MAX_LEVELS) {
		game->getStateMachine()->changeState(new EndState(game));
		std::cout << "GANASTE" << std::endl;
	}
	else {
		resetBlockMap();
	}
}
void PlayState::enterPause()
{
	game->getStateMachine()->pushState(new PauseState(game));
}
void PlayState::save()
{
	string nombre;
	cout << "\n";
	cin >> nombre;
	ofstream input("../saveGames/save" + nombre + ".dat");

	input << currentLevel << " " << lives << "\n" << "\n";

	for (auto gameObject : sceneObjects) {
		auto salvar = dynamic_cast<ArkanoidObject*> (gameObject);
		salvar->saveToFile(input);
		input << "\n";
	}
}
void PlayState::setSave()
{
	save();
	game->setSaveGame();
}
bool PlayState::collides(const SDL_Rect& ballRect, const Vector2D& ballVel, Vector2D& collVector, CollisionType colision) //Se evalúan las colisiones entre la pelota y las distintas partes del juego.
{
	switch (colision) {
	case PELOTA:
		for (auto gameObject : sceneObjects) {
			auto arkObject = dynamic_cast<ArkanoidObject*>(gameObject);
			if (arkObject->collides(ballRect, ballVel, collVector))
				return true;
		}
		break;
	case PLAYER:
		for (auto i : rewardsVector) {
			i->collides(ballRect);
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