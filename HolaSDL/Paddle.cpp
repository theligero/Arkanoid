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

	// habr�a que hacer un condicional que le impida al jug moverse a izq si est� en el borde izq y
	// der si est� en el borde der
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

bool Paddle::collides(SDL_Rect ball) const
{
	SDL_Rect dest;

	dest.w = width; dest.h = height;
	dest.x = pos.getX(); dest.y = pos.getY();

	return SDL_HasIntersection(&dest, &ball);
}
