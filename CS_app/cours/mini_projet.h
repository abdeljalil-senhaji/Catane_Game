#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <gtkmm.h>


// The class mainwindow inherits from Gtk::Window
class mainwindow : public Gtk::Window
{
	// Constructor and destructor
public:    
	mainwindow();
	virtual             ~mainwindow();

protected:

	//Member widgets:
	Gtk::Image              image1;
	Gtk::Image              image2;
	Gtk::Button             buttonQuit;
	Gtk::Grid               mainGrid;
};


#endif // MAINWINDOW_H
