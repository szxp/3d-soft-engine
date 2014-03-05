
#include "Vec3.h"

/**
 * Constructor
 *
 * Constructs a vector from the first 3 elements in the initializer list.
 * Elements with greater index than 2 will be ignored.
 */
g3d::Vec3::Vec3(std::initializer_list<float> values):
nums(new float[size])
{
	int i = 0;
	for(float f : values)
	{
		// skip if the vector is ready
		// no more elements than the size
		if (size == i) break;

		nums[i++] = f;
	}
}

/**
 * Destructor
 */
g3d::Vec3::~Vec3()
{
	delete[] nums;
}

/**
 * Copy constructor
 */
g3d::Vec3::Vec3(const g3d::Vec3& other):
nums(new float[size])
{
	std::copy(other.nums, other.nums + size, nums);
}

/**
 * Move constructor
 */
g3d::Vec3::Vec3(Vec3&& other): Vec3({0,0,0})
{
	swap(*this, other);
}

/**
 * Copy assignment operator
 */
g3d::Vec3& g3d::Vec3::operator=(Vec3 other)
{
	swap(*this, other);
	return *this;
}

/**
 * Vector subtraction.
 */
g3d::Vec3 g3d::Vec3::operator-(const g3d::Vec3& rhs) const
{
	g3d::Vec3 res {
		(*this)[0] - rhs[0],
		(*this)[1] - rhs[1],
		(*this)[2] - rhs[2]
	};
	return res;
}

/**
 * Vector addition.
 */
g3d::Vec3 g3d::Vec3::operator+(const g3d::Vec3& rhs) const
{
	g3d::Vec3 res {
		(*this)[0] + rhs[0],
		(*this)[1] + rhs[1],
		(*this)[2] + rhs[2]
	};
	return res;
}

/**
 * Scalar multiplication: vec * scalar
 */
g3d::Vec3 g3d::Vec3::operator*(const float scalar) const
{
	g3d::Vec3 res {
		(*this)[0] * scalar,
		(*this)[1] * scalar,
		(*this)[2] * scalar
	};
	return res;
}

/**
 * Scalar multiplication: scalar * vec
 */
g3d::Vec3 g3d::operator*(const float scalar, const g3d::Vec3& vec)
{
	// avoid code duplication
	return vec * scalar;
}

/**
 * Normalizes a vector.
 */
g3d::Vec3 g3d::normalize(const g3d::Vec3& vec)
{
	float factor = 1 / vec.length();
	g3d::Vec3 res { vec[0] * factor, vec[1] * factor, vec[2] * factor };
	return res;
}

/**
 * Dot product of two vectors.
 */
float g3d::dotProduct(const g3d::Vec3& lhs, const g3d::Vec3& rhs)
{
	return (lhs[0] * rhs[0]) + (lhs[1] * rhs[1]) + (lhs[2] * rhs[2]);
}

/**
 * Cross product of two vectors.
 */
g3d::Vec3 g3d::crossProduct(const g3d::Vec3& lhs, const g3d::Vec3& rhs)
{
	Vec3 res {
		(lhs[1] * rhs[2]) - (lhs[2] * rhs[1]),
		(lhs[2] * rhs[0]) - (lhs[0] * rhs[2]),
		(lhs[0] * rhs[1]) - (lhs[1] * rhs[0])
	};
	return res;
}

