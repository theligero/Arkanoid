#ifndef PLAYSTATE_H_
#define PLAYSTATE_H_

#include "GameState.h"
#include "PauseState.h"
#include "BlocksMap.h"
#include "Wall.h"
#include "Ball.h"
#include "Paddle.h"
#include "Reward.h"

class PlayState : public GameState
{
public:
	PlayState(Game* g);
	PlayState(Game* g, fstream& input);
	virtual void update();
	virtual void render();
	virtual void handleEvent();

	// colisión de objetos
	bool collides(const SDL_Rect& ballRect, const Vector2D& ballVel, Vector2D& collVector, CollisionType colision);

	virtual bool onEnter();
	virtual bool onExit();

	void resetBlockMap();

	int getLives() const { return lives; }

	void createReward(Vector2D _pos, int _w, int _h, Texture* _tex);

	void addOneUp();
	// Cambio al siguiente nivel
	void nextLevel();
	// Añadido de puntos
	void addPoints(const int& puntos);

	Paddle* getPaddlePointer();

	Texture* getRewardTexture() { return game->getArrayTex(REWARD); }

	list<ArkanoidObject*>* getRewardsVector() { return &rewardsVector;}

	void advanceLevel();

	void enterPause();

	void save();

	void setSave();

	// Observa que ahora la clase Game quedaría solo con los siguientes atributos básicos : los punteros a
	// SDL Window y SDL Renderer, el booleano de final de la aplicación, el array de texturas y la máquina de
	// estados. De hecho, esta clase podría pasar a llamarse SDLApplication pues ya no tiene nada referente
	// al juego propiamente dicho.
private:
	SDL_Window* window;

	BlocksMap* blocksMap = nullptr; // puntero del mapa de bloques
	Wall* walls[3]; // puntero a paredes
	Ball* ball = nullptr; // puntero a la pelota
	Paddle* player = nullptr; // puntero al jugador/pala

	list<ArkanoidObject*> rewardsVector;

	int lives = 3;
	int currentLevel = 1;
	int numRewards = 0;
	int points = 0;

	bool finJuego = false;
};

#endif /*PLAYSTATE_H_*/