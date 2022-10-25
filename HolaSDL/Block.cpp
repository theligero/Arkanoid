#include "Block.h"

void Block::render() const
{
	SDL_Rect dest;

	dest.w = width; dest.h = height;
	dest.x = pos.getX(); dest.y = pos.getY();

	tex->renderFrame(dest, row, col);
}

bool Block::collides(SDL_Rect ball, Vector2D& normal) const
{
	SDL_Rect dest;

	dest.w = width; dest.h = height;
	dest.x = pos.getX(); dest.y = pos.getY();

	if (SDL_HasIntersection(&dest, &ball)) {
		if (ball.y < dest.y)
			normal = Vector2D(0, 1);
		else if (ball.y > (dest.y + height))
			normal = Vector2D(0, -1);
		else {
			if (ball.x > dest.x)
				normal = Vector2D(-1, 0);
			else
				normal = Vector2D(1, 0);
		}
		tex->renderFrame(dest, -1, -1);
	}

	return SDL_HasIntersection(&dest, &ball);
}
