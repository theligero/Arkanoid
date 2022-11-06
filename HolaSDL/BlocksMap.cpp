#include "BlocksMap.h"
#include <fstream>
#include <iostream>

void BlocksMap::loadFile(int level, Texture* blocksTexture, SDL_Window* window) //Se carga el mapa de bloques de un archivo de datos.
{
	int height, width;
	SDL_GetWindowSize(window, &width, &height); //Se asigna la altura y anchura de la ventana a dos variables.

	//Establezco la parte de la ruta que es siempre igual.
	fstream input; 
	std::string aux = "../maps/level"; 

	if (level < 10) aux += "0";
	aux += std::to_string(level) + ".dat";
	//Abro el archivo
	input.open(aux);
	if (!input) throw "Error al cargar el mapa " + level;

	int block;
	//Leo las columnas y filas que tendra el mapa de bloques.
	input >> rows >> columns;
	numBlocks = blocksInMap();
	//Ajusto el tamaño del mapa de bloques a la pantalla.
	blockTam = Vector2D((width - 30), (height - 200));
	//En funcion del tamaño del mapa de bloques y la cantidad de filas/columnas, establezco el tamaño de cada bloque.
	blockPos = Vector2D(blockTam.getX() / columns, blockTam.getY() / rows);

	//Creo y relleno el array bidimensional de punteros a bloques.
	ptrblcks = new Block**[rows];
	for (int i = 0; i < rows; ++i) {
		ptrblcks[i] = new Block*[columns];
		for (int j = 0; j < columns; ++j) {
			input >> block;
			if (block != 0) ptrblcks[i][j] = new Block(Vector2D(15 + (blockPos.getX() * j), 15 + (blockPos.getY() * i)),
				blockPos.getX(), blockPos.getY(), block, columns, rows, blocksTexture);
			else {
				ptrblcks[i][j] = nullptr;
				--numBlocks;
			}
		}
	}
	//Cierro el stream de datos del archivo.
	input.close();
}

void BlocksMap::render() const //Renderizo el array de bloques.
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
	//Paso la posición de la bola, y divido ambas variables por la anchura y 
	//la altura del bloque para ver en que columna y fila del array de bloques debo comprobar la colisión.
	columna = (ballPos.getX() -15) / blockPos.getX();
	fila = (ballPos.getY() -15) / blockPos.getY();
	if (fila > (rows -1)) fila = rows - 1;
	if (columna > (columns -1)) columna = columns - 1;
	Block* bloque = ptrblcks[fila][columna];
	return bloque;
}

bool BlocksMap::collides(SDL_Rect ball, Vector2D& normal) 
{
	Block* bloqueColision = nullptr;

	if (ball.y < 415) {
		//Esquina superior izquierda
		bloqueColision = returnBlock({(double)ball.x, (double)ball.y});
		if (bloqueColision != nullptr && !bloqueColision->getColisionado()) {
			bool colisiona = bloqueColision->collides(ball, normal, numBlocks);
			return colisiona;
		}
		//Esquina inferior izquierda
		bloqueColision = returnBlock({ (double)ball.x, (double)(ball.y + blockPos.getY()) });
		if (bloqueColision != nullptr && !bloqueColision->getColisionado()) {
			bool colisiona = bloqueColision->collides(ball, normal, numBlocks);
			return colisiona;
		}
		//Esquina superior derecha
		bloqueColision = returnBlock({ (double)(ball.x + blockPos.getX()), (double)ball.y });
		if (bloqueColision != nullptr && !bloqueColision->getColisionado()) {
			bool colisiona = bloqueColision->collides(ball, normal, numBlocks);
			return colisiona;
		}
		//Esquina inferior derecha
		bloqueColision = returnBlock({ (double)(ball.x + blockPos.getX()), (double)(ball.y + blockPos.getY()) });
		if (bloqueColision != nullptr && !bloqueColision->getColisionado()) {
			bool colisiona = bloqueColision->collides(ball, normal, numBlocks);
			return colisiona;
		}
	}
	
	return false;
}



