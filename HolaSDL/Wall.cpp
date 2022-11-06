#include "Wall.h"

void Wall::render() const //Renderizo la pared.
{
	SDL_Rect dest = getRect(); //Establezco en una variable el SDL_Rect de la pared.

	tex->render(dest, SDL_FLIP_NONE);
}

bool Wall::collides(SDL_Rect ball, Vector2D& normalBall) const
{
	SDL_Rect dest = getRect(); //Establezco en una variable el SDL_Rect de la pared.

	//Si hay interección entre pared y bola, la normal afecta a la bola y rebota.

	normalBall = normal;

	return SDL_HasIntersection(&dest, &ball);
}

SDL_Rect Wall::getRect() const //Recojo el SDL_Rect de la pared.
{
	SDL_Rect rect;
	rect.x = pos.getX(); rect.y = pos.getY();
	rect.w = width, rect.h = height;

	return rect;
}
