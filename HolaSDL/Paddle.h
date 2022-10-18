#ifndef PADDLE_H_
#define PADDLE_H_

#include "Vector2D.h"
#include "Texture.h"

class Paddle
{
private:
	Vector2D pos;
	Vector2D dir;
	double width;
	double height;
	Texture* tex;

public:
	Paddle(): pos(0,0), dir(0,0), width(0), height(0), tex(nullptr) {}
	Paddle(Vector2D pos, Texture* t) : 
		pos(pos), dir(0, 0), tex(t) { width = t->getW(); height = t->getH(); }
	Paddle(Vector2D pos, int w, int h, Texture* t) :
		pos(pos), dir(0, 0), tex(t), width (w), height(h) {}

	void render();
	void update();
	void handleEvents();
};
#endif

