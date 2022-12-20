#ifndef MENUBUTTON_H_
#define MENUBUTTON_H_

#include "ArkanoidObject.h"
#include "Texture.h"
#include "Game.h"

enum button_state {
	MOUSE_OUT = 0,
	MOUSE_OVER = 1,
	CLICKED = 2
};

class MenuButton : public ArkanoidObject
{
private:
	button_state current_buttonState;
	Texture* tex;
public:
	MenuButton(Vector2D p, int w, int h, Texture* t);

	// renderizado
	virtual void render() const;
	// actualización
	virtual void update();
	// controlador de eventos
	virtual void handleEvent();
	typedef void CallBack(Game* game);
};

#endif /*MENUBUTTON_H_*/