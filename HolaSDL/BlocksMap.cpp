#include "BlocksMap.h"
#include <fstream>
#include <iostream>

void BlocksMap::loadFile(int level, Texture* blocksTexture, SDL_Window* window)
{
	int height, width;
	SDL_GetWindowSize(window, &width, &height);

	Vector2D blockPos;
	Vector2D blockTam;

	fstream input; 
	std::string aux = "../maps/level";

	if (level < 10) aux += "0";
	aux += std::to_string(level) + ".dat";

	input.open(aux);
	if (!input.is_open()) throw "Error loading texture from " + aux;

	int block;

	input >> rows >> columns;
	

	blockTam = Vector2D((width - 30), (height - 200));
	blockPos = Vector2D(blockTam.getX() / columns, blockTam.getY() / rows);

	ptrblcks = new Block**[rows];
	for (int i = 0; i < rows; ++i) {
		ptrblcks[i] = new Block*[columns];
		for (int j = 0; j < columns; ++j) {
			input >> block;
			if (blocksTexture != 0) ptrblcks[i][j] = new Block(Vector2D(15 + (blockPos.getX() * j), 15 + (blockPos.getY() * i)),
				blockPos.getX(), blockPos.getY(), block, blocksTexture);
			else ptrblcks[i][j] == nullptr;
		}
	}

	input.close();
}

void BlocksMap::render() const
{
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			ptrblcks[i][j]->render();
		}
	}
}

Block* BlocksMap::returnBlock(Vector2D pos) const
{
	return ptrblcks[0][0];
}