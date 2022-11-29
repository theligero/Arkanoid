#ifndef REWARD_H_
#define REWARD_H_

#include "MovingObject.h"

enum class TypeOfReward { NEXT_LEVEL, ONE_UP, CHANGE_PLATFORM };

class Reward : public MovingObject
{
private:
	TypeOfReward reward;
public:
	Reward(Vector2D pos, int w, int h, Texture* tex, TypeOfReward rew) :
		MovingObject(pos, w, h, tex, { 0, 1 }), reward(rew) {
		NextLevel();
	}
	Reward(Vector2D pos, int w, int h, Texture* tex, TypeOfReward rew, int& aux);
	~Reward() {}
	void NextLevel();
	void OneUp(int& lives);
	void ChangePlatformSize(int& width);
};

#endif