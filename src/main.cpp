
#include <iostream>
#include <gtkmm/window.h>
#include "Screen.h"

using namespace std;
using namespace g3;

int main (int argc, char** argv)
{

	Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv);

	Gtk::Window window;
	const int width = 640;
	const int height = 480;
	window.set_default_size(width, height);
        
	Screen screen (width, height);
	window.add(screen);
	screen.show();

	return app->run(window);
}
