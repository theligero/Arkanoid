#include "Block.h"
#include "PlayState.h"
#include <iostream>

void Block::render() const //Renderizo el bloque.
{
	SDL_Rect dest = getRect(); //Establezco en una variable el SDL_Rect del bloque.

	if (!colisionado) { //En función de si ha colisionado la bola o no, asigno la textura con color o sin él.
		tex->renderFrame(dest, TYPE_BLOCK[color].row, TYPE_BLOCK[color].col);
	}
	else {
		tex->renderFrame(dest, -1, -1);
	}
}

bool Block::collides(int &numBlocks) //Chequeo la colisión de la bola con el bloque.
{
	SDL_Rect dest = getRect(); //Establezco en una variable el SDL_Rect del bloque.

	if (numBlocks >= 0) {
		numBlocks--;
		std::cout << numBlocks << "\n";
	}

	//colisionado = true; // Cambio la variable que indica si un bloque ya ha sido chocado por la bola.
	if ((rand() % 1) == 0) {
		game->createReward(Vector2D{ pos.getX() + width / 2, pos.getY() + height / 2 }, 20, 13, game->getRewardTexture());
	}

	int puntos = this->color * game->getLives() * 10;
	game->addPoints(puntos);
	return true; 
}