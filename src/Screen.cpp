
#include "Screen.h"

using namespace G3D;

Screen::Screen():
frontBuffer(Gdk::Pixbuf::create(Gdk::Colorspace::COLORSPACE_RGB, true, 8, 640, 480)),
backBuffer(Gdk::Pixbuf::create(Gdk::Colorspace::COLORSPACE_RGB, true, 8, 640, 480)) {

	frontBuffer->fill(0xffffffff);
	backBuffer->fill(0xffffffff);

}


bool Screen::on_draw(const Cairo::RefPtr<Cairo::Context>& cr) {

	Gtk::Allocation allocation = get_allocation();
	const int width  = allocation.get_width();
	const int height = allocation.get_height();

	// Draw the image in the middle of the drawing area, or (if the image is
	// larger than the drawing area) draw the middle part of the image.
	Gdk::Cairo::set_source_pixbuf(cr, frontBuffer);
	cr->paint();

	return true;
}
