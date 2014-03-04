
#include "Mat4.h"

using namespace g3d;
using namespace std;

Mat4::Mat4(initializer_list<float> values):
nums( shared_ptr<float>(new float[16], default_delete<float[]>()))
{
	int i = 0;
	for(float f : values) 
	{
		if (i<16)
		{
			*(nums.get() + i++) = f;
		}
	}
}

float &Mat4::operator[] (const int ind) const
{
	return *(nums.get() + ind);
}

