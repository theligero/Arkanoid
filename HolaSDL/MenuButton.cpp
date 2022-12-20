#include "MenuButton.h"

MenuButton::MenuButton(Vector2D p, int w, int h, Texture* t)
{
	pos = p; width = w;
	height = h; tex = t;
	current_buttonState = MOUSE_OUT;
}

void MenuButton::render() const
{
	tex->renderFrame(getRect(), 0, current_buttonState);
}

void MenuButton::update()
{
	int x, y;
	SDL_GetMouseState(&x, &y);
	Vector2D* mousePos = new Vector2D(x, y);

	if (mousePos->getX() < (pos.getX() + width)
		&& mousePos->getX() > pos.getX()
		&& mousePos->getY() < (pos.getY() + height)
		&& mousePos->getY() > pos.getY())
	{
		current_buttonState = MOUSE_OVER;
	}
	else
	{
		current_buttonState = MOUSE_OUT;
	}
}

void MenuButton::handleEvent()
{
	SDL_Event ev;

	while (SDL_PollEvent(&ev)) {
		if (current_buttonState == MOUSE_OVER && ev.button.button == SDL_BUTTON_LEFT) {
			current_buttonState = CLICKED;
		}
	}
}
