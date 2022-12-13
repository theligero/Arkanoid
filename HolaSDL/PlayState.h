#include "GameState.h"
#include "Texture.h"
#include "BlocksMap.h"
#include "Wall.h"
#include "Ball.h"
#include "Paddle.h"
#include "Button.h"
#include "Reward.h"
#include "ArkanoidObject.h"

class PlayState : public GameState
{
private:
	std::list<ArkanoidObject*> scene;
public:
	// Observa que ahora la clase Game quedar�a solo con los siguientes atributos b�sicos : los punteros a
	// SDL Window y SDL Renderer, el booleano de final de la aplicaci�n, el array de texturas y la m�quina de
	// estados. De hecho, esta clase podr�a pasar a llamarse SDLApplication pues ya no tiene nada referente
	// al juego propiamente dicho.
};

