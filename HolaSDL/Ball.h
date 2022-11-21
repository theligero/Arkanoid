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
	// constructor con su posición, ancho, alto, vector dirección, puntero a textura y al juego
	Ball(Vector2D pos, int w, int h, Vector2D dir, Texture* tex, Game* game) :
		MovingObject(pos, w, h, tex, dir), game(game){}
	// renderizado
	void render() const override;
	// actualización
	void update() override;
	// modificador de posición si la pelota sale del mapa
	void restartPosition(int WINDOW_WIDTH, int WINDOW_HEIGHT);
};

#endif /* BALL_H_ */