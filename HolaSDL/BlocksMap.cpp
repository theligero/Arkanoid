#include "BlocksMap.h"
#include <fstream>
#include <iostream>

void BlocksMap::loadFile(int level, Texture* blocksTexture, SDL_Window* window)
{
	int height, width;
	SDL_GetWindowSize(window, &width, &height);

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
			if (block != 0) ptrblcks[i][j] = new Block(Vector2D(15 + (blockPos.getX() * j), 15 + (blockPos.getY() * i)),
				blockPos.getX(), blockPos.getY(), block, columns, rows,blocksTexture);
			else ptrblcks[i][j] = nullptr;
		}
	}

	input.close();
}

void BlocksMap::render() const
{
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			if(ptrblcks[i][j] != nullptr)
			ptrblcks[i][j]->render();
		}
	}
}

Block* BlocksMap::returnBlock(Vector2D ballPos) const
{
	int columna, fila;
	columna = (ballPos.getX() -15) / blockPos.getX();
	fila = (ballPos.getY() -15) / blockPos.getY();
	Block* bloque = ptrblcks[fila][columna];
	return bloque;
}

bool BlocksMap::collides(SDL_Rect ball, Vector2D& normal) const
{
	Block* bloqueColision = nullptr;
	if (/*ball.x > 15 && ball.x < 785 && ball.y > 15 && */ball.y < 415) {
		bloqueColision = returnBlock({(double)ball.x, (double)ball.y});
	}
	if (bloqueColision != nullptr && !bloqueColision->getColisionado()) {
		bool colisiona = bloqueColision->collides(ball, normal);
		//bloqueColision = nullptr;
		return colisiona;
	}
	return false;
}



