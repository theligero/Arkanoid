#include "PlayState.h"

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
	ball = new Ball({ WINDOW_WIDTH / 2 - 15, WINDOW_HEIGHT - 300 }, 20, 20, { 1, 1 }, game->getArrayTex(BALL), this);
	sceneObjects.push_back(ball);

}

void PlayState::update()
{
	for (auto it : sceneObjects) {
		it->update();
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
	//rewardsVector.push_back(recompensa);
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
		//win = true;
		std::cout << "GANASTE" << std::endl;
	}
	else {
		resetBlockMap();
	}
}