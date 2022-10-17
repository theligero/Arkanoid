#ifndef BALL_H_
#define BALL_H_

#include "Vector2D.h"
#include "Texture.h"
#include "Game.h"

class Ball
{
private:
	Vector2D pos;
	int width;
	int height;
	Vector2D dir;
	Texture* tex;
	Game* game;
public:
	Ball() : pos(0, 0), width(0), height(0), dir(0, 0), tex(nullptr), game(nullptr) {}
	Ball(Vector2D pos, Vector2D dir, Texture* tex, Game* game) : 
		pos(pos), dir(dir), tex(tex), game(game) { width = tex->getW(); height = tex->getH(); }
	void render();
	void update();
};

#endif /* BALL_H_ */