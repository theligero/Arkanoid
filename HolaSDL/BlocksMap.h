#ifndef BLOCKSMAP_H_
#define BLOCKSMAP_H_

#include "Block.h"
#include <iostream>
#include "ArkanoidObject.h"


using PointerBlocks = Block***;

class BlocksMap : public ArkanoidObject
{
private:
	PointerBlocks ptrblcks; // punteros a bloques
	int rows; // filas
	int columns; // columnas
	Vector2D blockTam; //Posición de un bloque respecto del blockMap.
	int numBlocks = 0; //Cantidad de bloques que quedan sin chocar por la bola.
public:
	// constructor por defecto
	BlocksMap() : 
		ptrblcks(nullptr), rows(0), columns(0) {}
	// constructor con un entero nivel, un puntero a su textura y a la ventana
	BlocksMap(int level, Texture* tex, SDL_Window* window) : 
		ArkanoidObject({ 0,0 }, 0, 0, tex) { loadFile(level, tex, window); }
	BlocksMap(fstream &input, Texture* tex) :
		ArkanoidObject({ 0,0 }, 0, 0, tex) { loadFromFile(input); }
	// destructor
	~BlocksMap() { delete[] ptrblcks; }
	// carga de archivo
	void loadFile(int level, Texture* blocksTexture, SDL_Window* win);
	// renderizado
	void render() const override;
	// entero con el número actual de bloques
	int blocksInMap() const { return rows * columns; }
	Block* returnBlock(Vector2D pos) const;
	bool collides(SDL_Rect ball, Vector2D& normal) override;
	void decreaseNumBlocks() { 
		numBlocks--; std::cout << numBlocks; };
	int getNumBlocks() { return numBlocks; };

	void saveToFile(ofstream& input) override;

	void loadFromFile(fstream& input) override;
};

#endif 