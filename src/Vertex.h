
#ifndef VERTEX_H
#define VERTEX_H

/*
 * Type for three coordinates
 */
struct Vector3 {
	double x,y,z;
};

/*
 * Type for four coordinates
 */
struct Vector4 {
	double x,y,z,w;
};

/*
 * The information we store at the vertex level
 */
struct Vertex {
	
	// Position of the vertex
	Vector3 pos;

	Vertex(): pos{0,0,0} {}
	Vertex(double x, double y, double z): pos{x,y,z} {}
};

#endif
