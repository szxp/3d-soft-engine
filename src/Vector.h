
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
	Vector ();
	Vector (double, double, double);

	// operators
	Vector &operator+(const Vector &);
	Vector &operator-(const Vector &);

	double x() const { return get<0>(coords); }
	double y() const { return get<1>(coords); }
	double z() const { return get<2>(coords); }

	private:
	tuple<double, double, double> coords;
};

}

#endif
