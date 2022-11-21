#include "Wall.h"

void Wall::render() const //Renderizo la pared.
{
	SDL_Rect dest = getRect(); //Establezco en una variable el SDL_Rect de la pared.

	tex->render(dest, SDL_FLIP_NONE);
}

bool Wall::collides(SDL_Rect ball, Vector2D& normal)
{
	SDL_Rect dest = getRect(); //Establezco en una variable el SDL_Rect de la pared.

	//Si hay interección entre pared y bola, la normal afecta a la bola y rebota.

	normal = _normal;

	return SDL_HasIntersection(&dest, &ball);
}