
#include "Screen.h"
#include <iostream>
#include <thread>
#include <chrono>
#include "Mat.h"

g3::Screen::Screen(const int w, const int h):
width {w},
height {h},
frontBuffer {Gdk::Pixbuf::create(Gdk::Colorspace::COLORSPACE_RGB, true, 8, width, height)},
targetFrameTime {33300000},
camera { Vec3{10, 10, -10}, Vec3{0, 0, 0} },
rotationY {0},
cube {
	{ {{-1,1,1}}, {{1,1,1}}, {{-1,-1,1}}, {{-1,-1,-1}},{{-1,1,-1}}, {{1,1,-1}}, {{1,-1,1}}, {{1,-1,-1}} }
	,8
	,{ {{0,1,2}}, {{1,2,3}}, {{1,3,6}}, {{1,5,6}}, {{0,1,4}}, {{1,4,5}}, {{2,3,7}}, {{3,6,7}}, {{0,2,7}}, {{0,4,7}}, {{4,5,6}}, {{4,6,7}} }
	,12
}
{
	// start frame time
	startFrameTime = clock_time();

	clear();

	// register idle function
	Glib::signal_idle().connect(sigc::mem_fun(*this, &Screen::on_idle));
}


void g3::Screen::clear()
{
	// Fill the buffer with color white
	frontBuffer->fill(0x0f3ff0ff);
	
}

bool g3::Screen::on_draw(const Cairo::RefPtr<Cairo::Context>& cr) {
	
	//Gtk::Allocation allocation = get_allocation();
	//const int width  = allocation.get_width();
	//const int height = allocation.get_height();

	render();
	
	// Draw the buffer
	Gdk::Cairo::set_source_pixbuf(cr, frontBuffer);
	cr->paint();

	return true;
}

/**
 * Renders the scene.
 */
void g3::Screen::render()
{
	clear();

	Vec3 upWorld {0,1,0};
	Mat4 viewMatrix = g3::createLookAtLHMatrix(camera.eye, camera.target, upWorld);
	Mat4 projectionMatrix = g3::createPerspectiveFovLHMatrix(0.78f, width / (float)height, 0.01f, 25.0f);

	Mat4 worldMatrix = g3::createScaleMatrix(1) * g3::createRotationYMatrix(rotationY);
	Mat4 transformMatrix = worldMatrix * viewMatrix * projectionMatrix;

	//std::size_t nFaces = cube.nFaces;
	std::size_t nVertices = cube.nVertices;
	for (int i = 0; i < nVertices; i++)
	{

		//std::cout << "Orig vec3: "<< cube.vertices[i][0] << ", " << cube.vertices[i][1] << ", " << cube.vertices[i][2] << std::endl;

		Vec3 v = transformP3( cube.vertices[i], transformMatrix );
		
		//std::cout << v[0] << ", " << v[1] << ", " << v[2] << std::endl;

		// transform point to window coordinate system
		int x = (v[0] * width) + (width / 2);
		int y = (-v[1] * height) + (height / 2);

		drawPoint(x, y);
	}

}


/**
 * Draws a point on the screen.
 */
void g3::Screen::drawPoint(int x, int y)
{
	//std::cout << x << ", " << y << std::endl;

	if ((x >= 0) && (y >=0) && (x < width) && (y < height))
	{

		int offset  = y * frontBuffer->get_rowstride() + x * frontBuffer->get_n_channels();
		guchar* pixel = &frontBuffer->get_pixels()[ offset ];

		pixel[0]=255;
		pixel[1]=255;
		pixel[2]=255;
	}
}

/**
 * Returns a time point in nanoseconds.
 *
 * @return Time point in nanoseconds.
 */
unsigned long g3::Screen::clock_time()
{
	timespec ts;
	clock_gettime(CLOCK_MONOTONIC_RAW, &ts);
	return (ts.tv_sec * 1000000000) + ts.tv_nsec;
}

/**
 * This idle callback function is executed as often as possible, 
 * hence it is ideal for processing intensive tasks.
 */
bool g3::Screen::on_idle()
{
	// finish current frame
	finishFrameTime = clock_time();

	// The amount of time that the frame spent in nanoseconds.
	unsigned long timeSpentInFrame = finishFrameTime - startFrameTime;

	if (timeSpentInFrame <= targetFrameTime)
	{
		// sleep
		std::chrono::duration<float, std::nano> wait { targetFrameTime - timeSpentInFrame };
		std::this_thread::sleep_for( wait );

		// redraw only if we were too fast in the prevoius frame.
		queue_draw();
	}
	else
	{
		// Here we were too slow so we will skip the next redrawing.
		std::cout << "Frame dropping: " << timeSpentInFrame << std::endl;
	}
	
	// start new frame
	startFrameTime = clock_time();

	// Elapsed time calculation between two frames goes here
	// ...

	rotationY += 0.01;

	return true;
}


