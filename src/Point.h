
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

	void draw();

	private:
	tuple<double, double, double> coords;

};

}

#endif
