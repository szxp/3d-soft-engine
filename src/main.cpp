
#include <iostream>
#include "Mesh.h"

using namespace std;

int main (const int argc, const char** argv)
{

	QuadMesh brick(
		{
			Vertex(1,0,1),
			Vertex(1,0,-1),
			Vertex(-1,0,-1),
			Vertex(-1,0,1),
			Vertex(1,2,1),
			Vertex(1,2,-1),
			Vertex(-1,2,-1),
			Vertex(-1,2,1)
		},
		{
			0, 1, 2, 3,
			0, 1, 5, 4,
			1, 2, 6, 5,
			2, 3, 7, 6,
			0, 3, 7, 4,
			4, 5, 6, 7
		
		}
	);

	for (int i=0; i < brick.vertexCount; i++) {
		cout	<< brick.vertexList[i].pos.x << ", "
			<< brick.vertexList[i].pos.y << ", "
			<< brick.vertexList[i].pos.z << ", ";
	}
	cout << endl;

	for (int i=0; i < brick.quadCount; i++) {
		cout << brick.quadList[i] << ", ";
	}
	cout << endl;
	
	return 0;
}
