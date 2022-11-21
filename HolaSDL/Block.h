#ifndef BLOCK_H_
#define BLOCK_H_

#include "ArkanoidObject.h"

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
	{0, 1}, {1, 1}, {2, 1}
};

class Block : public ArkanoidObject
{
private:
	int color; // color
	int col; // columna
	int row; // fila
	bool colisionado;
public:
	// constructor por defecto
	Block() : color(0), col(0), row(0), colisionado(false) {}
	// constructor con su posición, ancho, alto, número del bloque y puntero a textura
	Block(Vector2D newPos, double w, double h, int numBlock, int column, int rows, Texture* t) :
	  ArkanoidObject(newPos, w, h, t), color(numBlock), col(column), row(rows), colisionado(false) { }
	// renderizado
	void render() const ;
	// colisión
	bool collides(SDL_Rect ball, Vector2D& normal, int& numBlocks) override;
	bool getColisionado() { return colisionado; };
};

#endif /* BLOCK_H_ */