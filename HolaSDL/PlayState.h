#ifndef PLAYSTATE_H_
#define PLAYSTATE_H_

#include "GameState.h"

class PlayState : public GameState
{
public:
	virtual void update();
	virtual void render();
	virtual void handleEvent();

	virtual bool onEnter();
	virtual bool onExit();

	// Observa que ahora la clase Game quedaría solo con los siguientes atributos básicos : los punteros a
	// SDL Window y SDL Renderer, el booleano de final de la aplicación, el array de texturas y la máquina de
	// estados. De hecho, esta clase podría pasar a llamarse SDLApplication pues ya no tiene nada referente
	// al juego propiamente dicho.
};

#endif /*PLAYSTATE_H_*/