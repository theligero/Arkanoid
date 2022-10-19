#ifndef BLOCK_H_
#define BLOCK_H_

#include "Vector2D.h"
#include "Texture.h"

enum colors { NONE, BLUE, GREEN, RED, YELLOW, BLACK, PURPLE };

typedef struct {
	int col,
		row;
} TypeOfBlock;

const TypeOfBlock TYPE_BLOCK[7]{
	{-1, -1},
	{0, 0}, {1, 0}, {2, 0},
	{1, 0}, {1, 1}, {1, 2}
};

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
	Block(Vector2D newPos, double w, double h, int numBlock, Texture* t) :
		pos(newPos), color(numBlock), tex(t), width(w), height(h)
	{ col = TYPE_BLOCK[numBlock].col; row = TYPE_BLOCK[numBlock].row; }
	void render() const;
};

#endif /* BLOCK_H_ */