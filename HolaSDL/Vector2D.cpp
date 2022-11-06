#include "Vector2D.h"

Vector2D& Vector2D::normalizeVector()
{
	double mod = pow(x, 2) + pow(y, 2); // potencia de cuadrados
	mod = sqrt(mod); // raíz del resultado
	x = x / mod; y = y / mod; // lo asigno
	return Vector2D(x, y); // y lo devuelvo
}

Vector2D& Vector2D::operator+(const Vector2D& other)
{
	double aux_x, aux_y;
	aux_x = x + other.x; aux_y = y + other.y; // lo asigno
	return Vector2D(aux_x, aux_y); // y lo devuelvo
}

Vector2D& Vector2D::operator-(const Vector2D& other)
{
	double aux_x, aux_y;
	aux_x = x - other.x; aux_y = y - other.y;
	return Vector2D(aux_x, aux_y); // y lo devuelvo
}

Vector2D& Vector2D::operator*(const Vector2D& other)
{
	x *= other.x; y *= other.y; // lo asigno
	return Vector2D(x, y); // y lo devuelvo
}

Vector2D& Vector2D::operator+=(const Vector2D& other)
{
	x += other.x; y += other.y; // lo asigno
	return Vector2D(x, y); // y lo devuelvo
}

Vector2D& Vector2D::operator*(const int& other)
{
	x = other * x; y = other * y; // lo asigno
	return Vector2D(x, y); // y lo devuelvo
}

double Vector2D::scalarProduct(const Vector2D& v1, const Vector2D& v2)
{
	double suma1, suma2; // creo dos variables de tipo double

	// multiplico la x de uno con la x del otro y almaceno el resultado
	suma1 = v1.x * v2.x; 
	// multiplico la y de uno con la y del otro y almaceno el resultado
	suma2 = v1.y * v2.y;

	return suma1 + suma2; // devuelvo la suma de ambos resultados
}

Vector2D& Vector2D::scalarMultiplication(const double& scalar)
{
	x *= scalar; y *= scalar; // lo asigno
	return Vector2D(x, y); // y lo devuelvo
}
