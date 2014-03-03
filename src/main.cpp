
#include <iostream>
#include <gtkmm/window.h>
#include "Screen.h"

using namespace std;
using namespace g3d;

int main (int argc, char** argv)
{

	Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv);

	Gtk::Window window;
	window.set_default_size(640, 480);
        
	Screen screen;
	window.add(screen);
	screen.show();

	return app->run(window);
}
