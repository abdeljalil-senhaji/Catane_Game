#include "catane_header.h"
#include <gtkmm.h>
#include <iostream>
#include <gtkmm/main.h>
#include <gtkmm/window.h>


int main (int argc, char *argv[])
{
    auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");

    Fenetre fenetre;

    //Shows the window and returns when it is closed.
    return app->run(fenetre);
}
