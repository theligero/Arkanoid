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
// ¿A MÁS FRAME_RATE MENOS FRAMES?
const int FRAME_RATE = 10;
const int NUM_TEXTURES = 8;
const int WALL_WIDTH = 15;

// tipo enumerado de todas las texturas
enum TextureName { BALL, BRICKS, DIGITS, GAMEOVER, PADDLE, SIDE, TOPSIDE, YOUWIN };

// estructura simple con una cadena de caracteres del archivo, y entero de final y columnas
typedef struct {
	string filename;
	int cols, rows;
} TextureDescription;

// array de TextureDescription con los datos de cada textura y si es spritesheet o no
const TextureDescription TEXT_DESCR[NUM_TEXTURES] = {
	{"ball2.png", 1, 1},
	{"bricks2.png", 3, 2},
	{"digits2.jpeg", 3, 4},
	{"gameover1.png", 1, 1},
	{"paddle2.png", 1, 1},
	{"side2.png", 1, 1},
	{"topside.png", 1, 1},
	{"youwin.png", 1, 1}
};

class Ball;

class Game
{
private:
	SDL_Window* window = nullptr; // puntero a ventana
	SDL_Renderer* renderer = nullptr; // puntero a renderizado

	bool exit = false; // booleano de salida
	bool gameOver = false; // booleano de fin de partida
	bool win = false; // booleano de victoria

	Texture* arrayTex = nullptr; // array de punteros a texturas
	BlocksMap* blocksMap = nullptr; // puntero del mapa de bloques
	Wall* walls[3]; // puntero a paredes
	Ball* ball = nullptr; // puntero a la pelota
	Paddle* player = nullptr; // puntero al jugador/pala
public:
	// constructor
	Game();
	// destructor
	~Game();

	// ejecución
	void run();
	// renderizado
	void render();
	// actualización
	void update();
	// controlador de eventos
	void handleEvents();
	// colisión de objetos
	std::tuple<bool, Vector2D> collides(Vector2D ball);
};

#endif /* GAME_H_ */