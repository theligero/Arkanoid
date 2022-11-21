#ifndef PADDLE_H_
#define PADDLE_H_

#include "MovingObject.h"

class Paddle : public MovingObject
{
public:
	// constructor por defecto
	Paddle();
	// constructor con la posici�n, ancho, alto y puntero a textura
	Paddle(Vector2D pos, int w, int h, Texture* t) :
		MovingObject(pos, w, h, t, { 0,0 }) {}
	// renderizado
	void render() const override;
	// actualizaci�n
	void update() override;
	// controlador de eventos
	void handleEvents() override;
	// colisi�n
	bool collides(SDL_Rect ball, Vector2D& normal) override;
};
#endif

