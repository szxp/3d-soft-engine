
#ifndef POINT_H
#define POINT_H

#include <tuple>
#include "Vector.h"

namespace G3D 
{

using namespace std;

/**
 * Represents a 3D point.
 */
class Point
{
	public:
	Point (double, double, double);

	// operators
	Point  &operator+(const Vector&);
	Point  &operator-(const Vector&);
	Vector operator-(const Point&);

	double x() const { return get<0>(coords); }
	double y() const { return get<1>(coords); }
	double z() const { return get<2>(coords); }
	
	void draw();

	private:
	tuple<double, double, double> coords;

};

}

#endif
