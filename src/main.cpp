
#include "Point.h"
#include "Vector.h"
#include <iostream>

using namespace std;
using namespace G3D;

int main (const int argc, const char** argv)
{
	Point point1(1,2,1);
	Point point2(0,4,4);
	Vector vec1(2,0,0);
	Vector vec2;

	point1.draw();
	cout << endl;

	point2.draw();
	cout << endl;
	
	vec2 = point1 - point2;
	vec1 + vec2;
	
	(point1 + vec1).draw();
	cout << endl;

	(point2 - vec2).draw();
	cout << endl;

	return 0;
}
