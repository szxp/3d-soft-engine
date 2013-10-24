
#include "Point.h"
#include <iostream>

using namespace std;
using namespace G3D;

Point::Point(double x, double y, double z): coords(x,y,z) {}

void Point::draw()
{
	cout	<< get<0>(coords) << ',' 
		<< get<1>(coords) << ','
		<< get<2>(coords);
}
