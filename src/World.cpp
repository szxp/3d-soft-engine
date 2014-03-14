
#include "World.h"
#include <iostream>
#include <thread>
#include <chrono>
#include "Mat.h"
#include "Quaternion.h"
#include "Mesh.h"

g3::World::World(unsigned int w, unsigned int h):
width {w},
height {h},
frontBuffer {Gdk::Pixbuf::create(Gdk::Colorspace::COLORSPACE_RGB, true, 8, width, height)},
targetFrameTime {33300000},
camera { Vec3{10, 8, -10}, Vec3{0, 0, 0}, 1280 }
{
	g3::loadCube(cube);

	// start frame time
	startFrameTime = clock_time();

	clear();
	
	// enable mouse wheel detection
	add_events(Gdk::BUTTON_PRESS_MASK | Gdk::SCROLL_MASK);

	// register idle function
	Glib::signal_idle().connect(sigc::mem_fun(*this, &World::on_idle));

}


/**
 * Clears the backbuffer.
 */
void g3::World::clear()
{
	// Fill the buffer with color white
	frontBuffer->fill(0x000000ff);
	
}

/**
 * Detects mouse wheel movements. Called by the GUI.
 */
bool g3::World::on_scroll_event(GdkEventScroll* event)
{
	float zoomFactorPercent = 0.05;

	if (event->direction == GdkScrollDirection::GDK_SCROLL_UP)
	{
		camera.zoomFactor += camera.zoomFactor * zoomFactorPercent;
	}
	else
	{
		camera.zoomFactor -= camera.zoomFactor * zoomFactorPercent;
	}

	return true;
}

/**
 * The drawing function, called by the GUI.
 */
bool g3::World::on_draw(const Cairo::RefPtr<Cairo::Context>& cr) {
	
	render();
	
	// Draw the buffer
	Gdk::Cairo::set_source_pixbuf(cr, frontBuffer);
	cr->paint();

	return true;
}

/**
 * Renders the scene.
 */
void g3::World::render()
{
	clear();

	Vec3 upWorld {0,1,0};
	Mat4 viewMatrix = g3::createLookAtLHMatrix(camera.eye, camera.target, upWorld);
	Mat4 projectionMatrix = g3::createPerspectiveFovLHMatrix(0.78f, width / (float)height, 0.01f, 25.0f);
	Mat4 transformMatrix = g3::getWorldMatrix(cube) * viewMatrix * projectionMatrix;

	for (unsigned int i = 0; i < cube.nFaces; i++)
	{
		Vec3 v[3];
		int mapToWin[6];
		
		for (unsigned int j = 0; j < 3; j++)
		{
			v[j] = transformP3( cube.vertices[ cube.faces[i].vertexIndex[j] ].pos, transformMatrix );
			
			mapToWin[2*j]   = mapXToWin( v[j][0] );
			mapToWin[2*j+1] = mapYToWin( v[j][1] );
		}

		drawLine(mapToWin[0], mapToWin[1], mapToWin[2], mapToWin[3]);
		drawLine(mapToWin[2], mapToWin[3], mapToWin[4], mapToWin[5]);
		drawLine(mapToWin[4], mapToWin[5], mapToWin[0], mapToWin[1]);
	}


	// render axes
	Vec3 axes[] { {1, 0, 0}, {0, 1, 0}, {0, 0, 1} };

	


	/*
	std::size_t nVertices = cube.nVertices;
	for (int i = 0; i < nVertices; i++)
	{
		
		Vec3 v = transformP3( cube.vertices[ i ], transformMatrix );
		int x  = ( v[0] * camera.zoomFactor / (width/(float)height) ) + (width / 2);
		int y  = (-v[1] * camera.zoomFactor ) + (height / 2);
		drawPoint(x, y);
	}
	*/
}

/**
 * Maps the x coordinate to the window coordinate system
 */
inline int g3::World::mapXToWin(float x)
{
	return ( x * camera.zoomFactor / (width/(float)height)  ) + (width / 2.0f);
}

/**
 * Maps the y coordinate to the window coordinate system
 */
inline int g3::World::mapYToWin(float y)
{
	return ( -y * camera.zoomFactor ) + (height / 2.0f);
}

/**
 * Draws a line.
 */
void g3::World::drawLine(int x0, int y0, int x1, int y1)
{
	int dx = std::abs(x1 - x0);
	int dy = std::abs(y1 - y0);
	int sx = (x0 < x1) ? 1 : -1;
	int sy = (y0 < y1) ? 1 : -1;

	int err = dx - dy;

	while (true)
	{
		drawPoint(x0, y0);

		if ((x0 == x1) && (y0 == y1)) break;
		int e2 = 2 * err;
		if (e2 > -dy) { err -= dy; x0 += sx; }
		if (e2 < dx) { err += dx; y0 += sy; }
	}
}

/**
 * Draws a point on the screen.
 */
void g3::World::drawPoint(int x, int y)
{

	if ((x >= 0) && (y >=0) && (x < width) && (y < height))
	{
		int offset  = y * frontBuffer->get_rowstride() + x * frontBuffer->get_n_channels();
		guchar* pixel = &frontBuffer->get_pixels()[ offset ];

		pixel[0]=255;
		pixel[1]=255;
		pixel[2]=0;
	}
}

/**
 * Returns a time point in nanoseconds.
 *
 * @return Time point in nanoseconds.
 */
unsigned long g3::World::clock_time()
{
	timespec ts;
	clock_gettime(CLOCK_MONOTONIC_RAW, &ts);
	return (ts.tv_sec * 1000000000) + ts.tv_nsec;
}

/**
 * This idle callback function is executed as often as possible, 
 * hence it is ideal for processing intensive tasks.
 */
bool g3::World::on_idle()
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

	// Rotates the cube around the y axis in radians.
	cube.rotationX += 0.01;
	cube.rotationY += 0.01;
	cube.rotationZ += 0.01;

	return true;
}


