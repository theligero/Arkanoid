#ifndef GAME_H_
#define GAME_H_

#include <SDL.h>
#include "Texture.h"
#include "MenuButton.h"
#include <iostream>
#include "ArkanoidObject.h"
#include "checkML.h"
#include <list>
#include <vector>
#include <fstream>
#include "GameStateMachine.h"


const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
// ¿A MÁS FRAME_RATE MENOS FRAMES?
const int FRAME_RATE = 10;
const int NUM_TEXTURES = 16;
const int WALL_WIDTH = 15;
const int MAX_LEVELS = 3;

// tipo enumerado de todas las texturas
enum TextureName { BALL, BRICKS, DIGITS, GAMEOVER, PADDLE, SIDE, TOPSIDE, YOUWIN, CARGAR, JUGAR, REWARD, PAUSEGAME, PLAY, EXIT, RESUME, MAIN };

enum CollisionType {PELOTA, PLAYER};

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
	{"youwin.png", 1, 1},
	{"cargarButton.png", 1, 1},
	{"jugarButton.png", 1, 1},
	{"rewards.png", 8, 10},
	{"pauseGame.png", 1, 1},
	{"play.png", 3, 1},
	{"exit.png", 3, 1},
	{"resume.png", 3, 1},
	{"main.png", 3, 1}
};

class Ball;
class Paddle;
class BlocksMap;
class GameStateMachine;
class MenuButton;

class Game
{
private:
	SDL_Window* window = nullptr; // puntero a ventana
	SDL_Renderer* renderer = nullptr; // puntero a renderizado

	bool menu = true;
	bool exit = false; // booleano de salida
	bool gameOver = false; // booleano de fin de partida
	bool win = false; // booleano de victoria
	bool saveGame = false;
	bool cargarArchivo = false;

	//Texture* arrayTex = nullptr; // array de punteros a texturas
	Texture* arrayTex[NUM_TEXTURES];
	//BlocksMap* blocksMap = nullptr; // puntero del mapa de bloques
	//Wall* walls[3]; // puntero a paredes
	//Ball* ball = nullptr; // puntero a la pelota
	//Paddle* player = nullptr; // puntero al jugador/pala
	//MenuButton* jugar = nullptr;
	//MenuButton* cargar = nullptr;
	GameStateMachine* stateMachine = nullptr;

	Vector2D mousePosition = {0,0};

	list<ArkanoidObject*> objectsList;
	vector<ArkanoidObject*> buttonsVector;

	/*int lives = 3;
	int currentLevel = 1;
	int numRewards = 0;
	int points = 0;*/

	SDL_Rect pauseRect; 
	
	
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
	bool collides(SDL_Rect pos, Vector2D& normal, CollisionType colision);

	void resetBlockMap();

	void save();

	void load();

	void initGame();

	void setSaveGame() { saveGame = true; }
	// Añadir una vida extra
	//void addOneUp();
	// Cambio al siguiente nivel
	//void nextLevel();
	// Añadido de puntos
	//void addPoints(const int& puntos);

	//Paddle* getPaddlePointer();

	list<ArkanoidObject*>* getObjectList() { return &objectsList;  };

	//void createReward(Vector2D _pos, int _w, int _h, Texture* _tex);

	Texture* getRewardTexture() { return arrayTex[REWARD]; }

	Texture* getArrayTex(TextureName tex) const { return arrayTex[tex]; }

	//void advanceLevel();

	GameStateMachine* getStateMachine();

	SDL_Window* getGameWindow();

	void hello() { std::cout << "hola" << "\n"; };
};

#endif /* GAME_H_ */