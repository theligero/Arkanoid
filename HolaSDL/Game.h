#ifndef GAME_H_
#define GAME_H_

#include <SDL.h>
#include "Texture.h"
#include "BlocksMap.h"
#include "Wall.h"
#include "Ball.h"
#include "Paddle.h"

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
// ¿DIMENSIONES DE LOS OBJETOS?
const int FRAME_RATE = 60;

enum Texturas { BALL, BRICKS, DIGITS, GAMEOVER, PADDLE, SIDE, TOPSIDE, YOUWIN, };

class Game
{
private:
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;

	bool exit = false;
	bool gameOver = false;
	bool win = false;

	Texture* arrayTex = nullptr;
	BlocksMap* blocksMap = nullptr;
	Wall* wall = nullptr;
	Ball* ball = nullptr;
	Paddle* player = nullptr;
public:
	Game();
	~Game();

	void run();
	void render();
	void update();
	void handleEvents();
	void collides();
};

#endif /* GAME_H_ */