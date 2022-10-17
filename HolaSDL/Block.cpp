#include "Block.h"

Block::Block(Vector2D newPos, double w, double h, int c, Texture* t)
{
	pos = newPos; width = w; height = h; 
	color = c; tex = t;
	if (c > 2) {
		col = c - 3;
		row = 1;
	}
	else {
		col = c;
		row = 0;
	}
}

void Block::render() const
{
	SDL_Rect dest;

	dest.w = width; dest.h = height;
	dest.x = pos.getX(); dest.y = pos.getY();

	tex->renderFrame(dest, row, col);
}
