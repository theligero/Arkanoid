#include "Vector2D.h"
#include <cmath>

Vector2D& Vector2D::normalizeVector()
{
	double mod = pow(x, 2) + pow(y, 2);
	mod = sqrt(mod);
	x = x / mod; y = y / mod;
	return Vector2D(x, y);
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

Vector2D& Vector2D::operator*(const int& other)
{
	x = other * x; y = other * y;
	return Vector2D(x, y);
}

double Vector2D::scalarProduct(const Vector2D& v1, const Vector2D& v2)
{
	double suma1, suma2;

	suma1 = v1.x * v2.x;
	suma2 = v1.y * v2.y;

	return suma1 + suma2;
}

Vector2D& Vector2D::scalarMultiplication(const double& scalar)
{
	x *= scalar; y *= scalar;
	return Vector2D(x, y);
}
