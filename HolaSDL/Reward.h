#ifndef REWARD_H_
#define REWARD_H_

#include "MovingObject.h"
#include <list>
#include <unordered_map>
#include "Paddle.h"

// Número de recompensas implementadas
const int NUM_REWARDS = 4;

// Tipo enumerado con todos los tipos de recompensas
enum class TypeOfReward{ NEXT_LEVEL, ONE_UP, BIGGER_PLATFORM, SMALLER_PLATFORM };

// Estructura de almacenamiento de las recompensas con la fila que
// le corresponde en el sprite
typedef struct {
	TypeOfReward r;
	int row;
} RewardRow;

// Array de lo anterior con los datos correspondientes
const RewardRow REW_ROW[NUM_REWARDS]{
	{TypeOfReward::NEXT_LEVEL, 0 },
	{TypeOfReward::ONE_UP, 4},
	{TypeOfReward::BIGGER_PLATFORM, 1},
	{TypeOfReward::SMALLER_PLATFORM, 3}
};

// Mapa no ordenado de recompensas y enteros (fila en el sprite)
std::unordered_map<TypeOfReward, int> keyReward;

class Reward : public MovingObject
{
private:
	// Puntero al juego
	Game* game = nullptr;
	// Iterador de la recompensa en la lista
	std::list<ArkanoidObject*>::iterator it;
	// Tipo de recompensa
	TypeOfReward rew = TypeOfReward::ONE_UP;
public:
	// Constructora sin parámetros
	Reward() {}
	// Constructora con posición, puntero a textura, puntero a lista
	Reward(Vector2D pos, int w, int h, Texture* tex, Game* juego) :
		MovingObject(pos, w, h, tex, { 0, 1 }), game(juego),
		rew(TypeOfReward(rand() % NUM_REWARDS)) { InitializeKeyReward(); /*LoadFile();*/ }
	// Destructora
	virtual ~Reward();
	// Inicialización de tipos enumerados en el mapa no ordenado
	void InitializeKeyReward();
	// Carga de archivo
	void render() const override;
	// Colisión con el jugador
	bool collides(SDL_Rect paddle)override;
	// Ejecución de las distintas recompensas
	void StablishReward();
	
	void update() override;
};

#endif