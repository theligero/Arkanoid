#ifndef BLOCK_H_
#define BLOCK_H_

#include "Vector2D.h"
#include "Texture.h"

// tipo enumerado con los posibles colores
enum colors { NONE, BLUE, GREEN, RED, YELLOW, BLACK, PURPLE };

// estructura simple (tupla) de columnas y filas
typedef struct {
	int col,
		row;
} TypeOfBlock;

// array de TypeOfBlock con la fila y columna de la spritesheet 
// que le corresponde a cada número del fichero
const TypeOfBlock TYPE_BLOCK[7]{
	{-1, -1},
	{0, 0}, {1, 0}, {2, 0},
	{1, 0}, {1, 1}, {1, 2}
};

class Block
{
private:
	Vector2D pos; // posición
	double width; // ancho
	double height; // alto
	int color; // color
	int col; // columna
	int row; // fila
	Texture* tex; // puntero a su textura
public:
	// constructor por defecto
	Block() : pos(0, 0), width(0), height(0), color(0), col(0), row(0), tex(nullptr) {}
	// constructor con su posición, ancho, alto, número del bloque y puntero a textura
	Block(Vector2D newPos, double w, double h, int numBlock, Texture* t) :
		pos(newPos), color(numBlock), tex(t), width(w), height(h)
	{ col = TYPE_BLOCK[numBlock].col; row = TYPE_BLOCK[numBlock].row; }
	// renderizado
	void render() const;
};

#endif /* BLOCK_H_ */