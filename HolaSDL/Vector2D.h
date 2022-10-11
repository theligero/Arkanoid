#ifndef VECTOR2D_H_
#define VECTOR2D_H_

#include <tuple>

class Vector2D
{
private:
	double x;
	double y;
public:
	Vector2D() : x(0), y(0) {}
	Vector2D(double x, double y) : x(x), y(y) {}

	std::tuple<double> coor();
	Vector2D normalizeVector();

	Vector2D& operator+(const Vector2D& other);
	Vector2D& operator-(const Vector2D& other);
	Vector2D& operator*(const Vector2D& other);
	
	double scalarProduct(const Vector2D& v1, const Vector2D& v2, const double angle);
	Vector2D& scalarMultiplication(const double scalar);
};

#endif /* VECTOR2D_H_ */