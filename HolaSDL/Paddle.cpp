#include "Paddle.h"
#include <iostream>

void Paddle::render() const
{
	SDL_Rect dest = getRect();

	tex->render(dest, SDL_FLIP_NONE);
}

void Paddle::update()
{
	SDL_Rect dest = getRect(); //Establezco en una variable el SDL_Rect de la bola.

	game->collides(dest, Vector2D{ 0,0 }, PELOTA); 

	if (pos.getX() >= 635 && dir.getX() > 0 || // si estoy a punto de pasarme de los bordes 
		pos.getX() <= 15 && dir.getX() < 0) // y mi dirección es hacia ellos
		dir = Vector2D(0, 0); // no me muevo
	pos += dir; // actualizo mi posición
}

void Paddle::handleEvents()
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
				game->setSaveGame();
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

bool Paddle::collides(SDL_Rect ball, Vector2D& normal)
{
	SDL_Rect dest = getRect(); //Establezco en una variable el SDL_Rect del paddle.

	// hay una imagen en la carpeta images, pero lo intentaré explicar
	// de la mejor manera que pueda

	double aux = ((double)ball.x - dest.x) + ball.w / 2; // posición relativa de la pelota respecto al paddle
	double x; // variable dirección en x
	double y; // variable dirección en y

	// se supone que P es el tamaño del paddle

	if (SDL_HasIntersection(&dest, &ball)) { // si hay intersección
		if (aux >= 0 && aux < width) { // y la pelota está dentro del paddle
			x = (2 * aux / width) - 1; // transformo la x en la función (verde) f(x) = (2x / P) - 1  
			// si está en la mitad izquierda
			if (aux < width / 2.0) y = -(2 * aux) / width; // transformo y en la función (amarilla) g(x) = - 2x / P
			// y si está en la mitad derecha
			else y = ((2 * aux) / width) - 2; // transformo y en la función (rosa) h(x) = (2x / P) - 2
		}
		else { // en caso de estar en el borde del paddle (o fuera?)
			y = 0; // la normal en y será 0
			if (aux < 0) x = -1; // si es el lado izquierdo la normal en x es -1
			else x = 1; // si es lado derecho la normal en x es 1
		}

		std::cout << "Devuelvo la normal x: " << x << ", y: " << y << std::endl;

		normal = Vector2D(x, y); // le asigno la nueva normal al vector normal
		normal.normalizeVector(); // lo normalizo

		return true; // y devuelvo verdadero
	}

	return false; // en caso contrario devuelvo falso
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