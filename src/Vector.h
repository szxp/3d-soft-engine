
#ifndef VECTOR_H
#define VECTOR_H

#include <tuple>

namespace G3D
{

using namespace std;

/**
 * Represents a 3D vector.
 */
class Vector
{
	public:
	Vector (double, double, double);

	// operators
	Vector &operator+(const Vector &);
	Vector &operator-(const Vector &);

	private:
	tuple<double, double, double> coords;
};

}

#endif
