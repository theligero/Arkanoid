#ifndef VECTOR2D_H_
#define VECTOR2D_H_

#include <tuple>

class Vector2D
{
private:
	double _x;
	double _y;
public:
	Vector2D() : _x(0), _y(0) {}
	Vector2D(double x, double y) : _x(x), _y(y) {}

	double getX() const { return _x; };
	double getY() const{ return _y; };

	std::tuple<double> coor();
	Vector2D normalizeVector();

	Vector2D& operator+(const Vector2D& other);
	Vector2D& operator-(const Vector2D& other);
	Vector2D& operator*(const Vector2D& other);
	
	double scalarProduct(const Vector2D& v1, const Vector2D& v2);
	Vector2D& scalarMultiplication(const double scalar);
};

#endif /* VECTOR2D_H_ */