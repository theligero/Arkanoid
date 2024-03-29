#include "Reward.h"

Reward::~Reward()
{
	// Me busco en la lista gracias al iterador guardado
	_scene->getObjectList()->erase(itScene);
	// Me borro del todo
	_scene->getRewardsVector()->erase(itRewards);
}

void Reward::InitializeKeyReward()
{
	itScene = _scene->getObjectList()->end();
	--itScene;
	itRewards = _scene->getRewardsVector()->end();
	--itRewards;
}

void Reward::render() const
{
	SDL_Rect dest = getRect(); //Establezco en una variable el SDL_Rect del bloque.

	if (!colision) {
		tex->renderFrame(dest,  TYPE_REWARD[rew].row,TYPE_REWARD[rew].col, 1);
	}
	else {
		tex->renderFrame(dest, TYPE_REWARD[NINGUNO].row, TYPE_REWARD[NINGUNO].col, 1);
	}
}

bool Reward::collides(SDL_Rect paddle)
{
	// Si hay intersecci�n entre el jugador y la recompensa
	if (SDL_HasIntersection(&paddle, &getRect()) && !colision) {
		StablishReward(); // se activan las recompensas
		colision = true;
		return true; // y devuelvo verdadero
	}
	else return false; // devuelvo falso en caso contrario
}

void Reward::StablishReward()
{
	// Creo un condicional de tipo switch para evaluar
	// qu� recompensa tengo
	switch (rew) {
		case (rewardColors::L): // si soy NEXT_LEVEL
			_scene->nextLevel(); // cambio de nivel
			break;
		case (rewardColors::R): // si soy ONE_UP
			_scene->addOneUp(); // me sumo una vida
			break;
		case (rewardColors::E): // si soy BIGGER_PLATFORM
			// cambio mis dimensiones en un 50 % m�s
			_scene->getPaddlePointer()->changePlatWidth(1.5);
			break;
		case (rewardColors::S): // si soy SMALLER_PLATFORM
			// cambio mis dimensiones en un 50 % menos
			_scene->getPaddlePointer()->changePlatWidth(0.5);
			break;
		default:
			break;
	}
}

void Reward::update() 
{
	pos += dir;
}
