
#ifndef SCREEN_H
#define SCREEN_H

#include <gtkmm.h>
#include <chrono>

namespace g3
{

typedef std::chrono::high_resolution_clock Clock;
typedef std::chrono::time_point<Clock> TimePoint;
typedef std::chrono::microseconds MicroSeconds;


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
	Glib::RefPtr<Gdk::Pixbuf> frontBuffer;
	Glib::RefPtr<Gdk::Pixbuf> backBuffer;

	/**
	 * The target frame time in microseconds.
	 */
	MicroSeconds targetFrameTime;

	/**
	 * The time point when the last frame is completed.
	 */
	TimePoint lastFrameCompleted;

};

}

#endif
