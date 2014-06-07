
#include <iostream>
#include <gtkmm/window.h>
#include "World.h"


int main (int argc, char** argv)
{

	Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv);

	Glib::RefPtr<Gdk::Screen> screen = Gdk::Screen::get_default();
	int width = 900; //screen->get_width();
	int height = 600; //screen->get_height(); 

	Gtk::Window window;
	window.set_default_size(width, height);
	//window.fullscreen();
        
	g3::World world (width, height);
	window.add(world);
	world.show();

	return app->run(window);
}
