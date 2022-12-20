#include "BlocksMap.h"
#include "FileNotFoundError.h"
#include "FileFormatError.h"
#include <fstream>
#include <iostream>



// Se carga el mapa de bloques de un archivo de datos.
void BlocksMap::loadFile(int level, Texture* blocksTexture, SDL_Window* window)
{
	int h, w;
	SDL_GetWindowSize(window, &w, &h); // Se asigna la altura y anchura de la ventana a dos variables.

	// Establezco la parte de la ruta que es siempre igual.
	fstream input; 
	std::string aux = "../maps/level"; 

	if (level < 10) aux += "0";
	aux += std::to_string(level) + ".dat";
	// Abro el archivo
	input.open(aux);
	if (!input) throw FileNotFoundError(std::to_string(level) + ".dat");

	int block;
	// Leo las columnas y filas que tendra el mapa de bloques.
	input >> rows >> columns;
	if (rows < 0 || columns < 0) throw FileFormatError(FileFormatError::TamanoIncorrecto(level));
	numBlocks = blocksInMap();
	// Ajusto el tamaño del mapa de bloques a la pantalla.
	width = (w - 30);
	height = (h - 200);
	// En función del tamaño del mapa de bloques y la cantidad de filas/columnas, establezco el tamaño de cada bloque.
	blockTam = Vector2D(width / columns, height / rows);

	// Creo y relleno el array bidimensional de punteros a bloques.
	ptrblcks = new Block**[rows];
	for (int i = 0; i < rows; ++i) {
		ptrblcks[i] = new Block*[columns];
		for (int j = 0; j < columns; ++j) {
			input >> block;
			if (block == 0) { ptrblcks[i][j] = nullptr; --numBlocks; }
			else if (block > 0 && block < 7)
				ptrblcks[i][j] = new Block(Vector2D(15 + (blockTam.getX() * j), 15 + (blockTam.getY() * i)),
					blockTam.getX(), blockTam.getY(), block, columns, rows, blocksTexture, game);
			else throw FileFormatError(FileFormatError::ValorDeColorIncorrecto(block));
		}
	}
	// Cierro el stream de datos del archivo.
	input.close();
}

// Renderizo el array de bloques
void BlocksMap::render() const
{
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			if (ptrblcks[i][j] != nullptr)
				ptrblcks[i][j]->render();
		}
	}
}

Block* BlocksMap::returnBlock(Vector2D ballPos) const
{
	int columna, fila;
	//Paso la posición de la bola, y divido ambas variables por la anchura y 
	//la altura del bloque para ver en que columna y fila del array de bloques debo comprobar la colisión.
	columna = (ballPos.getX() -15) / blockTam.getX();
	fila = (ballPos.getY() -15) / blockTam.getY();
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
		bloqueColision = returnBlock({ (double)ball.x, (double)(ball.y + ball.h) });
		if (bloqueColision != nullptr && !bloqueColision->getColisionado()) {
			bool colisiona = bloqueColision->collides(ball, normal, numBlocks);
			return colisiona;
		}
		//Esquina superior derecha
		bloqueColision = returnBlock({ (double)(ball.x + ball.w), (double)ball.y });
		if (bloqueColision != nullptr && !bloqueColision->getColisionado()) {
			bool colisiona = bloqueColision->collides(ball, normal, numBlocks);
			return colisiona;
		}
		//Esquina inferior derecha
		bloqueColision = returnBlock({ (double)(ball.x + ball.w), (double)(ball.y + ball.h) });
		if (bloqueColision != nullptr && !bloqueColision->getColisionado()) {
			bool colisiona = bloqueColision->collides(ball, normal, numBlocks);
			return colisiona;
		}
	}
	
	return false;
}

void BlocksMap::saveToFile(ofstream& input)
{
	input << rows << " " << columns << " " << width << " " << height << " " << blockTam.getX() << " " << blockTam.getY() << "\n";
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			if (ptrblcks[i][j] != nullptr && !ptrblcks[i][j]->getColisionado()) {
				input << ptrblcks[i][j]->getColor() << " ";
			}
			else {
				input << 0 << " ";
			}
		}
		input << "\n";
	}

}

void BlocksMap::loadFromFile(fstream& input)
{	
	double tamX, tamY;
	input >> rows >> columns >> width >> height >> tamX >> tamY;
	blockTam = Vector2D(tamX, tamY);
	// Creo y relleno el array bidimensional de punteros a bloques.
	int block;
	ptrblcks = new Block * *[rows];
	for (int i = 0; i < rows; ++i) {
		ptrblcks[i] = new Block * [columns];
		for (int j = 0; j < columns; ++j) {
			input >> block;
			if (block == 0) { ptrblcks[i][j] = nullptr; --numBlocks; }
			else if (block > 0 && block < 6)
				ptrblcks[i][j] = new Block(Vector2D(15 + (blockTam.getX() * j), 15 + (blockTam.getY() * i)),
					blockTam.getX(), blockTam.getY(), block, columns, rows, tex, game);
			else throw FileFormatError(FileFormatError::ValorDeColorIncorrecto(block));
		}
	}

}