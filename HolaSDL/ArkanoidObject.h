#ifndef ARKANOIDOBJECT_H_
#define	ARKANOIDOBJECT_H_

#include "GameObject.h"
#include "Vector2D.h"
#include "Texture.h"
#include "checkML.h"

class ArkanoidObject : public GameObject
{
public: 
	virtual void loadFromFile() {};
	virtual void saveToFile() {};
	virtual SDL_Rect getRect() const;
	virtual bool collides(SDL_Rect ball, Vector2D& normal) { return false; };
	virtual bool collides(SDL_Rect ball, Vector2D& normal, int& numBlocks) { return false; };
	ArkanoidObject() : pos(0, 0), width(0), height(0), tex(nullptr) {}
	ArkanoidObject(Vector2D pos, int w, int h, Texture* t) :
		pos(pos), width(w), height(h), tex(t) {}
protected:
	Vector2D pos; // posición
	double width; // ancho
	double height; // alto
	Texture* tex; // puntero a su textura
};

#endif