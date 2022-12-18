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

	// Observa que ahora la clase Game quedar�a solo con los siguientes atributos b�sicos : los punteros a
	// SDL Window y SDL Renderer, el booleano de final de la aplicaci�n, el array de texturas y la m�quina de
	// estados. De hecho, esta clase podr�a pasar a llamarse SDLApplication pues ya no tiene nada referente
	// al juego propiamente dicho.
};

#endif /*PLAYSTATE_H_*/