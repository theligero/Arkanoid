#ifndef PADDLE_H_
#define PADDLE_H_

#include "Vector2D.h"
#include "Texture.h"

class Paddle
{
private:
	Vector2D pos; // posici�n
	Vector2D dir; // vector direcci�n
	double width; // ancho
	double height; // alto
	Texture* tex; // puntero a su textura

public:
	// constructor por defecto
	Paddle(): pos(0,0), dir(0,0), width(0), height(0), tex(nullptr) {}
	// constructor con la posici�n, ancho, alto y puntero a textura
	Paddle(Vector2D pos, int w, int h, Texture* t) :
		pos(pos), dir(0, 0), tex(t), width (w), height(h) {}

	// renderizado
	void render();
	// actualizaci�n
	void update();
	// controlador de eventos
	void handleEvents();
};
#endif

