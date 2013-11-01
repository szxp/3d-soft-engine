
#ifndef MESH_H
#define MESH_H

#include "Vertex.h"
#include <initializer_list>

using namespace std;

/*
 * Stores an indexed quad mesh
 */
class QuadMesh {

	public:
	QuadMesh(initializer_list<Vertex>, initializer_list<unsigned short>);
	~QuadMesh();
	
	// The vertices
	// Public for performance reason
	size_t	vertexCount;
	Vertex	*vertexList;

	// The quads
	// Public for performance reason
	size_t 		quadCount;
	unsigned short	*quadList;
};

#endif
