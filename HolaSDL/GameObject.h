#ifndef GAMEOBJECT_H_
#define	GAMEOBJECT_H_

class GameObject
{
public:
	// renderizado
	virtual void render() const{};
	// actualización
	virtual void update() {};
	// controlador de eventos
	virtual void handleEvents() {};
};

#endif