#include "mini_projet.h"
#include <iostream>


// Constructor of the main Window (build ui interface).
mainwindow::mainwindow()
{
	// Initialize the main window and hide the title bar
	this->set_border_width(10);

	// Load and display the image
	image1.set("Board.png");
	mainGrid.attach(image1,0,0,1,1);

	image2.set("gtk.png");
	mainGrid.attach(image2,1,1,2,2);

	// Add the Quit button
	buttonQuit.add_label("Quit");
	buttonQuit.signal_pressed().connect(sigc::mem_fun(*this,&mainwindow::close));
	mainGrid.attach(buttonQuit,0,3,3,1);

	// Display the main grid in the main window
	mainGrid.show_all();

	// Insert the grid in the main window
	add(mainGrid);
}


// Destructor of the class
mainwindow::~mainwindow()
{}
