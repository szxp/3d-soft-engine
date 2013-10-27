
#include "Point.h"
#include <iostream>

using namespace std;
using namespace G3D;

Point::Point(): coords(0,0,0) {}

Point::Point(double x, double y, double z): coords(x,y,z) {}

Point &Point::operator+(const Vector& rhs) 
{
	get<0>(coords) += rhs.x();
	get<1>(coords) += rhs.y();
	get<2>(coords) += rhs.z();
	return *this;
}

Point &Point::operator-(const Vector& rhs)
{
	get<0>(coords) -= rhs.x();
	get<1>(coords) -= rhs.y();
	get<2>(coords) -= rhs.z();
	return *this;
}

Vector Point::operator-(const Point& rhs)
{
	return Vector(	get<0>(coords) - rhs.x(),
			get<1>(coords) - rhs.y(),
			get<2>(coords) - rhs.z() );
}

void Point::draw()
{
	cout	<< get<0>(coords) << ',' 
		<< get<1>(coords) << ','
		<< get<2>(coords);
}
