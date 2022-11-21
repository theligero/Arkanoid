#ifndef MOVINGOBJECT_H_
#define	MOVINGOBJECT_H_

#include "ArkanoidObject.h"

class MovingObject : public ArkanoidObject
{
protected:
	Vector2D dir; // vector dirección
public:
	MovingObject() : dir({ 0,0 }) {}
	MovingObject(Vector2D pos, int w, int h, Texture* t, Vector2D _dir) :
		ArkanoidObject(pos, w, h, t), dir(_dir) {}
};

#endif