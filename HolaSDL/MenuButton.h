#ifndef MENUBUTTON_H_
#define MENUBUTTON_H_

#include "GameObject.h"
#include "Texture.h"

enum button_state {
	MOUSE_OUT = 0,
	MOUSE_OVER = 1,
	CLICKED = 2
};

class MenuButton : public GameObject
{
private:
	button_state current_buttonState;
	Texture* tex;
public:
	MenuButton();

	virtual void draw();
	virtual void update();
	virtual void clean();
	// typedef void CallBack(Game* game);
};

#endif /*MENUBUTTON_H_*/