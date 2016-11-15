

#ifndef MAT_H
#define MAT_H

#include <cstddef>
#include <memory>
#include <initializer_list>
#include "Vec.h"
#include <iostream>

namespace g3
{

/**
 * Represents a NxN square matrix.
 */
template<std::size_t N>
class Mat
{
	public:
	/**
	 * Default constructor.
	 */
	Mat():mScalars{} {}

	Mat(std::initializer_list<float> values): mScalars()
	{
		std::size_t i = 0, j = 0;
		for (float f : values)
		{
			if (i == N*N) break;
			mScalars[i++] = f;
		}
	}

	/**
	 * Copy constructor
	 */
	Mat(const Mat<N>& other): mScalars{}
	{
		std::copy(other.mScalars, other.mScalars + (N*N), mScalars);
	}
	
	/**
	 * Move constructor
	 */
	Mat(Mat<N>&& other): mScalars{}
	{
		swap(*this, other);
	}

	/**
	 * Copy assignment operator 
	 */
	Mat<N>& operator=(Mat<N> other)
	{
		swap(*this, other);
		return *this;
	}

	/**
	 * Subscript operator overloading
	 */
	float& operator[](const std::size_t ind) { return mScalars[ind]; }
	const float& operator[](const std::size_t ind) const { return mScalars[ind]; }

	/**
	 * Matrix multiplication operator overloading
	 */
	Mat<N> operator*(const Mat<N>& other) const
	{
		Mat<N> res;
		for (std::size_t i = 0; i<N; i++)
		{
			for (std::size_t j = 0, k = 0; (j<N) || (k<N); )
			{
				res[i*N+k] += (*this)[i*N+j] * other[j*N+k]; 
				
				if ((++j == N) && (++k != N)) { j=0; }
			}
		}
		return res;
	}

	/**
	 * Scalar multiplication operator overloading
	 */
	Mat<N> operator*(const float scalar) const
	{
		Mat<N> res;
		for (std::size_t i = 0; i<N; i++)
		{
			for (std::size_t j = 0; j<N; j++)
			{
				res[i*N+j] = (*this)[i*N+j] * scalar;
			}
		}
		return res;
	}

	/**
	 * Swaps two matrices. Used by the assignment operators (copy, move).
	 */
	friend void swap(Mat<N>& first, Mat<N>& second)
	{
		// By swapping the members of two classes,
		// the two classes are effectively swapped.
		std::swap(first.mScalars, second.mScalars);
	}
	
	private:

