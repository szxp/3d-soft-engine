
#include "Vec3.h"

/**
 * Constructor
 */
g3::Vec3::Vec3(float x, float y, float z)
{
	mScalars[0] = x;
	mScalars[1] = y;
	mScalars[2] = z;
}

/**
 * Copy constructor
 */
g3::Vec3::Vec3(const g3::Vec3& other)
{
	std::copy(other.mScalars, other.mScalars + size, mScalars);
}

/**
 * Move constructor
 */
g3::Vec3::Vec3(Vec3&& other): Vec3(0,0,0)
{
	swap(*this, other);
}

/**
 * Copy assignment operator
 */
g3::Vec3& g3::Vec3::operator=(Vec3 other)
{
	swap(*this, other);
	return *this;
}

/**
 * Vector subtraction.
 */
g3::Vec3 g3::Vec3::operator-(const g3::Vec3& rhs) const
{
	g3::Vec3 res {
		(*this)[0] - rhs[0],
		(*this)[1] - rhs[1],
		(*this)[2] - rhs[2]
	};
	return res;
}

/**
 * Vector addition.
 */
g3::Vec3 g3::Vec3::operator+(const g3::Vec3& rhs) const
{
	g3::Vec3 res {
		(*this)[0] + rhs[0],
		(*this)[1] + rhs[1],
		(*this)[2] + rhs[2]
	};
	return res;
}

/**
 * Scalar multiplication: vec * scalar
 */
g3::Vec3 g3::Vec3::operator*(const float scalar) const
{
	g3::Vec3 res {
		(*this)[0] * scalar,
		(*this)[1] * scalar,
		(*this)[2] * scalar
	};
	return res;
}

/**
 * Scalar multiplication: scalar * vec
 */
g3::Vec3 g3::operator*(const float scalar, const g3::Vec3& vec)
{
	// avoid code duplication
	return vec * scalar;
}

/**
 * Normalizes a vector.
 */
g3::Vec3 g3::normalize(const g3::Vec3& vec)
{
	float factor = 1 / vec.length();
	g3::Vec3 res { vec[0] * factor, vec[1] * factor, vec[2] * factor };
	return res;
}

/**
 * Dot product of two vectors.
 */
float g3::dotProduct(const g3::Vec3& lhs, const g3::Vec3& rhs)
{
	return (lhs[0] * rhs[0]) + (lhs[1] * rhs[1]) + (lhs[2] * rhs[2]);
}

/**
 * Cross product of two vectors.
 */
g3::Vec3 g3::crossProduct(const g3::Vec3& lhs, const g3::Vec3& rhs)
{
	Vec3 res {
		(lhs[1] * rhs[2]) - (lhs[2] * rhs[1]),
		(lhs[2] * rhs[0]) - (lhs[0] * rhs[2]),
		(lhs[0] * rhs[1]) - (lhs[1] * rhs[0])
	};
	return res;
}

