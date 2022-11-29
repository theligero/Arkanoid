#ifndef REWARD_H_
#define REWARD_H_

#include "MovingObject.h"
#include <vector>

class Reward : public MovingObject
{
protected:
	std::vector<Reward*> recompensas;
public:
	Reward(Vector2D pos, int w, int h, Texture* tex) :
		MovingObject(pos, w, h, tex, { 0, 1 }) {}
	virtual ~Reward() {}
};

class Reward_NextLvl : public Reward {
public:
	Reward_NextLvl(Vector2D pos, int w, int h, Texture* tex, int& level) :
		Reward(pos, w, h, tex) { level += 1; }
};

class Reward_OneUp : public Reward {
public:
	Reward_OneUp(Vector2D pos, int w, int h, Texture* tex, int& lives) :
		Reward(pos, w, h, tex) {
		lives += 1; this->recompensas.push_back(this);
	}
};

class Reward_Platform : public Reward {
public:
	Reward_Platform(Vector2D pos, int w, int h, Texture* tex, int& paddleWidth) :
		Reward(pos, w, h, tex) {
		int aux;
		if (rand() % 2 + 1 == 1) aux = 0.5;
		else aux = 1.5;
		width *= aux;
	}
};

#endif