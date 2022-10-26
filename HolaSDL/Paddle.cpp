#include "Paddle.h"
#include <iostream>

void Paddle::render()
{
	SDL_Rect dest;

	dest.w = width; dest.h = height;
	dest.x = pos.getX(); dest.y = pos.getY();

	tex->render(dest, SDL_FLIP_NONE);
}

void Paddle::update()
{
	/*if (dir.getX() != -1 && pos.getX() != 0);
	else if (dir.getX() != 1 && pos.getX() != 600)*/

	// habría que hacer un condicional que le impida al jug moverse a izq si está en el borde izq y
	// der si está en el borde der
	// if (dir.getX() == -1 && pos.getX() > 0 || dir.getX() == 1 && pos.getX() < 600)
	if (pos.getX() >= 635 && dir.getX() > 0 || 
		pos.getX() <= 15 && dir.getX() < 0) dir = Vector2D(0, 0);
	pos += dir;
}

void Paddle::handleEvents()
{
	SDL_Event event;

	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym) {
			case SDLK_RIGHT:
					dir = Vector2D(10, 0);
				break;
			case SDLK_LEFT:
					dir = Vector2D(-10, 0);
				break;
			default:
				break;
			}
			break;
		case SDL_KEYUP:
			switch (event.key.keysym.sym) {
			case SDLK_RIGHT:
				if (dir.getX() > 0) dir = Vector2D(0, 0);
			case SDLK_LEFT:
				if (dir.getX() < 0) dir = Vector2D(0, 0);
			default:
				break;
			}
			break;
		default:
			break;
		}
	}
}

bool Paddle::collides(SDL_Rect ball, Vector2D& normal) const
{
	SDL_Rect dest;

	dest.w = width; dest.h = height;
	dest.x = pos.getX(); dest.y = pos.getY();

	double aux = (double)ball.x - dest.x;
	double x;
	double y;

	if (SDL_HasIntersection(&dest, &ball)) {
		if (aux >= 0 && aux < width) {
			x = (2 * aux / width) - 1;
			if (aux < width / 2.0) y = -(2 * aux) / width;
			else y = ((2 * aux) / width) - 2;
		}
		else {
			y = 0;
			if (aux < 0) x = -1;
			else x = 1;
		}

		std::cout << "Devuelvo la normal x: " << x << ", y: " << y << std::endl;

		normal = Vector2D(x, y);

		return true;
	}

	return false;
}
