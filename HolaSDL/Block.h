#ifndef BLOCK_H_
#define BLOCK_H_

#include "Vector2D.h"
#include "Texture.h"

enum colors { BLUE, GREEN, RED, YELLOW, BLACK, PURPLE };

class Block
{
private:
	Vector2D pos;
	double width;
	double height;
	int color; 
	int col; 
	int row;
	Texture* tex;
public:
	Block() : pos(0, 0), width(0), height(0), color(0), col(0), row(0), tex(nullptr) {}
	Block(Vector2D newPos, double w, double h, int c, int _col, int _row, Texture* t) : 
		pos(newPos), width(w), height(h), color(c), col(_col), row(_row), tex(t) {}

	void render() const;
};

#endif /* BLOCK_H_ */