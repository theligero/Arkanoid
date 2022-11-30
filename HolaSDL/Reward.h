#ifndef REWARD_H_
#define REWARD_H_

#include "MovingObject.h"
#include <list>
#include <unordered_map>
#include "Paddle.h"

// N�mero de recompensas implementadas
const int NUM_REWARDS = 4;

enum rewardColors { NINGUNO, L, E, S, R };

// Estructura de almacenamiento de las recompensas con la fila que
// le corresponde en el sprite


typedef struct {
	int col,
		row;
} TipoReward;

// Array de lo anterior con los datos correspondientes


const TipoReward TYPE_REWARD[5]{
	{-1, -1},
	{0, 0}, {0, 1}, {0, 3}, {0, 4}
};

class Reward : public MovingObject
{
private:
	// Puntero al juego
	Game* game = nullptr;
	// Iterador de la recompensa en la lista
	std::list<ArkanoidObject*>::iterator it;
	// Tipo de recompensa
	rewardColors rew = rewardColors::R;
public:
	// Constructora sin par�metros
	Reward() {}
	// Constructora con posici�n, puntero a textura, puntero a lista
	Reward(Vector2D pos, int w, int h, Texture* tex, Game* juego) :
		MovingObject(pos, w, h, tex, { 0, 1 }), game(juego),
		rew(rewardColors(rand() % 4 + 1)) { /*InitializeKeyReward(); LoadFile();*/ }
	// Destructora
	virtual ~Reward();
	//// Inicializaci�n de tipos enumerados en el mapa no ordenado
	//void InitializeKeyReward();
	// Carga de archivo
	void render() const override;
	// Colisi�n con el jugador
	bool collides(SDL_Rect paddle)override;
	// Ejecuci�n de las distintas recompensas
	void StablishReward();
	
	void update() override;
};

#endif