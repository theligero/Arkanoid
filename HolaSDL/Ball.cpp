#include "Ball.h"
#include <cmath>

void Ball::render() const
{
	SDL_Rect dest = getRect(); //Establezco en una variable el SDL_Rect de la bola.

	tex->render(dest); // le doy al renderizado el SDL_Rect
}

void Ball::update()
{
	SDL_Rect dest = getRect(); //Establezco en una variable el SDL_Rect de la bola.

	Vector2D normal(1, 1); // creo una normal auxiliar

	dir.normalizeVector(); // normalizo el vector direcci�n
	/////////////////////////////////////////////////////////////////////////////
	if (game->collides(dest, dir, normal, PELOTA)) { // si colisiona
		// aplico la f�rmula de la reflexi�n
		dir = dir - (normal.scalarMultiplication((Vector2D().scalarProduct(dir, normal) * 2)));
	}
	pos += dir; // avanzo la pelota
}

void Ball::restartPosition(int WINDOW_WIDTH, int WINDOW_HEIGHT)
{
	pos = Vector2D(WINDOW_WIDTH / 2, WINDOW_HEIGHT - 170);
}

bool Ball::isUnderDeadline(int windowHeight)
{
	return getRect().y > windowHeight;
}

void Ball::saveToFile(ofstream& input)
{
	input << pos.getX() << " " << pos.getY() << " " << width << 
		" " << height << " " << dir.getX() << " " << dir.getY() << "\n";
}

void Ball::loadFromFile(fstream& input)
{
	double posX, posY, dirX, dirY;
	input >> posX >> posY >> width >> height >> dirX >> dirY;
	pos = Vector2D(posX, posY);
	dir = Vector2D(dirX, dirY);
}