	/**
	 * A float array which contains the elements of the matrix.
	 */
	float mScalars[N*N];
};

/**
 * Scalar multiplication operator overloading
 */
template<std::size_t N>
Mat<N> operator*(const float scalar, const Mat<N>& mat)
{
	// avoid code duplication
	return mat * scalar;
}

/**
 * Replaces a matrix with the identity matrix.
 */
template<std::size_t N>
Mat<N>& loadIdentity(Mat<N>& mat)
{
	std::size_t ind = 0;
	for (std::size_t i = 0; i<N; i++)
	{
		for (std::size_t j = 0; j<N; j++)
		{
			ind = i*N+j;
			mat[ind] = (ind % (N+1) == 0) ? 1 : 0;
		}
	}
	return mat;
}


/**
 * Type alias for a 2x2 dimensional matrix.
 */
using Mat2 = Mat<2>;

/**
 * Type alias for a 3x3 dimensional matrix.
 */
using Mat3 = Mat<3>;

/**
 * Type alias for a 4x4 dimensional matrix.
 */
using Mat4 = Mat<4>;

/**
 * Transforms a 3D point with a 4x4 matrix.
 */
Vec3 transformP3(const Vec3& vec, const Mat4& mat);

/**
 * Transforms a 3D vector with a 4x4 matrix.
 */
Vec3 transformV3(const Vec3& vec, const Mat4& mat);

/**
 * Creates a scaling matrix in row major order.
 *
 * @param scaleX valueto scale by on the all axes.
 * @return a 4x4 uniform scaling matrix
 */
Mat4 createScaleMatrix(const float scale);

/**
 * Creates a scaling matrix in row major order.
 *
 * @param scaleX value to scale by on the x-axis
 * @param scaleY value to scale by on the y-axis
 * @param scaleZ value to scale by on the x-axis
 * @return a 4x4 scaling matrix
 */
Mat4 createScaleMatrix(const float scaleX, const float scaleY, const float scaleZ);

/**
 * Creates a translation matrix in row major order.
 *
 * @param valX value to translate by on the x-axis
 * @param valY value to translate by on the y-axis
 * @param valZ value to translate by on the x-axis
 * @return a 4x4 scaling matrix
 */
Mat4 createTranslationMatrix(const float valX, const float valY, const float valZ);

/**
 * PI constant
 */
constexpr float PI = 3.14159265358979;

/**
 * Converts degrees to radians.
 *
 * @param deg degress
 * @return radian value
 */
constexpr float toRad(const float deg)
{
	return deg * PI / 180.0; 
}

/**
 * Converts radians to degrees.
 *
 * @param rad radians
 * @return degree value
 */
constexpr float toDeg(const float rad)
{
	return rad * 180.0 / PI;
}

/**
 * Transponses a matrix.
 */
Mat4 transponse(const Mat4& mat);


/**
 * Returns a rotation matrix in row major order that can be used to rotate 
 * a set of vertices around the x-axis.
 *
 * @param rad The amount, in radians, in which to rotate around the x-axis.
 * Note that you can use toRad to convert degrees to radians. 
 *
 * @return a 4x4 rotation matrix 
 */
Mat4 createRotationXMatrix(const float rad);

/**
 * Returns a rotation matrix in row major order that can be used to rotate 
 * a set of vertices around the y-axis.
 *
 * @param rad The amount, in radians, in which to rotate around the y-axis.
 * Note that you can use toRad to convert degrees to radians. 
 *
 * @return a 4x4 rotation matrix 
 */
Mat4 createRotationYMatrix(const float rad);

/**
 * Returns a rotation matrix in row major order that can be used to rotate 
 * a set of vertices around the z-axis.
 *
 * @param rad The amount, in radians, in which to rotate around the z-axis.
 * Note that you can use toRad to convert degrees to radians. 
 *
 * @return a 4x4 rotation matrix 
 */
Mat4 createRotationZMatrix(const float rad);

/**
 * Creates a left-handed look-at matrix in row major order.
 *
 * @param eye A Vec3 structure that defines the camera point. This value is used
 * in translation.
 *
 * @param target A Vec3 structure that defines the camera look-at target.
 *
 * @param up A Vec3 structure that defines the up direction of the current 
 * world, usually [0, 1, 0].
 *
 * @return A left-handed look-at matrix in row major order.
 */
Mat4 createLookAtLHMatrix(const Vec3& eye, const Vec3& target, const Vec3& up);

/**
 * Creates a left-handed perspective projection matrix based on a field of view.
 *
 * @param fieldOfViewY Field of view in the y direction, in radians.
 * @param aspectRatio Aspect ratio, defined as the view space width divided
 * by height.
 *
 * @param zNearPlane Z-value of the near view plane.
 * @param zFarPlane Z-value of the far view plane.
 * @return A left-handed perspective projection matrix.
 */
Mat4 createPerspectiveFovLHMatrix(float fieldOfViewY, float aspectRatio, float zNearPlane, float zFarPlane);

/**
 * Prints the matrix in four rows.
 */
template<std::size_t N>
std::ostream& operator<<(std::ostream& out, const Mat<N>& mat)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			out << mat[i*N+j] << ", ";
		}

		if (i < N-1)
		{
			out << std::endl;
		}
	}

	return out;
}	


}

#endif
