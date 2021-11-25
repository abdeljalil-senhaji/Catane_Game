#ifndef CATANE_PROJECT_H
#define CATANE_PROJECT_H
#include <gtkmm.h>
#include <iostream>
#include <gtkmm/drawingarea.h>
#include <gdkmm/pixbuf.h>
#include <gtkmm/window.h> 
#include <pangomm.h>
#include <string>
#include <map>
#include <vector>





////////////////////////// class de dessin ///////////////////////////////////////




class MyArea : public Gtk::DrawingArea
{
public:
  MyArea();
  virtual ~MyArea();
  //Override default signal handler:
  bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr);
  Glib::RefPtr<Gdk::Pixbuf> m_image; 
};



////////////////////////// class de ménu grid ///////////////////////////////////////


class MyGrid : public Gtk::Grid 
{
public :
  MyGrid(); //constructeur

  virtual ~MyGrid(); //destructeur
  void Page2();
  void Page1();
  

protected:
  Pango::FontDescription font, font1;
  /**** Page 1 ***/
  Gtk::Label message;
  Gtk::Image cover;
  Gtk::Button nextButton;
  MyArea obj1;
  //Box pour mettre l'image : 
  Gtk::Box Box1;
  // bare de menu et event
  void on_action1_event();
  //Child widgets:
  Gtk::VBox board_box, board_box2, menuLayout;
  Gtk::MenuBar menuBar;
  Gtk::MenuItem menuFiles;
  Gtk::Menu subMenuFiles;
  Gtk::MenuItem open, close, quit;
  Gtk::SeparatorMenuItem hline;
  Gtk::MenuItem menuEdit;
  Gtk::Grid mainGrid;

};


////////////////////////// class de la fenêtre principale ///////////////////////////////////////


class Fenetre : public Gtk::Window
        /**
         * Main window holding the grid
         */
{

public:
    Fenetre();
    virtual ~Fenetre(); // Setup window


protected:
    //Member widgets:
     MyGrid welcome;



};


#endif //CATANE_PROJECT_H


