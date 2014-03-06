
#include "Vec.h"

/**
 * Cross product of two vectors.
 */
g3::Vec3 g3::crossProduct(const g3::Vec3& lhs, const g3::Vec3& rhs)
{
	g3::Vec3 res {
		(lhs[1] * rhs[2]) - (lhs[2] * rhs[1]),
		(lhs[2] * rhs[0]) - (lhs[0] * rhs[2]),
		(lhs[0] * rhs[1]) - (lhs[1] * rhs[0])
	};
	return res;
}

