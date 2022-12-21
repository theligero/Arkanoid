#include "Paddle.h"
#include <iostream>

void Paddle::render() const
{
	SDL_Rect dest = getRect();

	tex->render(dest, SDL_FLIP_NONE);
}

void Paddle::update()
{
	game->collides(getRect(), dir, Vector2D{ 0,0 }, PLAYER); /////////////////////////////////////

	if (pos.getX() >= 635 && dir.getX() > 0 || // si estoy a punto de pasarme de los bordes 
		pos.getX() <= 15 && dir.getX() < 0) // y mi dirección es hacia ellos
		dir = Vector2D(0, 0); // no me muevo
	pos += dir; // actualizo mi posición
}

void Paddle::handleEvent()
{
	// creo un evento auxiliar
	SDL_Event event;

	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_KEYDOWN: // si pulso una tecla
			switch (event.key.keysym.sym) {
			case SDLK_RIGHT: // y es la flecha derecha
					dir = Vector2D(10, 0); // muevo el paddle a der
				break;
			case SDLK_LEFT: // y es la flecha izquierda
					dir = Vector2D(-10, 0); // muevo el paddle a izq
				break;
			case SDLK_s: // y es la flecha derecha
				std::cout << "hola";
				game->setSave();   ////////////////////////////////////////////////////////
				break;
			case SDLK_ESCAPE:
				std::cout << "hola";
				game->enterPause();
				break;
			default:
				break;
			}
			break;
		case SDL_KEYUP: // si levanto la tecla
			switch (event.key.keysym.sym) {
			case SDLK_RIGHT: // y pulso la flecha derecha
				if (dir.getX() > 0) dir = Vector2D(0, 0); // Freno el paddle
			case SDLK_LEFT: // y pulso la flecha izquierda
				if (dir.getX() < 0) dir = Vector2D(0, 0); //Freno el paddle.
			default:
				break;
			}
			break;
		default:
			break;
		}
	}
}

bool Paddle::collides(const SDL_Rect& ballRect, const Vector2D& ballVel, Vector2D& collVector)
{
	if ((ballRect.y + ballRect.h >= pos.getY()) && (ballRect.x <= pos.getX() + width)
		&& ((ballRect.x + ballRect.w) >= pos.getX()) && ballVel.getY() >= 0) {
		// ratioToCenter is in [-1,1}, 0 if in the center and 1 (or -1) if in the border
		double ratioToCenter = ((ballRect.x + ballRect.w / 2.0) - (pos.getX() + width / 2.0)) / (width / 2.0 + ballRect.w / 2.0);
		collVector = { ratioToCenter,-2.5 };
		// collVector.normalize();
		return true;
	}
	else return false;
}

void Paddle::changePlatWidth(double scalar)
{
	width *= scalar;
}

void Paddle::saveToFile(ofstream& input)
{
	input << pos.getX() << " " << pos.getY() << " " << width << " " << height << "\n";
}

void Paddle::loadFromFile(fstream& input)
{
	double posX, posY;
	input >> posX >> posY >> width >> height;
	pos = Vector2D(posX, posY);
}