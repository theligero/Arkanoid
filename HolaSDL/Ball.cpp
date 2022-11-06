#include "Ball.h"
#include <cmath>

void Ball::render()
{
	SDL_Rect dest = getRect(); //Establezco en una variable el SDL_Rect de la bola.

	tex->render(dest); // le doy al renderizado el SDL_Rect
}

void Ball::update()
{
	SDL_Rect dest = getRect(); //Establezco en una variable el SDL_Rect de la bola.

	Vector2D normal(1, 1); // creo una normal auxiliar

	dir.normalizeVector(); // normalizo el vector direcci�n

	if (game->collides(dest, normal)) { // si colisiona
		// aplico la f�rmula de la reflexi�n
		dir = dir - (normal.scalarMultiplication((Vector2D().scalarProduct(dir, normal) * 2)));
		dir.normalizeVector(); // normalizo el vector
	}
	pos += dir; // avanzo la pelota
}

SDL_Rect Ball::getRect() const //Recojo el SDL_Rect de la bola.
{
	SDL_Rect rect;
	rect.x = pos.getX(); rect.y = pos.getY();
	rect.w = width, rect.h = height;

	return rect;
}

void Ball::restartPosition(int WINDOW_HEIGHT)
{
	pos = Vector2D(pos.getX(), WINDOW_HEIGHT - 170);
	//pos.getX(), WINDOW_HEIGHT - 170
}
