#ifndef ARKANOIDOBJECT_H_
#define	ARKANOIDOBJECT_H_

#include "GameObject.h"
#include "Vector2D.h"
#include "Texture.h"

class ArkanoidObject : public GameObject
{
public: 
	virtual void loadFromFile() {};
	virtual void saveToFile() {};
	virtual void getRect() {};

protected:
	Vector2D pos; // posición
	Vector2D dir; // vector dirección
	double width; // ancho
	double height; // alto
	Texture* tex; // puntero a su textura

private:
	ArkanoidObject() : pos(0, 0), dir(0, 0), width(0), height(0), tex(nullptr) {}
	ArkanoidObject(Vector2D pos, Vector2D d = new Vector2D(0,1), int w, int h, Texture* t) :
		pos(pos), dir(d), tex(t), width(w), height(h) {}
};

#endif