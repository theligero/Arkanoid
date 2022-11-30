#include "Reward.h"

Reward::~Reward()
{
	objectList->erase(it);
	delete(this);
}

void Reward::LoadFile(Texture* t)
{
	height = t->getH(); width = t->getW();
	columns = t->getNumCols(); rows = t->getNumRows();
}

void Reward::Collides(Paddle* p)
{
	SDL_Rect rect = getRect();
}

void Reward::StablishReward()
{
	SDL_Rect aux;

	if (rew == TypeOfReward::NEXT_LEVEL) {
		// game->currentLevel += 1;
		// tex->renderFrame(aux, )
	}
	else if (rew == TypeOfReward::ONE_UP) {
		// game->lives += 1;
	}
	else {

	}
}
