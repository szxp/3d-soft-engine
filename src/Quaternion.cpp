
#include "Quaternion.h"
#include <cmath>

/**
 * Create a unit quaternion.
 *
 * @param axis The rotation axis which should be a unit vector. If not, it will be normalized.
 * @param rad The angle of the rotation in radians.
 * @return A unit quaternion.
 */
g3::Quaternion g3::createQuaternion(const g3::Vec3& axis, const float rad)
{
	float len = axis.length();
	Vec3 norm = (len != 1) ? g3::normalize(axis) : axis;

	float factor = std::sin(rad/2.0f);

	return {
		{ norm[0] * factor, norm[1] * factor, norm[2] * factor },
		std::cos(rad/2.0f)
	};
}


/**
 * Multiplication using Grassmann product.
 * It is possible to perform one quaternion rotation followed by another.
 * In order to do so, the quaternions should be multiplied together, but
 * in the reverse order. So if an object should be rotated by q and then
 * by p, the multiplication is pq.
 */
g3::Quaternion g3::operator*(const g3::Quaternion& lhs, const g3::Quaternion& rhs)
{
	float x1 = lhs.v[0];
	float y1 = lhs.v[1];
	float z1 = lhs.v[2];
	float w1 = lhs.s;
	float x2 = rhs.v[0];
	float y2 = rhs.v[1];
	float z2 = rhs.v[2];
	float w2 = rhs.s;

	return {
		{
			(w1*x2) + (x1*w2) + (y1*z2) - (z1*y2),
			(w1*y2) - (x1*z2) + (y1*w2) + (z1*x2),
			(w1*z2) + (x1*y2) - (y1*x2) + (z1*w2)
		},
		(w1*w2) - (x1*x2) - (y1*y2) - (z1*z2)
	};
}


/**
 * Returns the magnitude of a quaternion.
 */
float g3::magnitude(const g3::Quaternion& q)
{
	return std::sqrt( (q.v[0]*q.v[0]) + (q.v[1]*q.v[1]) + (q.v[2]*q.v[2]) + (q.s*q.s) );
}

/**
 * Normalizes a quaternion.
 */
g3::Quaternion g3::normalize(const g3::Quaternion& q)
{
	float mag = g3::magnitude(q);
	if (mag <= 0) return q;

	return {
		{ q.v[0] / mag, q.v[1] / mag, q.v[2] / mag },
		q.s / mag
	};
}


/**
 * Prints a quaternion.
 */
std::ostream& g3::operator<<(std::ostream& out, const Quaternion& q)
{
	return (out << "[" << q.v[0] << ", " << q.v[1] << ", " << q.v[2] << " | " << q.s << "]");
}


/**
 * Converts a quaternion to a 4x4 rotation matrix in row major order.
 */
g3::Mat4 g3::createRotationMatrix(const g3::Quaternion& q)
{
	float x = q.v[0];
	float y = q.v[1];
	float z = q.v[2];
	float w = q.s;

	// There are some good opportunities for optimization, but it works. :)
	return {
		1-(2*y*y)-(2*z*z), (2*x*y)+(2*w*z),   (2*x*z)-(2*w*y),   0,
		(2*x*y)-(2*w*z),   1-(2*x*x)-(2*z*z), (2*y*z)+(2*w*x),   0,
		(2*x*z)+(2*w*y),   (2*y*z)-(2*w*x),   1-(2*x*x)-(2*y*y), 0,
		0,                 0,                 0,                 1
	};

}
