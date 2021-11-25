#include "mini_projet.h"
#include <map> 
#include <gtkmm/application.h>


int main(int argc, char *argv[])
{
    auto app = Gtk::Application::create(argc, argv);
    ExampleWindow window;

   app->run(window);
   
    return 0;
        
   

}
