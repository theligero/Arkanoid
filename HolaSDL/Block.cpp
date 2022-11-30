#include "Block.h"
#include "Game.h"
#include <iostream>

void Block::render() const //Renderizo el bloque.
{
	SDL_Rect dest = getRect(); //Establezco en una variable el SDL_Rect del bloque.

	if (!colisionado) { //En funci�n de si ha colisionado la bola o no, asigno la textura con color o sin �l.
		tex->renderFrame(dest, TYPE_BLOCK[color].row, TYPE_BLOCK[color].col);
	}
	else {
		tex->renderFrame(dest, -1, -1);
	}
	//tex->renderFrame(dest, TYPE_BLOCK[color].row, TYPE_BLOCK[color].col);

	
	//col = TYPE_BLOCK[numBlock].col; row = TYPE_BLOCK[numBlock].row; 
}

bool Block::collides(SDL_Rect ball, Vector2D& normal, int &numBlocks) //Chequeo la colisi�n de la bola con el bloque.
{
	SDL_Rect dest = getRect(); //Establezco en una variable el SDL_Rect del bloque.

	if (!colisionado && SDL_HasIntersection(&dest, &ball) ) { //Compruebo si el bloque ya ha sido colisionado y si hay intersecci�n entre el bloque y la bola.
		//Choca por arriba
		if (ball.y <= dest.y && ball.x >= dest.x && ball.x <= (dest.x + dest.w))
			normal = Vector2D(0, 1); //Asigno la normal correspondiente.
		//Choca por abajo
		else if (ball.y >= dest.y)
			normal = Vector2D(0, -1); //Asigno la normal correspondiente.
		else {
			//Choca por la derecha
			if (ball.x <= dest.x)
				normal = Vector2D(-1, 0); //Asigno la normal correspondiente.
			//Choca por la izquierda
			else if(ball.x >= dest.x)
				normal = Vector2D(1, 0); //Asigno la normal correspondiente.
		}
		if (numBlocks >= 0) {
			numBlocks--;
			std::cout << numBlocks << "\n";
		}
		colisionado = true; // Cambio la variable que indica si un bloque ya ha sido chocado por la bola.
		if ((rand() % 5) == 0) {
			game->createReward(pos, width, height, tex);
		}
	}

	return SDL_HasIntersection(&dest, &ball);
}