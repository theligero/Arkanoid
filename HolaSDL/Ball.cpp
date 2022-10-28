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

	if (game->collides(dest, normal)) {
		double angle = acos(Vector2D().scalarProduct(normal, -dir) / 
			(sqrt(pow(normal.getX(), 2) + pow(normal.getY(), 2)) * 
				sqrt(pow(dir.getX(), 2) + pow(dir.getY(), 2))));
		dir = dir - normal * (dir * normal) * 2;
		// dir.normalizeVector();
	}
	dir.normalizeVector();
	pos += dir;
}
