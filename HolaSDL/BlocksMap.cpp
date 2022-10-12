#include "BlocksMap.h"
#include <fstream>

void BlocksMap::loadFile(int level, Texture* blocksTexture)
{
	int Window_Height = 800;
	int Window_Width = 600;
	Vector2D blockPos;

	fstream input; std::string aux;
	if (level < 10) aux = "level0" + level;
	else aux = "level" + level;

	aux += ".dat";

	input.open(aux);

	int rows, cols, block;

	input >> rows >> cols;

	blockPos = Vector2D(Window_Width / cols, Window_Height / rows);

	ptrblcks = new Block**[rows];
	for (int i = 0; i < rows; ++i) {
		ptrblcks[i] = new Block*[cols];
		for (int j = 0; j < cols; ++j) {
			input >> block;
			ptrblcks[i][j] = new Block(Vector2D(blockPos.getX() * i, blockPos.getY() * j), blockPos.getX(), blockPos.getY(), block, blocksTexture);
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
