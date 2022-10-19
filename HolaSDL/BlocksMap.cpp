#include "BlocksMap.h"
#include <fstream>
#include <iostream>

BlocksMap::BlocksMap(int level, Texture* tex)
{
	loadFile(level, tex);
}

void BlocksMap::loadFile(int level, Texture* blocksTexture)
{
	// int WINDOW_HEIGHT = SDL_GetSize
	int Window_Height = 600;
	int Window_Width = 800;
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

	blockTam = Vector2D((Window_Width - 30), (Window_Height - 200));
	blockPos = Vector2D(blockTam.getX() / columns, blockTam.getY() / rows);

	ptrblcks = new Block**[rows];
	for (int i = 0; i < rows; ++i) {
		ptrblcks[i] = new Block*[columns];
		for (int j = 0; j < columns; ++j) {
			input >> block;
			ptrblcks[i][j] = new Block(Vector2D(15 + (blockPos.getX() * j), 15 + (blockPos.getY() * i)), 
				blockPos.getX(), blockPos.getY(), block, blocksTexture);
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

Block* BlocksMap::returnBlock(int row, int col)
{
	return ptrblcks[row][col];
}
