
#include "Vec3.h"

using namespace g3d;

/**
 * Constructs a vector from the first 3 elements in the initializer list.
 * Elements with greater index than 2 will be ignored.
 */
Vec3::Vec3(initializer_list<float> values): nums(new float[3])  {
	int i = 0;
	for(float f : values) {
		if (i<3) nums[i++] = f;
	}
}

Vec3::~Vec3() {
	if (nums) { delete[] nums; }

}

float &Vec3::operator[] (const int ind) {
	return nums[ind];
}
