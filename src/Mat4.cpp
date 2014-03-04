
#include "Mat4.h"

using namespace g3d;

/**
 * Constructs a matrix from the first 16 elements in the initializer list.
 * Elements with greater index than 15 will be ignored.
 */
Mat4::Mat4(initializer_list<float> values): nums(new float[16])  {
	int i = 0;
	for(float f : values) {
		if (i<16) nums[i++] = f;
	}
}

Mat4::~Mat4() {
	if (nums) { delete[] nums; }

}

float &Mat4::operator[] (const int ind) {
	return nums[ind];
}
