#include "BlocksMap.h"
#include <fstream>
#include <iostream>

BlocksMap::BlocksMap(int level, Texture* tex)
{
	loadFile(level, tex);
}

void BlocksMap::loadFile(int level, Texture* blocksTexture)
{
	int Window_Height = 800;
	int Window_Width = 600;
	Vector2D blockPos;
	Vector2D blockTam;

	fstream input; std::string aux;
	if (level < 10) aux = "../maps/level0" + std::to_string(level);
	else aux = "../maps/level" + std::to_string(level);

	aux += ".dat";

	input.open(aux);
	if (!input.is_open()) throw "Error loading texture from " + aux;

	int block;

	input >> rows >> columns;

	blockPos = Vector2D(Window_Width / columns, (Window_Height - 100) / rows);
	blockTam = Vector2D((Window_Width - 30) / columns, (Window_Height - 200) / rows);

	ptrblcks = new Block**[rows];
	for (int i = 0; i < rows; ++i) {
		ptrblcks[i] = new Block*[columns];
		for (int j = 0; j < columns; ++j) {
			input >> block;
			ptrblcks[i][j] = new Block(Vector2D(blockPos.getX() * i, blockPos.getY() * j), 
				blockTam.getX(), blockTam.getY(), block, blocksTexture);
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
