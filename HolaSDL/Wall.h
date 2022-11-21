#ifndef WALL_H_
#define WALL_H_
#include "ArkanoidObject.h"

class Wall : public ArkanoidObject
{
private:
	Vector2D _normal;
public:
	// constructor por defecto
	Wall() : _normal(0, 0) {}
	// constructor con su posici�n, ancho, alto y puntero a textua como par�metros
	Wall(Vector2D pos, int width, int height, Texture* tex, Vector2D normal) : ArkanoidObject(pos, width, height, tex), _normal(normal) {}
	// renderizado
	void render() const override;
	// colisi�n
	bool collides(SDL_Rect ball, Vector2D& normal) override;
};

#endif
