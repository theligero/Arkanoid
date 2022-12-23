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

bool BlocksMap::collides(const SDL_Rect& ballRect, const Vector2D& ballVel, Vector2D& collVector)
{
	Vector2D p0 = { (double)ballRect.x, (double)ballRect.y }; // top-left
	Vector2D p1 = { (double)(ballRect.x + ballRect.w), (double)ballRect.y }; // top-right
	Vector2D p2 = { (double)ballRect.x, (double)(ballRect.y + ballRect.h) }; // bottom-left
	Vector2D p3 = { (double)(ballRect.x + ballRect.w), (double)(ballRect.y + ballRect.h) }; // bottom-right

	Block* b = nullptr;
	if (ballRect.y < height) {
		if (ballVel.getX() < 0 && ballVel.getY() < 0) {
			if ((b = returnBlock(p0))) {
				if ((b->getRect().y + b->getRect().h - p0.getY()) <= (b->getRect().x + b->getRect().w - p0.getX()))
					collVector = { 0,1 }; // Borde inferior mas cerca de p0
				else
					collVector = { 1,0 }; // Borde dcho mas cerca de p0
			}
			else if ((b = returnBlock(p1))) {
				collVector = { 0,1 };
			}
			else if ((b = returnBlock(p2))) collVector = { 1,0 };
		}
		else if (ballVel.getX() >= 0 && ballVel.getY() < 0) {
			if ((b = returnBlock(p1))) {
				if (((b->getRect().y + b->getRect().h - p1.getY()) <= (p1.getX() - b->getRect().x)) || ballVel.getX() == 0)
					collVector = { 0,1 }; // Borde inferior mas cerca de p1
				else
					collVector = { -1,0 }; // Borde izqdo mas cerca de p1
			}
			else if ((b = returnBlock(p0))) {
				collVector = { 0,1 };
			}
			else if ((b = returnBlock(p3))) collVector = { -1,0 };
		}
		else if (ballVel.getX() > 0 && ballVel.getY() > 0) {
			if ((b = returnBlock(p3))) {
				if (((p3.getY() - b->getRect().y) <= (p3.getX() - b->getRect().x))) // || ballVel.getX() == 0)
					collVector = { 0,-1 }; // Borde superior mas cerca de p3
				else
					collVector = { -1,0 }; // Borde dcho mas cerca de p3
			}
			else if ((b = returnBlock(p2))) {
				collVector = { 0,-1 };
			}
			else if ((b = returnBlock(p1))) collVector = { -1,0 };
		}
		else if (ballVel.getX() < 0 && ballVel.getY() > 0) {
			if ((b = returnBlock(p2))) {
				if (((p2.getY() - b->getRect().y) <= (b->getRect().x + b->getRect().w - p2.getX()))) // || ballVel.getX() == 0)
					collVector = { 0,-1 }; // Borde superior mas cerca de p2
				else
					collVector = { 1,0 }; // Borde dcho mas cerca de p0
			}
			else if ((b = returnBlock(p3))) {
				collVector = { 0,-1 };
			}
			else if ((b = returnBlock(p0))) collVector = { 1,0 };
		}
	}
	

	if (b != nullptr && !b->getColisionado()) {
		b->setColisionado(b->collides(numBlocks));
		//--numBlocks;
		return true;
	}
	else return false;
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