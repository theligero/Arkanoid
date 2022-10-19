#ifndef PADDLE_H_
#define PADDLE_H_

#include "Vector2D.h"
#include "Texture.h"

class Paddle
{
private:
	Vector2D pos; // posición
	Vector2D dir; // vector dirección
	double width; // ancho
	double height; // alto
	Texture* tex; // puntero a su textura

public:
	// constructor por defecto
	Paddle(): pos(0,0), dir(0,0), width(0), height(0), tex(nullptr) {}
	// constructor con la posición, ancho, alto y puntero a textura
	Paddle(Vector2D pos, int w, int h, Texture* t) :
		pos(pos), dir(0, 0), tex(t), width (w), height(h) {}

	// renderizado
	void render();
	// actualización
	void update();
	// controlador de eventos
	void handleEvents();
};
#endif

