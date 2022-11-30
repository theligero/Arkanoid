#ifndef BALL_H_
#define BALL_H_

#include "Game.h"
#include "MovingObject.h"

class Game;

class Ball : public MovingObject
{
private:
	Game* game; // puntero al juego
public:
	// constructor por defecto
	Ball() : game(nullptr) {}
	// constructor con su posici�n, ancho, alto, vector direcci�n, puntero a textura y al juego
	Ball(Vector2D pos, int w, int h, Vector2D dir, Texture* tex, Game* _game) :
		MovingObject(pos, w, h, tex, dir), game(_game){}
	// renderizado
	void render() const override;
	// actualizaci�n
	void update() override;
	// modificador de posici�n si la pelota sale del mapa
	void restartPosition(int WINDOW_WIDTH, int WINDOW_HEIGHT);

	bool isUnderDeadline(int windowHeight);

	//void loadFromFile() override;
};

#endif /* BALL_H_ */