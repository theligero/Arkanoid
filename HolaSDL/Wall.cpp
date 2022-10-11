#include "Wall.h"

void Wall::render() const
{
	SDL_Rect dest;

	dest.w = width; dest.h = height;
	dest.x = pos.getX(); dest.y = pos.getY();

	tex->render(dest, SDL_FLIP_NONE);
}
