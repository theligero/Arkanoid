#ifndef WALL_H_
#define WALL_H_

#include "Vector2D.h"
#include "Texture.h"

class Wall
{
private:
	Vector2D pos; // posición de la esquina superior izquierda
	int width; // ancho
	int height; // alto
	Texture* tex; // puntero a textura
public:
	Wall() : pos(0, 0), width(0), height(0), tex(nullptr) {} // constructor vacío
	Wall(Vector2D pos, Texture* tex) : pos(pos), tex(tex) { width = tex->getW(); height = tex->getH(); }
	Wall(Vector2D pos, int width, int height, Texture* tex) : pos(pos), width(width), height(height), tex(tex) {}
	// renderizado
	void render() const;
};

#endif
