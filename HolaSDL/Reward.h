#ifndef REWARD_H_
#define REWARD_H_

#include "MovingObject.h"
#include <list>
#include "Paddle.h"

enum class TypeOfReward{ NEXT_LEVEL, ONE_UP, PLATFORM_SIZE };

class Reward : public MovingObject
{
private:
	// Número de filas
	int rows = 0;
	// Número de columnas
	int columns = 0;
	// Puntero a la lista de punteros a objetos
	std::list<ArkanoidObject*>* objectList = nullptr;
	// Iterador de la recompensa en la lista
	std::list<ArkanoidObject*>::iterator it;
	// Tipo de recompensa
	TypeOfReward rew = TypeOfReward::ONE_UP;
public:
	// Constructora sin parámetros
	Reward() {}
	// Constructora con posición, puntero a textura, puntero a lista
	Reward(Vector2D pos, Texture* tex, std::list<ArkanoidObject*>* l) :
		MovingObject(pos, 0, 0, tex, { 0, 1 }), objectList(l), 
		rew(TypeOfReward(rand() % 2)) 
		{ LoadFile(tex); StablishReward(); }
	// Destructora
	virtual ~Reward();
	// Carga de archivo
	void LoadFile(Texture* t);
	void Collides(Paddle* p);
	void StablishReward();
};

//class Reward_NextLvl : public Reward {
//public:
//	Reward_NextLvl(Vector2D pos, int w, int h, Texture* tex, int& level) :
//		Reward(pos, w, h, tex) { level += 1; }
//};
//
//class Reward_OneUp : public Reward {
//public:
//	Reward_OneUp(Vector2D pos, int w, int h, Texture* tex, int& lives) :
//		Reward(pos, w, h, tex) {
//		lives += 1;
//	}
//};
//
//class Reward_Platform : public Reward {
//public:
//	Reward_Platform(Vector2D pos, int w, int h, Texture* tex, int& paddleWidth) :
//		Reward(pos, w, h, tex) {
//		int aux;
//		if (rand() % 2 + 1 == 1) aux = 0.5;
//		else aux = 1.5;
//		width *= aux;
//	}
//};

#endif