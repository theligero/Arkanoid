#include "ArkanoidObject.h"

SDL_Rect ArkanoidObject::getRect() const
{
	SDL_Rect rect;
	rect.x = pos.getX(); rect.y = pos.getY();
	rect.w = width, rect.h = height;

	return rect;
}
