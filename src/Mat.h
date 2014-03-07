
#ifndef MAT_H
#define MAT_H

#include <cstddef>
#include <memory>
#include <initializer_list>
#include "Vec.h"

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
template<std::size_t N>
Vec3 transformP3(const Vec3& vec, const Mat4& mat)
{
	float x =  (vec[0] * mat[0]) + (vec[1] * mat[4]) + (vec[2] * mat[8])  + mat[12];
	float y = (vec[0] * mat[1]) + (vec[1] * mat[5]) + (vec[2] * mat[9])  + mat[13];
	float z =  (vec[0] * mat[2]) + (vec[1] * mat[6]) + (vec[2] * mat[10]) + mat[14];
	float w = (vec[0] * mat[3]) + (vec[1] * mat[7]) + (vec[2] * mat[11]) + mat[15];	
	
	if (w != 1 && w != 0)
	{
		x /= w;
		y /= w;
		z /= w;
	}

	return Vec3 { x, y, z };
}

/**
 * Transforms a 3D vector with a 4x4 matrix.
 */
template<std::size_t N>
Vec3 transformV3(const Vec3& vec, const Mat4& mat)
{
	return Vec3 {
		(vec[0] * mat[0]) + (vec[1] * mat[4]) + (vec[2] * mat[8]),
		(vec[0] * mat[1]) + (vec[1] * mat[5]) + (vec[2] * mat[9]),
		(vec[0] * mat[2]) + (vec[1] * mat[6]) + (vec[2] * mat[10])
	};
}

/**
 * Load the look-at-matrix (view matrix) based on the camera parameters into the first argument (res).
 */
//Mat4 &loadLookAtMatrixLH(Mat4 &res, Vec3 eye, Vec3 target, Vec3 up);

}

#endif
