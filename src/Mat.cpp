
#include "Mat.h"


/**
 * Transforms a 3D point with a 4x4 matrix.
 */
g3::Vec3 g3::transformP3(const Vec3& vec, const Mat4& mat)
{
	float x =  (vec[0] * mat[0]) + (vec[1] * mat[4]) + (vec[2] * mat[8])  + mat[12];
	float y = (vec[0] * mat[1]) + (vec[1] * mat[5]) + (vec[2] * mat[9])  + mat[13];
	float z =  (vec[0] * mat[2]) + (vec[1] * mat[6]) + (vec[2] * mat[10]) + mat[14];
	float w = (vec[0] * mat[3]) + (vec[1] * mat[7]) + (vec[2] * mat[11]) + mat[15];	
	
	if (w != 1 && w != 0)
	{
		x /= w;
		y /= w;
		z /= w;
	}

	return Vec3 { x, y, z };
}

/**
 * Transforms a 3D vector with a 4x4 matrix.
 */
g3::Vec3 g3::transformV3(const Vec3& vec, const Mat4& mat)
{
	return Vec3 {
		(vec[0] * mat[0]) + (vec[1] * mat[4]) + (vec[2] * mat[8]),
		(vec[0] * mat[1]) + (vec[1] * mat[5]) + (vec[2] * mat[9]),
		(vec[0] * mat[2]) + (vec[1] * mat[6]) + (vec[2] * mat[10])
	};
}


/**
 * Creates a scaling matrix in row major order.
 *
 * @param scale value to scale by on all axes (x,y,z).
 * @return a 4x4 uniform scaling matrix
 */
g3::Mat4 g3::createScalingMatrix(const float scale)
{
	return Mat4 {
		scale, 0,     0,     0,
		0,     scale, 0,     0,
		0,     0,     scale, 0,
		0,     0,     0,     1
	};
}

/**
 * Creates a scaling matrix in row major order.
 *
 * @param scaleX value to scale by on the x-axis
 * @param scaleY value to scale by on the y-axis
 * @param scaleZ value to scale by on the x-axis
 * @return a 4x4 scaling matrix
 */
g3::Mat4 g3::createScalingMatrix(const float scaleX, const float scaleY, const float scaleZ)
{
	return Mat4 {
		scaleX, 0,      0,      0,
		0,      scaleY, 0,      0,
		0,      0,      scaleZ, 0,
		0,      0,      0,      1
	};
}

/**
 * Creates a translation matrix in row major order.
 *
 * @param valX value to translate by on the x-axis
 * @param valY value to translate by on the y-axis
 * @param valZ value to translate by on the x-axis
 * @return a 4x4 scaling matrix
 */
g3::Mat4 g3::createTranslationMatrix(const float valX, const float valY, const float valZ)
{
	return Mat4 {
		1,    0,    0,    0,
		0,    1,    0,    0,
		0,    0,    1,    0,
		valX, valY, valZ, 1
	};
}


