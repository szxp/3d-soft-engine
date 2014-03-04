
#include <iostream>
#include <gtkmm/window.h>
#include "Screen.h"
#include "Vec3.h"
#include "Mat4.h"

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

	Mat4 mat {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
	std::cout << mat[14] << std::endl;

	return app->run(window);
}
