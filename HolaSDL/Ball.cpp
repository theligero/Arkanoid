#include "Ball.h"

void Ball::render()
{
	SDL_Rect dest;
	dest.x = pos.getX(); dest.y = pos.getY();
	dest.w = width, dest.h = height;

	tex->render(dest);
}

void Ball::update()
{
	if (game->collides()) 
		dir = Vector2D(- dir.getX(), - dir.getY());
	pos += dir;
}