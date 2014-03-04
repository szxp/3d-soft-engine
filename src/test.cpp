
#include <cassert>
#include <iostream>
#include "Vec3.h"
#include "Mat4.h"

using namespace std;
using namespace g3d;

int main (int argc, char** argv)
{
	// subscript operator
	initializer_list<float> values {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
	Mat4 mat(values);
	int i = 0;
	for(float f : values) { assert(mat[i++]==f); }
	

	Vec3 vec1 {1, 2, 3};
	Vec3 vec2 {3, 2, -1};

	// addition
	Vec3 vec3 = vec1 + vec2;
	assert( (vec3[0]==4) && (vec3[1]==4) && (vec3[2]==2));

	// subtraction
	Vec3 vec4 = vec1 - vec2;
	assert( (vec4[0]==-2) && (vec4[1]==0) && (vec4[2]==4));

	// scalar multiplication
	Vec3 vec5 = vec1 * 20;
	assert( (vec5[0]==20) && (vec5[1]==40) && (vec5[2]==60));

	std::cout << "test ok" << std::endl;
	return 0;
}
