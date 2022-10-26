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
	SDL_Rect dest;
	dest.x = pos.getX(); dest.y = pos.getY();
	dest.w = width, dest.h = height;

	Vector2D normal(1, 1);

	if (game->collides(dest, normal)) {
		dir = dir - normal * Vector2D(dir * normal).scalarMultiplication(2);
		dir.normalizeVector();
	}
	pos += dir;
}
