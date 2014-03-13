
#ifndef SCREEN_H
#define SCREEN_H

#include <gtkmm.h>
#include "Camera.h"
#include "Mesh.h"

namespace g3
{


/**
 * Implements the graphics pipeline.
 */
class Screen: public Gtk::DrawingArea {

	public:
	Screen(unsigned int w, unsigned int h);
	virtual ~Screen(){};
	
	/**
	 * Clears the backbuffer.
	 */
	void clear();

	/**
	 * This idle callback function is executed as often as possible, 
	 * hence it is ideal for processing intensive tasks.
	 */
	bool on_idle();

	/**
	 * The drawing function, called by the GUI.
	 */
	virtual bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr);

	/**
	 * Detects mouse wheel movements. Called by the GUI.
	 */
	virtual bool on_scroll_event(GdkEventScroll* event);

	private:

	/**
	 * Renders the scene.
	 */
	void render();

	/**
	 * Draws a point on the screen.
	 */
	void drawPoint(int x, int y);

	/**
	 * Draws a line.
	 */
	void drawLine(int x0, int y0, int x1, int y1);

	/**
	 * Returns a time point in nanoseconds.
	 *
	 * @return Time point in nanoseconds.
	 */
	unsigned long clock_time();

	/**
	 * The width of the screen.
	 */
	unsigned int width;

	/**
	 * The height of the screen
	 */
	unsigned int height;

	/**
	 * Front buffer.
	 */
	Glib::RefPtr<Gdk::Pixbuf> frontBuffer;

	/**
	 * The target frame time in nanoseconds.
	 *
	 * 30 FPS = 33.3 milliseconds/frame == 33300000 nanoseconds/frame.
	 */
	unsigned long targetFrameTime;

	/**
	 * The beginning of a frame.
	 */
	unsigned long startFrameTime;

	/**
	 * The end of a frame.
	 */
	unsigned long finishFrameTime;

	/**
	 * The camera that we look from.
	 */
	Camera camera;

	/**
	 * The cube model.
	 */
	Cube cube;


	/**
	 * Rotation velocity around y axis in radians.
	 */
	float rotationY;

};

}

#endif
