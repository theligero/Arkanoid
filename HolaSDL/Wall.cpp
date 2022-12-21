#include "Wall.h"

void Wall::render() const //Renderizo la pared.
{
	SDL_Rect dest = getRect(); //Establezco en una variable el SDL_Rect de la pared.

	tex->render(dest, SDL_FLIP_NONE);
}

bool Wall::collides(const SDL_Rect& ballRect, const Vector2D& ballVel, Vector2D& collVector)
{
	SDL_Rect dest = getRect(); //Establezco en una variable el SDL_Rect de la pared.

	//Si hay interección entre pared y bola, la normal afecta a la bola y rebota.

	collVector = _normal;

	return SDL_HasIntersection(&dest, &ballRect);
}

void Wall::saveToFile(ofstream& input)
{
	input << pos.getX() << " " << pos.getY() << " " << width << " " << height << " " << _normal.getX() << " " << _normal.getY() << "\n";
}

void Wall::loadFromFile(fstream& input)
{
	double posX, posY, normalX, normalY;
	input >> posX >> posY >> width >> height >> normalX >> normalY;
	pos = Vector2D(posX, posY);
	_normal = Vector2D(normalX, normalY);
}