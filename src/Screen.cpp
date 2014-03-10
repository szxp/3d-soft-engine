
#include "Screen.h"
#include <iostream>
#include <thread>
#include <chrono>

g3::Screen::Screen():
frontBuffer {Gdk::Pixbuf::create(Gdk::Colorspace::COLORSPACE_RGB, true, 8, 640, 480)},
backBuffer {Gdk::Pixbuf::create(Gdk::Colorspace::COLORSPACE_RGB, true, 8, 640, 480)},
targetFrameTime {2000000}, // micro
lastFrameCompleted {Clock::now()}
{

	clear();

	// register idle function
	Glib::signal_idle().connect(sigc::mem_fun(*this, &Screen::on_idle));
}


void g3::Screen::clear()
{
	// Fill the buffer with color white
	frontBuffer->fill(0xffffffff);
	
	// Fill the buffer with color white
	backBuffer->fill(0xffffffff);
}

bool g3::Screen::on_draw(const Cairo::RefPtr<Cairo::Context>& cr) {
	
	clear();

	Gtk::Allocation allocation = get_allocation();
	const int width  = allocation.get_width();
	const int height = allocation.get_height();

	// Draw the buffer
	Gdk::Cairo::set_source_pixbuf(cr, frontBuffer);
	cr->paint();

	return true;
}


/**
 * This idle callback function is executed as often as possible, 
 * hence it is ideal for processing intensive tasks.
 */
bool g3::Screen::on_idle()
{
	TimePoint now = Clock::now();
	auto elapsed = std::chrono::duration_cast<MicroSeconds>(now - lastFrameCompleted);
	std::cout << "Elapsed: " << elapsed.count() << std::endl;
	lastFrameCompleted = now;

	// sleep
	MicroSeconds wait {(elapsed <= targetFrameTime)
		? (targetFrameTime - elapsed) + targetFrameTime
		: targetFrameTime - (elapsed % targetFrameTime)};

	std::cout << "Sleep for: " << wait.count() << std::endl;
	std::this_thread::sleep_for( wait );

	queue_draw();

	return true;
}


