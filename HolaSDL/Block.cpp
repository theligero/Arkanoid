#include "Block.h"

void Block::render() const
{
	SDL_Rect dest = getRect();

	if (!colisionado) {
		tex->renderFrame(dest, TYPE_BLOCK[color].row, TYPE_BLOCK[color].col);
	}
	else {
		tex->renderFrame(dest, -1, -1);
	}
	//tex->renderFrame(dest, TYPE_BLOCK[color].row, TYPE_BLOCK[color].col);

	
	//col = TYPE_BLOCK[numBlock].col; row = TYPE_BLOCK[numBlock].row; 
}

bool Block::collides(SDL_Rect ball, Vector2D& normal)
{
	SDL_Rect dest = getRect();

	if (!colisionado && SDL_HasIntersection(&dest, &ball) ) {
		if (ball.y <= dest.y)
			normal = Vector2D(0, -1);
		else if (ball.y >= dest.y)
			normal = Vector2D(0, 1);
		else {
			if (ball.x <= dest.x)
				normal = Vector2D(-1, 0);
			else if(ball.x >= dest.x)
				normal = Vector2D(1, 0);
		}
		colisionado = true;
	}

	return SDL_HasIntersection(&dest, &ball);
}

SDL_Rect Block::getRect() const
{
	SDL_Rect rect;

	rect.w = width; rect.h = height;
	rect.x = pos.getX(); rect.y = pos.getY();

	return rect;
}