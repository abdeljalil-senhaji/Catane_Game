#include "examplewindow.h"
#include <gtkmm.h>
#include <cairo/cairo.h>
#include <cairomm/context.h>
#include <cairomm/surface.h>

constexpr int DEFAULT_WIDTH = 500;
constexpr int DEFAULT_HEIGHT = 500;

// DrawHelper here ...
// MyWindow here ...


int main(int argc, char *argv[])
{
    auto app = Gtk::Application::create(argc, argv, "org.gtkmm.examples.base");
  
    MyWindow window;
  
    return app->run(window);
}