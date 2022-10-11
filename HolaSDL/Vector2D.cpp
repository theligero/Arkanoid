#include "Vector2D.h"
#include <cmath>

std::tuple<double> Vector2D::coor()
{
	double auxX = _x, auxY = _y;
	// return std::make_tuple(auxX, auxY);
}

Vector2D Vector2D::normalizeVector()
{
	int mod = (this->_x * this->_x) + (this->_y * this->_y);
	mod = sqrt(mod);
	return Vector2D(this->_x / mod, this->_y / mod);
}

Vector2D& Vector2D::operator+(const Vector2D& other)
{
	return Vector2D(this->_x + other._x, this->_y + other._y);
}

Vector2D& Vector2D::operator-(const Vector2D& other)
{
	return Vector2D(this->_x - other._x, this->_y - other._y);
}

Vector2D& Vector2D::operator*(const Vector2D& other)
{
	return Vector2D(this->_x * other._x, this->_y * other._y);
}

double Vector2D::scalarProduct(const Vector2D& v1, const Vector2D& v2)
{
	/*int mod1, mod2, sol;

	mod1 = (v1._x * v1._x) + (v1._y * v1._y);
	mod2 = (v2._x * v2._x) + (v2._y * v2._y);

	sol = mod1 * mod2 * cos(angle);*/

	int suma1, suma2, sol;

	suma1 = v1._x * v2._x;
	suma2 = v1._y * v2._y;
	sol = suma1 + suma2;

	return sol;
}

Vector2D& Vector2D::scalarMultiplication(const double scalar)
{
	return Vector2D(this->_x * scalar, this->_y * scalar);
}
