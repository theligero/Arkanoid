#include "Ball.h"
#include <cmath>

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

	dir.normalizeVector();

	if (game->collides(dest, normal)) {
		dir = dir - (normal.scalarMultiplication((Vector2D().scalarProduct(dir, normal) * 2)));
		dir.normalizeVector();
	}
	pos += dir;
}
