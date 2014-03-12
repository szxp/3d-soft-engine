
#ifndef MESH_H
#define MESH_H

#include <cstddef>
#include "Vec.h"

namespace g3 
{


/*******************************************************************************
 * Describes a general face with N indices. Indices refer to vertices of a Mesh.
 ******************************************************************************/
template<std::size_t S>
struct Face
{
	std::size_t indices[S];
};

/*******************************************************************************
 * Triangle is a concrete Face.
 ******************************************************************************/
using Triangle = Face<3>;

/*******************************************************************************
 * Describes a general mesh with N vertices and M faces of type F.
 ******************************************************************************/
template<std::size_t N, std::size_t M, typename F>
struct Mesh
{
	Vec3 vertices[N];
	std::size_t nVertices = N;
	F faces[M];
	std::size_t nFaces = M;
}; // struct Mesh

/*******************************************************************************
 * Cube is a concrete Mesh with 8 vertices and 12 Triangle faces.
 ******************************************************************************/
using Cube = Mesh<8, 12, Triangle>;


} // namespace g3

#endif // MESH_H
