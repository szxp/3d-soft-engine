
#include "Mesh.h"
#include "Vec.h"
#include "Quaternion.h"
#include "Mat.h"

/**
 * Loads a cube triangle mesh.
 */
void g3::loadCube(g3::TriangleMesh& mesh)
{
	mesh.nVertices = 8;
	mesh.vertices.reset(new Vertex[mesh.nVertices]);

	float vs[] {-1,1,1,  -1,1,-1,  1,1,-1,  1,1,1,  -1,-1,1,  -1,-1,-1,  1,-1,-1,  1,-1,1};
	for (unsigned int i = 0, j = 0; i < mesh.nVertices; i++, j+=3)
	{
		mesh.vertices[i].pos = { vs[j], vs[j+1], vs[j+2] };
	}
	
	mesh.nFaces = 12;
	mesh.faces.reset(new Triangle[mesh.nFaces]);

	unsigned int indices[] {0,1,2,  2,3,0,  4,5,6,  6,7,4,  0,5,1,  0,4,5,  3,6,7,  3,2,6,  1,5,6,  1,6,2,  0,7,3,  0,4,7};
	for (unsigned int i = 0, j = 0; i < mesh.nFaces; i++, j+=3)
	{
		mesh.faces[i].vertexIndex[0] = indices[j];
		mesh.faces[i].vertexIndex[1] = indices[j+1];
		mesh.faces[i].vertexIndex[2] = indices[j+2];
	}

	mesh.rotationX = mesh.rotationY = mesh.rotationZ = 0;
	mesh.loc = {0, 0, 0};
}


/**
 * Calculates the world transformation matrix of the triangle mesh object.
 */
g3::Mat4 g3::getWorldMatrix(g3::TriangleMesh& mesh)
{
	Vec3 axisX {1, 0, 0};
	Vec3 axisY {0, 1, 0};
	Vec3 axisZ {0, 0, 1};
	Quaternion rotX = g3::createQuaternion(axisX, mesh.rotationX);
	Quaternion rotY = g3::createQuaternion(axisY, mesh.rotationY);
	Quaternion rotZ = g3::createQuaternion(axisZ, mesh.rotationZ);

	
	return g3::createRotationMatrix(rotZ * rotY * rotX) * g3::createTranslationMatrix(mesh.loc[0], mesh.loc[1], mesh.loc[2]);
}
