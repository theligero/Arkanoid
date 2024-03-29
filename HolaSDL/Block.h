#ifndef BLOCK_H_
#define BLOCK_H_

#include "ArkanoidObject.h"

class PlayState;

// tipo enumerado con los posibles colores
enum colors { NONE, BLUE, GREEN, RED, YELLOW, BLACK, PURPLE };

// estructura simple (tupla) de columnas y filas
typedef struct {
	int col,
		row;
} TypeOfBlock;

// array de TypeOfBlock con la fila y columna de la spritesheet 
// que le corresponde a cada n�mero del fichero
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
	PlayState* game = nullptr;
public:
	// constructor por defecto
	Block() : color(0), col(0), row(0), colisionado(false), game(nullptr) {}
	// constructor con su posici�n, ancho, alto, n�mero del bloque y puntero a textura
	Block(Vector2D newPos, double w, double h, int numBlock, int column, int rows, Texture* t, PlayState* _game) :
	  ArkanoidObject(newPos, w, h, t), color(numBlock), col(column), row(rows), colisionado(false), game(_game) { }
	// renderizado
	void render() const ;
	// colisi�n
	bool collides(int& numBlocks) override;
	void setColisionado(const bool& col) { colisionado = col; }
	bool getColisionado() { return colisionado; };
	int getColor() { return color; };
};

#endif /* BLOCK_H_ */