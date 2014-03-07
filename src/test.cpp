
#include <cassert>
#include <iostream>
#include <utility>
#include "Vec.h"
#include "Mat.h"

using namespace std;
using namespace g3;

int main (int argc, char** argv)
{

	// matrix subscript operator
	initializer_list<float> values {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
	Mat4 mat(values);
	int i = 0;
	for(float f : values) { assert(mat[i++]==f); }

	// matrix multiplication
	Mat2 mul1 {1, 2, 3, 4};
	Mat2 mul2 {5, 6, 7, 8};
	Mat2 res = mul1 * mul2;
	assert( (res[0]==19) && (res[1]==22) && (res[2]==43) && (res[3]==50));

	// matrix scalar multiplication
	Mat2 dup = mul1 * 2;
	assert( (dup[0]==2) && (dup[1]==4) && (dup[2]==6) && (dup[3]==8));
	Mat2 dup2 = 2 * mul2;
	assert( (dup2[0]==10) && (dup2[1]==12) && (dup2[2]==14) && (dup2[3]==16));

	// matrix loadIdentity
	Mat2 iden;
	loadIdentity(iden);
	assert( (iden[0]==1) && (iden[1]==0) && (iden[2]==0) && (iden[3]==1));

	// matrix scaling
	Mat4 scaleMat1 = createScalingMatrix(5);
	assert( (scaleMat1[0]==5) && (scaleMat1[5]==5) && (scaleMat1[10]==5) && (scaleMat1[15]==1));
	Mat4 scaleMat2 = createScalingMatrix(3,4,5);
	assert( (scaleMat2[0]==3) && (scaleMat2[5]==4) && (scaleMat2[10]==5) && (scaleMat1[15]==1));

	// matrix transform point
	Vec3 point {1,2,3};
	Mat4 scaleMat = createScalingMatrix(5);
	Vec3 newPoint = transformP3(point, scaleMat);
	assert((newPoint[0]==5) && (newPoint[1]==10) && (newPoint[2]==15));


	Vec3 vec1 {1, 2, 3};
	Vec3 vec2 {3, 2, -1};

	// vector copy constructor
	Vec3 copy (vec1);
	assert( (copy[0]==1) && (copy[1]==2) && (copy[2]==3));

	// vector move constructor
	Vec3 moveTo = std::move(vec1 + vec2);
	assert( (moveTo[0]==4) && (moveTo[1]==4) && (moveTo[2]==2));

	// vector copy assignment operator
	Vec3 swap1 {4, 5, 6};
	Vec3 swap2 {-1, 2, 4};
	swap2 = swap1;
	assert( (swap2[0]==4) && (swap2[1]==5) && (swap2[2]==6));

	// addition: vec + vec
	Vec3 vec3 = vec1 + vec2;
	assert( (vec3[0]==4) && (vec3[1]==4) && (vec3[2]==2));

	// vector: unary minus
	Vec3 min = -vec1;
	assert( (min[0]==-1) && (min[1]==-2) && (min[2]==-3));
	
	// subtraction: vec - vec
	Vec3 vec4 = vec1 - vec2;
	assert( (vec4[0]==-2) && (vec4[1]==0) && (vec4[2]==4));

	// scalar multiplication: vec * s | s * vec
	Vec3 vec51 = vec1 * 20;
	Vec3 vec52 = 30 * vec1;
	assert( (vec51[0]==20) && (vec51[1]==40) && (vec51[2]==60));
	assert( (vec52[0]==30) && (vec52[1]==60) && (vec52[2]==90));

	// length of a vector
	Vec3 lenVec {0, 0, -4};
	assert(4 == lenVec.length());
	
	// vector normalize
	Vec3 norm = normalize(lenVec);
	assert( (norm[0]==0) && (norm[1]==0) && (norm[2]==-1));

	// vector dot product
	Vec3 dot1 {1,2,3};
	Vec3 dot2 {2,3,4};
	assert(dotProduct(dot1, dot2) == 20);

	// vector cross product
	Vec3 cross1 {1,2,3};
	Vec3 cross2 {3,1,1};
	Vec3 cross = crossProduct(cross1, cross2);
	assert( (cross[0]==-1) && (cross[1]==8) && (cross[2]==-5));

	std::cout << "test ok" << std::endl;
	return 0;
}
