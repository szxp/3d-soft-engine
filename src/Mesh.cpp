
#include "Mesh.h"

QuadMesh::QuadMesh (initializer_list<Vertex> vertices, initializer_list<unsigned short> quads):
vertexCount{vertices.size()},
vertexList{new Vertex[vertices.size()]},
quadCount{quads.size()},
quadList{new unsigned short[quads.size()]}
{
	int n=0;
	for (Vertex v : vertices) {vertexList[n++]=v;}

	n=0;
	for (unsigned short q : quads) {quadList[n++]=q;}
}

QuadMesh::~QuadMesh()
{
	if (quadList) 
	{
		delete[] quadList;
	}

	if (vertexList)
	{
		delete[] vertexList;
	}
}
