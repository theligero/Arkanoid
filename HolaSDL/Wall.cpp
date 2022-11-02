#include "Wall.h"

void Wall::render() const
{
	SDL_Rect dest = getRect();

	tex->render(dest, SDL_FLIP_NONE);
}

bool Wall::collides(SDL_Rect ball, Vector2D& normalBall) const
{
	SDL_Rect dest = getRect();

	normalBall = normal;

	return SDL_HasIntersection(&dest, &ball);
}

SDL_Rect Wall::getRect() const
{
	SDL_Rect rect;
	rect.x = pos.getX(); rect.y = pos.getY();
	rect.w = width, rect.h = height;

	return rect;
}
