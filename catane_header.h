#ifndef CATANE_PROJECT_H
#define CATANE_PROJECT_H
#include <gtkmm.h>

#include <iostream>
#include <string>
#include <vector>
#include <iostream>
#include <cairomm/context.h>
#include <gdkmm/general.h> // set_source_pixbuf()
#include <glibmm/fileutils.h>
#include <gtkmm/window.h>
#include <cairomm/surface.h>




////////////////////////// class de dessin ///////////////////////////////////////


////////////////////////// class de ménu grid ///////////////////////////////////////


class MyGrid ;

class MyArea : public Gtk::DrawingArea
{
public:
  MyArea(MyGrid & parent_win  );
  virtual ~MyArea();
  void switch_to_circle();
  void switch_to_rectangle();
  void fill_tokens();


protected:
  //Override default signal handler:
 
  bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr);

  // Override mouse events
  bool on_button_press_event(GdkEventButton * event);

  // varible stocker l'image utilise Glib
  Glib::RefPtr<Gdk::Pixbuf> m_image , route1_image, route2_image, maison1_image, maison2_image, colonie1_image, colonie2_image;

  double beginPoint_x, beginPoint_y, endPoint_x, endPoint_y, lineWidth, width, height;

  bool isDrawRectangle;

  //two coordinates
  int x1;
  int y1;
  int x2;
  int y2;
  //two bools for the clicks
  bool first_click;
  bool second_click;

  private:
  std::vector<int> X,Y; 
  // appel par reffernce de la classe parent Mygrid 
  MyGrid & parent ; 
};



//class MyGrid : public Gtk::Grid, public Fenetre
class MyGrid : public Gtk::Grid
{
  public :
    MyGrid(); //constructeur
    virtual ~MyGrid(); //destructeur
    void Page2();
    void Page1();
    void  lancerDe();
    void on_button_info_clicked();

    void on_button_place_route();
    void on_button_place_maison();
    void on_button_place_colonie();

    void set_clicked(bool N_val);
    bool get_clicked();
  protected:
    Pango::FontDescription font, font1;
    /**** Page 1 ***/
    Gtk::Label message;
    Gtk::Image cover, imageBle, imageBois, imagePierre, imageMouton, imageBrique;
    Gtk::Button nextButton;

    //Signal handlers:
    bool on_eventbox_button_press(GdkEventButton* button_event);
    //Child widgets:
    Gtk::HBox buttonBox;
    Gtk::VBox menuLayout;
    Gtk::EventBox imageBox, eventBle, eventBois, eventMouton, eventBrique, eventPierre;
    Gtk::Button buttonDes, rectangleButton, circleButton, buttonRoute, buttonHouse, buttonClan, buttonRoute1, buttonHouse1, buttonClan1, buttonBuild;
    Gtk::MenuBar menuBar;
    Gtk::MenuItem menuFiles;
    Gtk::Menu subMenuFiles;
    Gtk::MenuItem open, close, quit;
    Gtk::SeparatorMenuItem hline;
    Gtk::MenuItem menuEdit;
    Gtk::Frame m_Frame, Frame_gamer2;
    Gtk::Label m_Label, etiquette, etiquette1, LabelRess, LabelDice, LabelBuild;
    Gtk::Grid mainGrid, gridGame1, gridGame2, gridDes, gridRessource, gridDe;
    

  private:
    bool clicked = false;
    MyArea objArea;

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
    //Signal handlers:
    


protected:
    //Member widgets:
    
    MyGrid welcome;



};


#endif //CATANE_PROJECT_H

