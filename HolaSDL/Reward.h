#ifndef REWARD_H_
#define REWARD_H_

#include "MovingObject.h"
#include <list>
#include <unordered_map>
#include "Paddle.h"

const int NUM_REWARDS = 4;

enum class TypeOfReward{ NEXT_LEVEL, ONE_UP, BIGGER_PLATFORM, SMALLER_PLATFORM };

typedef struct {
	TypeOfReward r;
	int row;
} RewardRow;

const RewardRow REW_ROW[NUM_REWARDS]{
	{TypeOfReward::NEXT_LEVEL, 0 },
	{TypeOfReward::ONE_UP, 4},
	{TypeOfReward::BIGGER_PLATFORM, 1},
	{TypeOfReward::SMALLER_PLATFORM, 3}
};

std::unordered_map<TypeOfReward, int> keyReward;

class Reward : public MovingObject
{
private:
	Game* game = nullptr;
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
	Reward(Vector2D pos, int w, int h, Texture* tex, std::list<ArkanoidObject*>* l, Game* juego) :
		MovingObject(pos, w, h, tex, { 0, 1 }), objectList(l), game(juego),
		rew(TypeOfReward(rand() % NUM_REWARDS)) { InitializeKeyReward(); LoadFile(); }
	// Destructora
	virtual ~Reward();
	// Inicialización de tipos enumerados en el mapa no ordenado
	void InitializeKeyReward();
	// Carga de archivo
	void LoadFile();
	// Colisión con el jugador
	bool Collides(SDL_Rect* paddle);
	// Ejecución de las distintas recompensas
	void StablishReward();
};

#endif