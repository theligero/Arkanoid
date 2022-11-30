#include "Reward.h"

Reward::~Reward()
{
	objectList->erase(it);
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
	if (SDL_HasIntersection(paddle, &getRect())) {
		StablishReward();
		return true;
	}
	else return false;
}

void Reward::StablishReward()
{
	switch (rew) {
		case (TypeOfReward::NEXT_LEVEL):
			game->nextLevel();
			break;
		case (TypeOfReward::ONE_UP):
			game->addOneUp();
			break;
		case (TypeOfReward::BIGGER_PLATFORM):
			game->getPaddlePointer()->changePlatWidth(1.5);
			break;
		case (TypeOfReward::SMALLER_PLATFORM):
			game->getPaddlePointer()->changePlatWidth(0.5);
			break;
		default:
			break;
	}
}
