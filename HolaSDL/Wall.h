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
	// constructor con su posición, ancho, alto y puntero a textua como parámetros
	Wall(fstream &input, Texture* _tex) : 
		ArkanoidObject(_tex), _normal(0, 0) { loadFromFile(input); }

	Wall(Vector2D pos, int width, int height, Texture* tex, Vector2D normal) :
		ArkanoidObject(pos, width, height, tex), _normal(normal) {}
	// renderizado
	void render() const override;
	// colisión
	bool collides(SDL_Rect ball, Vector2D& normal) override;

	void saveToFile(ofstream& input) override;

	void loadFromFile(fstream& input) override;
};

#endif
