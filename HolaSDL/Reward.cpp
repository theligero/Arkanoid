#include "Reward.h"

Reward::~Reward()
{
	// Me busco en la lista gracias al iterador guardado
	objectList->erase(it);
	// Me borro del todo
	delete(this);
}

void Reward::InitializeKeyReward()
{
	// Inserto en el mapa no ordenado las posiciones que le corresponden
	// a cada tipo de recompensa
	for (int i = 0; i < NUM_REWARDS; ++i) {
		keyReward.insert({ REW_ROW[i].r, REW_ROW[i].row });
	}
}

void Reward::LoadFile()
{
	height = tex->getH(); width = tex->getW();
	tex->renderFrame(getRect(), keyReward[rew], 1);
}

bool Reward::Collides(SDL_Rect* paddle)
{
	// Si hay intersección entre el jugador y la recompensa
	if (SDL_HasIntersection(paddle, &getRect())) {
		StablishReward(); // se activan las recompensas
		return true; // y devuelvo verdadero
	}
	else return false; // devuelvo falso en caso contrario
}

void Reward::StablishReward()
{
	// Creo un condicional de tipo switch para evaluar
	// qué recompensa tengo
	switch (rew) {
		case (TypeOfReward::NEXT_LEVEL): // si soy NEXT_LEVEL
			game->nextLevel(); // cambio de nivel
			break;
		case (TypeOfReward::ONE_UP): // si soy ONE_UP
			game->addOneUp(); // me sumo una vida
			break;
		case (TypeOfReward::BIGGER_PLATFORM): // si soy BIGGER_PLATFORM
			// cambio mis dimensiones en un 50 % más
			game->getPaddlePointer()->changePlatWidth(1.5);
			break;
		case (TypeOfReward::SMALLER_PLATFORM): // si soy SMALLER_PLATFORM
			// cambio mis dimensiones en un 50 % menos
			game->getPaddlePointer()->changePlatWidth(0.5);
			break;
		default:
			break;
	}
}
