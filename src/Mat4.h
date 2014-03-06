
#ifndef MAT4_H
#define MAT4_H

#include <memory>
#include <initializer_list>
#include "Vec3.h"

namespace g3
{

using namespace std;

/**
 * Represents a 4x4 matrix.
 */
class Mat4
{
	public:

	Mat4(initializer_list<float> n);

	// operator overloading
	float &operator[] (const int ind) const;

	private:

	/**
	 * A float array which contains the 16 elements of the matrix.
	 */
	shared_ptr<float> nums;
};


/**
 * Load the look-at-matrix (view matrix) based on the camera parameters into the first argument (res).
 */
//Mat4 &loadLookAtMatrix(Mat4 &res, Vec3 eye, Vec3 target, Vec3 up);

}

#endif
