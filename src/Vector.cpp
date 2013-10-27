
#include "Vector.h"

using namespace G3D;

Vector::Vector(): coords(0,0,0) {}

Vector::Vector(double x, double y, double z): coords(x,y,z) {}

Vector &Vector::operator+(const Vector &rhs)
{
	get<0>(coords) += get<0>(rhs.coords);
	get<1>(coords) += get<1>(rhs.coords);
	get<2>(coords) += get<2>(rhs.coords);
	return *this;
}

Vector &Vector::operator-(const Vector &rhs)
{
	get<0>(coords) -= get<0>(rhs.coords);
	get<1>(coords) -= get<1>(rhs.coords);
	get<2>(coords) -= get<2>(rhs.coords);
	return *this;
}

