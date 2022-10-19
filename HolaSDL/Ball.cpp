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
	if (std::get<0>(game->collides(pos))) {
		Vector2D aux = std::get<1>(game->collides(pos));
		dir = dir - Vector2D(dir * aux).scalarMultiplication(2) * aux;
	}
	pos += dir;
}