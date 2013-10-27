
#include "Point.h"
#include "Vector.h"
#include <iostream>

using namespace std;
using namespace G3D;

int main (const int argc, const char** argv)
{
	Point point1(1,2,1);
	Point point2(4,-1,2);
	Vector vec(2,-3,4);

	point1.draw();
	cout << endl;

	(point1 - vec).draw();
	cout << endl;

	(point2 + vec).draw();
	cout << endl;
	return 0;
}
