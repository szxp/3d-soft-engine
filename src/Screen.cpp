
#include "Screen.h"

using namespace g3d;

Screen::Screen():
frontBuffer(Gdk::Pixbuf::create(Gdk::Colorspace::COLORSPACE_RGB, true, 8, 640, 480)),
backBuffer(Gdk::Pixbuf::create(Gdk::Colorspace::COLORSPACE_RGB, true, 8, 640, 480)) {

	// Fill the buffer with color white
	frontBuffer->fill(0xffffffff);

	// Fill the buffer with color white
	backBuffer->fill(0xffffffff);

}


bool Screen::on_draw(const Cairo::RefPtr<Cairo::Context>& cr) {

	Gtk::Allocation allocation = get_allocation();
	const int width  = allocation.get_width();
	const int height = allocation.get_height();

	// Draw the buffer
	Gdk::Cairo::set_source_pixbuf(cr, frontBuffer);
	cr->paint();

	return true;
}
