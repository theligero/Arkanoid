#include "Button.h"

void Button::render() const //Renderizo la pared.
{
	SDL_Rect dest = getRect(); //Establezco en una variable el SDL_Rect de la pared.

	tex->render(dest, SDL_FLIP_NONE);
}

bool Button::inBounds(Vector2D coordRaton)
{
	if (coordRaton.getX() < (pos.getX() + width)
		&& coordRaton.getX() > pos.getX()
		&& coordRaton.getY() < (pos.getY() + height)
		&& coordRaton.getY() > pos.getY())
	{
		return true;
	}
	return false;
}

