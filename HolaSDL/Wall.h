#ifndef WALL_H_
#define WALL_H_

#include "Vector2D.h"
#include "Texture.h"

class Wall
{
private:
	Vector2D pos; // posici�n de la esquina superior izquierda
	int width; // ancho
	int height; // alto
	Texture* tex; // puntero a textura
	Vector2D normal;
public:
	// constructor por defecto
	Wall() : pos(0, 0), width(0), height(0), tex(nullptr), normal(0, 0) {}
	// constructor con su posici�n, ancho, alto y puntero a textua como par�metros
	Wall(Vector2D pos, int width, int height, Texture* tex, Vector2D normal) : 
		pos(pos), width(width), height(height), tex(tex), normal(normal) {}
	// renderizado
	void render() const;
	// colisi�n
	bool collides(SDL_Rect ball, Vector2D& normal) const;
};

#endif
