
#ifndef QUATERNION_H
#define QUATERNION_H

#include "Vec.h"
#include "Mat.h"
#include <iostream>

namespace g3
{

/**
 * Describes a quaternion.
 */
struct Quaternion
{
	/**
	 * Vector component.
	 * Represents the axis about which a rotation will occur.
	 */
	Vec3 v;

	/**
	 * Scalar component.
	 * The amount of rotation about the axis defined by vector v component.
	 */
	float s;

}; // struct Quaternion


/**
 * Create a unit quaternion.
 *
 * @param axis The rotation axis which should be a unit vector. If not, it will be normalized.
 * @param rad The angle of the rotation in radians.
 * @return A unit quaternion.
 */
Quaternion createQuaternion(const Vec3& axis, const float rad);


/**
 * Multiplication using Grassmann product.
 * It is possible to perform one quaternion rotation followed by another.
 * In order to do so, the quaternions should be multiplied together, but
 * in the reverse order. So if an object should be rotated by q and then
 * by p, the multiplication is pq.
 */
Quaternion operator*(const Quaternion& lhs, const Quaternion& rhs);


/**
 * Returns the magnitude of a quaternion.
 */
float magnitude(const Quaternion& q);


/**
 * Normalizes a quaternion.
 */
Quaternion normalize(const Quaternion& q);


/**
 * Converts a quaternion to a 4x4 rotation matrix in row major order.
 */
Mat4 createRotationMatrix(const Quaternion& q);


/**
 * Prints a quaternion.
 */
std::ostream& operator<<(std::ostream& out, const Quaternion& q);


} // namespace g3


#endif // QUATERNION_H

