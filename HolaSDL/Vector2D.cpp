#include "Vector2D.h"
#include <cmath>

std::tuple<double> Vector2D::coor()
{
	double auxX = this->x, auxY = this->y;
	// return std::make_tuple(auxX, auxY);
}

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

double Vector2D::scalarProduct(const Vector2D& v1, const Vector2D& v2, double angle)
{
	int mod1, mod2, sol;

	mod1 = (v1.x * v1.x) + (v1.y * v1.y);
	mod2 = (v2.x * v2.x) + (v2.y * v2.y);

	sol = mod1 * mod2 * cos(angle);
	return sol;
}

Vector2D& Vector2D::scalarMultiplication(const double scalar)
{
	return Vector2D(this->x * scalar, this->y * scalar);
}
