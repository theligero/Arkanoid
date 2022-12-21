#ifndef PADDLE_H_
#define PADDLE_H_

#include "MovingObject.h"
#include "Game.h"

class PlayState;

class Paddle : public MovingObject
{
private:
	PlayState* game;
public:
	// constructor por defecto
	Paddle() : game(nullptr) {};
	// constructor con la posici�n, ancho, alto y puntero a textura
	Paddle(Vector2D pos, int w, int h, Texture* t, PlayState* _game) :
		MovingObject(pos, w, h, t, { 0,0 }), game(_game) {}

	Paddle(fstream& input, Texture* t, PlayState* _game) :
		MovingObject(t), game(_game) { loadFromFile(input); }
	// renderizado
	void render() const override;
	// actualizaci�n
	void update() override;
	// controlador de eventos
	void handleEvent() override;
	// colisi�n
	bool collides(SDL_Rect ball, Vector2D& normal) override;
	// cambio de ancho de la pala
	void changePlatWidth(double scalar);

	void saveToFile(ofstream& input) override;

	void loadFromFile(fstream& input) override;
};
#endif

