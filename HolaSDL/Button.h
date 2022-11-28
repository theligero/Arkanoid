#pragma once
#include "ArkanoidObject.h"

class Button : public ArkanoidObject
{
public:
	Button(){}
	// constructor con su posici�n, ancho, alto y puntero a textua como par�metros
	Button(Vector2D pos, int width, int height, Texture* tex) : ArkanoidObject(pos, width, height, tex){}
	// renderizado
	void render() const override;
	bool inBounds(Vector2D coordRaton);
};

