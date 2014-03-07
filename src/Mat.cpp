
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
