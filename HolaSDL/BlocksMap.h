#ifndef BLOCKSMAP_H_
#define BLOCKSMAP_H_

#include "Block.h"
#include "checkML.h"
#include <iostream>

using PointerBlocks = Block***;

class BlocksMap
{
private:
	PointerBlocks ptrblcks; // punteros a bloques
	int rows; // filas
	int columns; // columnas
	Vector2D blockPos; //Posición de un bloque respecto del blockMap.
	Vector2D blockTam; //Tamaño del blockMap respecto de la pantalla.
	int numBlocks = 0; //Cantidad de bloques que quedan sin chocar por la bola.
public:
	// constructor por defecto
	BlocksMap() : ptrblcks(nullptr), rows(0), columns(0) {}
	// constructor con un entero nivel, un puntero a su textura y a la ventana
	BlocksMap(int level, Texture* tex, SDL_Window* window) { loadFile(level, tex, window); }
	// destructor
	~BlocksMap() { delete[] ptrblcks; }
	// carga de archivo
	void loadFile(int level, Texture* blocksTexture, SDL_Window* win);
	// renderizado
	void render() const;
	//// entero con el número actual de bloques
	int blocksInMap() const { return rows * columns; }
	Block* returnBlock(Vector2D pos) const;
	bool collides(SDL_Rect ball, Vector2D& normal) ; 
	void decreaseNumBlocks() { numBlocks--; std::cout << numBlocks; };
	int getNumBlocks() { return numBlocks; };
};

#endif 