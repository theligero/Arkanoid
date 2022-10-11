#ifndef BLOCKSMAP_H_
#define BLOCKSMAP_H_

#include "Block.h"

using PointerBlocks = Block***;

class BlocksMap
{
private:
	PointerBlocks ptrblcks;
	int rows;
	int columns;
public:
	BlocksMap() : ptrblcks(nullptr), rows(0), columns(0) {}
	// BlocksMap(int blockSize, int size) : ptrblcks(new Block**[size]) {} // provisional
	~BlocksMap() { delete[] ptrblcks; }
	void loadFile(int level, Texture* blocksTexture);
	void render() const;
	int numBlocks() const { return rows * columns; }
	Block* returnBlock(int row, int col);
	//Creo queeste funcion no va a valer



};

#endif 