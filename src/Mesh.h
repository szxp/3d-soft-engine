
#ifndef MESH_H
#define MESH_H

#include <cstddef>
#include "Vec.h"

namespace g3 
{


/*******************************************************************************
 * Describes a triangle with 3 indices. Indices refer to vertices of a Mesh.
 ******************************************************************************/
struct Triangle
{
	std::size_t indices[3];
};

/*******************************************************************************
 * Describes a general mesh with N vertices and M triangles.
 ******************************************************************************/
template<std::size_t N, std::size_t M>
struct Mesh
{
	Vec3 vertices[N];
	std::size_t nVertices;
	Triangle faces[M];
	std::size_t nFaces;
}; // struct Mesh

/*******************************************************************************
 * Cube is a concrete Mesh with 8 vertices and 12 Triangle faces.
 ******************************************************************************/
using Cube = Mesh<8, 12>;



} // namespace g3

#endif // MESH_H
