
#ifndef MAT4_H
#define MAT4_H

#include <initializer_list>

namespace g3d
{

using namespace std;

/**
 * Represents a 4x4 matrix.
 */
class Mat4
{
	public:

	Mat4(initializer_list<float> n);
	~Mat4();

	// operator overloading
	float &operator[] (const int ind);

	private:

	/**
	 * A float array which contains the 16 elements of the matrix.
	 */
	float *nums;
};


// helper functions
Mat4 &resetLookAtMatrix();

}

#endif
