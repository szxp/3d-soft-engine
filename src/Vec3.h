
#ifndef VEC3_H
#define VEC3_H

#include <cstddef>
#include <memory>
#include <cmath>

namespace g3
{

/**
 * Represents a 3d vector.
 */
class Vec3
{
	public:
	
	explicit Vec3(float x, float y, float z);

	/**
	 * Copy constructor 
	 */
	Vec3(const Vec3&);

	/**
	 * Move constructor
	 */
	Vec3(Vec3&&);

	/**
	 * Copy assignment operator 
	 */
	Vec3& operator=(Vec3);

	/**
	 * Subscript operator overloading
	 */
	const float& operator[] (const int ind) const { return mScalars[ind]; }

	/**
	 * Vector subtraction.
	 */
	Vec3 operator-(const Vec3&) const;
	
	/**
	 * Vector addition.
	 */
	Vec3 operator+(const Vec3&) const;
	
	
	/**
	 * Scalar multiplication: vec * scalar
	 */
	Vec3 operator*(const float) const;

	/**
	 * Returns the length of the vector.
	 */
	float length() const { return std::sqrt((mScalars[0] * mScalars[0]) + (mScalars[1] * mScalars[1]) + (mScalars[2] * mScalars[2])); }

	/**
	 * Swaps two vectors. Used by the assignment operators (copy, move).
	 */
	friend void swap(Vec3& first, Vec3& second)
	{
		// By swapping the members of two classes,
		// the two classes are effectively swapped.
		std::swap(first.mScalars, second.mScalars);
	}

	private:

	/**
	 * The number of floats in the vector.
	 */
	static const std::size_t size = 3;
	
	/**
	 * A float array which contains the elements of the vector.
	 */
	float mScalars[size];
};


/**
 * Scalar multiplication: scalar * vec
 */
Vec3 operator*(const float lhs, const Vec3& rhs);

/**
 * Normalizes a vector.
 */
Vec3 normalize(const Vec3&);

/**
 * Dot product of two vectors.
 */
float dotProduct(const Vec3&, const Vec3&);

/**
 * Cross product of two vectors.
 */
Vec3 crossProduct(const Vec3&, const Vec3&);

}
#endif
