
#ifndef VEC3_H
#define VEC3_H

#include <initializer_list>
#include <memory>
#include <cmath>

namespace g3d
{

using namespace std;

/**
 * Represents a 3d vector.
 */
class Vec3
{
	public:

	Vec3(initializer_list<float> n);

	// operator overloading
	float	&operator[] (const int ind) const;
	Vec3	operator-(const Vec3&) const;
	Vec3	operator+(const Vec3&) const;
	Vec3	operator*(const float) const;

	float length() const {
		float *p = nums.get();
		return sqrt((p[0] * p[0]) + (p[1] * p[1]) + (p[2] * p[2]));
	}

	private:

	/**
	 * A float array which contains the elements of the vector.
	 *
	 * Shared ptr is used to support efficent operator overloading 
	 * when a new Vec3 object must be returned and move semantics is not supported.
	 * vec + vec
	 * vec - vec
	 * scalar * vec
	 *
	 */
	shared_ptr<float> nums;
};


Vec3 operator*(const float lhs, const Vec3& rhs);

Vec3 normalize(const Vec3&);
Vec3 dotProduct(const Vec3&, const Vec3&);
Vec3 crossProduct(const Vec3&, const Vec3&);

}
#endif
