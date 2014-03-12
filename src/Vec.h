
#ifndef VEC_H
#define VEC_H

#include <cstddef>
#include <memory>
#include <cmath>
#include <iostream>

namespace g3
{

/**
 * Represents an N-dimensional vector.
 */
template<std::size_t N>
class Vec
{
	public:

	Vec():mScalars{} {}

	Vec(std::initializer_list<float> scalars): mScalars()
	{
		std::size_t i = 0;
		for (float f : scalars)
		{
			if (N == i) break;
			mScalars[i++] = f;
		}
	}

	/**
	 * Copy constructor 
	 */
	Vec(const Vec<N>& other): mScalars{}
	{
		std::copy(other.mScalars, other.mScalars + N, mScalars);
	}

	/**
	 * Move constructor
	 */
	Vec(Vec<N>&& other): mScalars{}
	{
		swap(*this, other);
	}

	/**
	 * Copy assignment operator 
	 */
	Vec<N>& operator=(Vec<N> other)
	{
		swap(*this, other);
		return *this;
	}

	/**
	 * Subscript operator overloading
	 */
	float& operator[] (const int ind) { return mScalars[ind]; }
	const float& operator[] (const int ind) const { return mScalars[ind]; }

	/**
	 * Unary minus operator overloading
	 */
	Vec<N> operator-() const
	{
		g3::Vec<N> res;
		for (int i = 0; i < N; i++)
		{
			res[i] = -((*this)[i]);
		}
		return res;
	}
	
	/**
	 * Vector addition.
	 */
	Vec<N> operator+(const Vec<N>& rhs) const
	{
		g3::Vec<N> res;
		for (int i = 0; i < N; i++)
		{
			res[i] = (*this)[i] + rhs[i];
		}
		return res;
	}
	
	/**
	 * Vector subtraction.
	 */
	Vec<N> operator-(const Vec<N>& rhs) const
	{
		// avoid code duplication
		return (*this) + -rhs;
	}
	
	
	/**
	 * Scalar multiplication: vec * scalar
	 */
	Vec<N> operator*(const float scalar) const
	{
		g3::Vec<N> res;
		for (int i = 0; i < N; i++)
		{
			res[i] = (*this)[i] * scalar;
		}
		return res;
	}

	/**
	 * Returns the length of the vector.
	 */
	float length() const { 
	
		float res = 0;
		for (int i = 0; i < N; i++)
		{
			res += (*this)[i] * (*this)[i];
		}
		return std::sqrt(res);
	}

	/**
	 * Swaps two vectors. Used by the assignment operators (copy, move).
	 */
	friend void swap(Vec<N>& first, Vec<N>& second)
	{
		// By swapping the members of two classes,
		// the two classes are effectively swapped.
		std::swap(first.mScalars, second.mScalars);
	}


	private:

	/**
	 * A float array which contains the elements of the vector.
	 */
	float mScalars[N];
};

/**
 * Tpye alias for a 2D vector.
 */
using Vec2 = Vec<2>;

/**
 * Tpye alias for a 3D vector.
 */
using Vec3 = Vec<3>;

/**
 * Tpye alias for a 4D vector.
 */
using Vec4 = Vec<4>;


/**
 * Scalar multiplication: scalar * vec
 */
template<std::size_t N>
Vec<N> operator*(const float scalar, const Vec<N>& vec)
{
	// avoid code duplication
	return vec * scalar;
}

/**
 * Normalizes a vector.
 */
template<std::size_t N>
Vec<N> normalize(const Vec<N>& vec)
{
	Vec<N> res;
	float factor = N > 0 ? 1 / vec.length() : 1;
	for (int i = 0; i < N; i++)
	{
		res[i] = vec[i] * factor;
	}
	return res;
}

/**
 * Dot product of two vectors.
 */
template<std::size_t N>
float dotProduct(const Vec<N>& lhs, const Vec<N>& rhs)
{
	float res = 0;
	for (int i = 0; i < N; i++)
	{
		res += lhs[i] * rhs[i];
	}
	return res;
}

/**
 * Cross product of two vectors, specifically for only 3D vectors. 
 */
Vec3 crossProduct(const Vec3&, const Vec3&);



/**
 * Prints the vector.
 */
template<std::size_t N>
std::ostream& operator<<(std::ostream& out, const Vec<N>& vec)
{
	for (int i = 0; i < N; i++)
	{
		if (i > 0)
		{
			out << ", ";
		}
		out << vec[i];
	}

	return out;
}	


}
#endif
