#ifndef GAMEOBJECT_H_
#define	GAMEOBJECT_H_

class GameObject
{
public:
	// renderizado
	virtual void render() {};
	// actualización
	virtual void update() {};
	// controlador de eventos
	virtual void handleEvents() {};

private:

};

#endif