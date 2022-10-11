#include "Block.h"

void Block::render() const
{
	SDL_Rect dest;

	dest.w = width; dest.h = height;
	dest.x = pos.getX(); dest.y = pos.getY();

	tex->renderFrame(dest, row, col);
}
