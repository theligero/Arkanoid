#include "Reward.h"

Reward::Reward(Vector2D pos, int w, int h, Texture* tex, TypeOfReward rew, int& aux)
{
	this->pos = pos; this->width = w;
	this->height = h; this->tex = tex;
	reward = rew;

	if (reward == TypeOfReward::ONE_UP)
		OneUp(aux);
	else if (reward == TypeOfReward::CHANGE_PLATFORM)
		ChangePlatformSize(aux);
}

void Reward::NextLevel()
{

}

void Reward::OneUp(int& lives)
{

}

void Reward::ChangePlatformSize(int& width)
{

}
