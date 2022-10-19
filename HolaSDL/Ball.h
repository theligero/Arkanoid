#ifndef BALL_H_
#define BALL_H_

#include "Vector2D.h"
#include "Texture.h"
#include "Game.h"

class Game;

class Ball
{
private:
	Vector2D pos; // posición
	int width; // ancho
	int height; // alto
	Vector2D dir; // vector dirección
	Texture* tex; // puntero a su textura
	Game* game; // puntero al juego
public:
	// constructor por defecto
	Ball() : pos(0, 0), width(0), height(0), dir(0, 0), tex(nullptr), game(nullptr) {}
	// constructor con su posición, ancho, alto, vector dirección, puntero a textura y al juego
	Ball(Vector2D pos, int w, int h, Vector2D dir, Texture* tex, Game* game) :
		pos(pos), dir(dir), tex(tex), game(game), width(w), height(h) {}
	// renderizado
	void render();
	// actualización
	void update();
};

#endif /* BALL_H_ */