#ifndef PADDLE_H_
#define PADDLE_H_

#include "MovingObject.h"
#include "Game.h"

class Game;

class Paddle : public MovingObject
{
private:
	Game* game;
public:
	// constructor por defecto
	Paddle() : game(nullptr) {};
	// constructor con la posición, ancho, alto y puntero a textura
	Paddle(Vector2D pos, int w, int h, Texture* t, Game* _game) :
		MovingObject(pos, w, h, t, { 0,0 }), game(_game) {}
	// renderizado
	void render() const override;
	// actualización
	void update() override;
	// controlador de eventos
	void handleEvents() override;
	// colisión
	bool collides(SDL_Rect ball, Vector2D& normal) override;
	// cambio de ancho de la pala
	void changePlatWidth(double scalar);
};
#endif

