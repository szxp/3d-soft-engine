
#ifndef VEC3_H
#define VEC3_H

#include <initializer_list>
#include <memory>

namespace g3d
{

using namespace std;

/**
 * Represents a 3d vector.
 */
class Vec3
{
	public:

	Vec3(initializer_list<float> n);
	~Vec3();

	// operator overloading
	float	&operator[] (const int ind);
	//Vec3	operator-(const Vec3&);

	private:

	/**
	 * A float array which contains the elements of the vector.
	 */
	float *nums;
};


}

#endif
