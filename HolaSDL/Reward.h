#ifndef REWARD_H_
#define REWARD_H_

#include "MovingObject.h"
#include <list>
#include "PlayState.h"
#include <unordered_map>
#include "Paddle.h"



// Número de recompensas implementadas
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

class PlayState;

class Reward : public MovingObject
{
private:
	// Puntero al juego
	PlayState* _scene = nullptr;
	// Iterador de la recompensa en la lista
	std::list<GameObject*>::iterator itScene;
	std::list<ArkanoidObject*>::iterator itRewards;
	// Tipo de recompensa
	rewardColors rew = rewardColors::R;

	bool colision = false;
public:
	// Constructora sin parámetros
	Reward() {}
	// Constructora con posición, puntero a textura, puntero a lista
	Reward(Vector2D pos, int w, int h, Texture* tex, PlayState* juego) :
		MovingObject(pos, w, h, tex, { 0, 1 }), _scene(juego),
		rew(rewardColors(rand() % 4 + 1)) {
	}
	// Destructora
	~Reward();
	//// Inicialización de tipos enumerados en el mapa no ordenado
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