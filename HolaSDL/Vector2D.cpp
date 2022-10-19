#include "Vector2D.h"

//std::tuple<double> Vector2D::coor()
//{
//	double auxX = _x, auxY = _y;
//	// return std::make_tuple(auxX, auxY);
//}

Vector2D Vector2D::normalizeVector()
{
	int mod = (this->x * this->x) + (this->y * this->y);
	mod = sqrt(mod);
	return Vector2D(this->x / mod, this->y / mod);
}

Vector2D& Vector2D::operator+(const Vector2D& other)
{
	return Vector2D(this->x + other.x, this->y + other.y);
}

Vector2D& Vector2D::operator-(const Vector2D& other)
{
	return Vector2D(this->x - other.x, this->y - other.y);
}

Vector2D& Vector2D::operator*(const Vector2D& other)
{
	return Vector2D(this->x * other.x, this->y * other.y);
}

Vector2D& Vector2D::operator+=(const Vector2D& other)
{
	return Vector2D(this->x += other.x, this->y += other.y);
}

double Vector2D::scalarProduct(const Vector2D& v1, const Vector2D& v2)
{
	/*int mod1, mod2, sol;

	mod1 = (v1._x * v1._x) + (v1._y * v1._y);
	mod2 = (v2._x * v2._x) + (v2._y * v2._y);

	sol = mod1 * mod2 * cos(angle);*/

	int suma1, suma2, sol;

	suma1 = v1.x * v2.x;
	suma2 = v1.y * v2.y;
	sol = suma1 + suma2;

	return sol;
}

Vector2D& Vector2D::scalarMultiplication(const double scalar)
{
	return Vector2D(this->x * scalar, this->y * scalar);
}
