
#include "Point.h"
#include "Vector.h"
#include <iostream>

using namespace std;
using namespace G3D;

int main (const int argc, const char** argv)
{
	Point point1(1,2,1);
	
	point1.draw();
	cout << endl;

	return 0;
}
