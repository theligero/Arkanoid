#ifndef PADDLE_H_
#define PADDLE_H_

#include "Vector2D.h"
#include "Texture.h"

class Paddle
{
private:
	Vector2D pos;
	Vector2D dirVel;
	double width;
	double height;
	Texture* tex;

public:
	Paddle():pos(0,0),dirVel(0,0),width(0),height(0),tex(nullptr){}
	Paddle(Vector2D newPos, Vector2D new_dirVel, double w, double h, Texture* t) : pos(newPos), dirVel(new_dirVel), width(w), height(h), tex(t){}

	void render();

};
#endif

