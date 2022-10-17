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
const int NUM_TEXTURES = 8;
const int WALL_WIDTH = 15;

enum TextureName { BALL, BRICKS, DIGITS, GAMEOVER, PADDLE, SIDE, TOPSIDE, YOUWIN };

typedef struct {
	string filename;
	int cols, rows;
} TextureDescription;

const TextureDescription TEXT_DESCR[NUM_TEXTURES] = {
	{"ball2.png", 1, 1},
	{"bricks2.png", 2, 3},
	{"digits2.jpeg", 3, 4},
	{"gameover1.png", 1, 1},
	{"paddle2.png", 1, 1},
	{"side2.png", 1, 1},
	{"topside.png", 1, 1},
	{"youwin.png", 1, 1}
};

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
	Wall* walls[3];
	Ball* ball = nullptr;
	Paddle* player = nullptr;
public:
	Game();
	~Game();

	void run();
	void render();
	void update();
	void handleEvents();
	bool collides();
};

#endif /* GAME_H_ */