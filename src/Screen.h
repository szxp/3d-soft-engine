
#ifndef SCREEN_H
#define SCREEN_H

#include <gtkmm.h>

namespace g3d
{

/**
 * Represents a 2D screen. It uses double buffering.
 */
class Screen: public Gtk::DrawingArea {

	public:
	Screen();
	virtual ~Screen(){};
	
	virtual bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr);


	private:
	Glib::RefPtr<Gdk::Pixbuf> frontBuffer;
	Glib::RefPtr<Gdk::Pixbuf> backBuffer;
};

}

#endif
