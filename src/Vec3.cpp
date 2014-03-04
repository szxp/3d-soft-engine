
#include "Vec3.h"

using namespace g3d;
using namespace std;

/**
 * Constructs a vector from the first 3 elements in the initializer list.
 * Elements with greater index than 2 will be ignored.
 */
Vec3::Vec3(initializer_list<float> values):
nums(shared_ptr<float>(new float[3], default_delete<float[]>()))
{
	int i = 0;
	for(float f : values)
	{
		if (i<3)
		{
			*(nums.get() + i++) = f;
		}
	}
}

float &Vec3::operator[] (const int ind) const
{
	return *(nums.get() + ind);
}


Vec3 Vec3::operator-(const Vec3& rhs) const
{
	Vec3 res {
		(*this)[0] - rhs[0],
		(*this)[1] - rhs[1],
		(*this)[2] - rhs[2]
	};
	return res;
}


Vec3 Vec3::operator+(const Vec3& rhs) const
{
	Vec3 res {
		(*this)[0] + rhs[0],
		(*this)[1] + rhs[1],
		(*this)[2] + rhs[2]
	};
	return res;
}


Vec3 Vec3::operator*(const float rhs) const
{
	Vec3 res {
		(*this)[0] * rhs,
		(*this)[1] * rhs,
		(*this)[2] * rhs
	};
	return res;
}

Vec3 g3d::operator*(const float lhs, const Vec3& rhs)
{
	Vec3 res {
		rhs[0] * lhs,
		rhs[1] * lhs,
		rhs[2] * lhs
	};
	return res;
}


Vec3 g3d::normalize(const Vec3& vec)
{
	float factor = 1 / vec.length();
	Vec3 res { vec[0] * factor, vec[1] * factor, vec[2] * factor };
	return res;
}

Vec3 g3d::dotProduct(const Vec3&, const Vec3&)
{

}

Vec3 g3d::crossProduct(const Vec3&, const Vec3&)
{

}
