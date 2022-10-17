#include "Paddle.h"

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

	pos += dir;
}

void Paddle::handleEvents()
{
	SDL_Event event;

	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDLK_RIGHT:
			dir = Vector2D(1, 0);
			break;
		case SDLK_LEFT:
			dir = Vector2D(-1, 0);
			break;
		default:
			dir = Vector2D(0, 0);
			break;
		}
	}
}
