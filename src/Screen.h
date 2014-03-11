
#ifndef SCREEN_H
#define SCREEN_H

#include <gtkmm.h>

namespace g3
{


/**
 * Represents a 2D screen. It uses double buffering.
 */
class Screen: public Gtk::DrawingArea {

	public:
	Screen();
	virtual ~Screen(){};
	
	/**
	 * Clears the buffer.
	 */
	void clear();

	/**
	 * This idle callback function is executed as often as possible, 
	 * hence it is ideal for processing intensive tasks.
	 */
	bool on_idle();

	virtual bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr);


	private:

	/**
	 * Returns a time point in nanoseconds.
	 *
	 * @return Time point in nanoseconds.
	 */
	unsigned long clock_time();

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

};

}

#endif
