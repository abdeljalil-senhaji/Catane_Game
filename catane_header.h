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
  std::vector<int> X,Y;    //route
  std::vector<int> X1,Y1;  //maison
  std::vector<int> X2,Y2;  //colonie
  //Gamer2
  std::vector<int> X3,Y3;    //route2
  std::vector<int> X4,Y4;  //maison2
  std::vector<int> X5,Y5;  //colonie2

  //Place tuilles : 
  std::vector<int> X_tuille{227, 226, 363, 501};
  std::vector<int> Y_tuille{180, 342, 263, 342};
  // appel par reffernce de la classe parent Mygrid 
  MyGrid & parent ; 
};



/**
 * Main grid ajouter a la window.
*/


class MyGrid : public Gtk::Grid
{
  public :


    MyGrid(); //constructeur
    virtual ~MyGrid(); //destructeur
    void Page2();
    void Page1();
    void  lancerDe();
    void on_button_info_clicked();
    void on_button_info_clicked2();

    // Gamer 1
    void on_button_place_route();
    void on_button_place_maison();
    void on_button_place_colonie();

    void set_clicked_route(bool N_val);
    bool get_clicked_route();

    void set_clicked_maison(bool N_val);
    bool get_clicked_maison();

    void set_clicked_colonie(bool N_val);
    bool get_clicked_colonie();

    // Gamer 2

    void on_button_place_route2();
    void on_button_place_maison2();
    void on_button_place_colonie2();

    void set_clicked_route2(bool N_val);
    bool get_clicked_route2();

    void set_clicked_maison2(bool N_val);
    bool get_clicked_maison2();

    void set_clicked_colonie2(bool N_val);
    bool get_clicked_colonie2();



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


    bool clicked_route = false;
    bool clicked_maison = false; 
    bool clicked_colonie = false;
    // Gamer 2 :
    bool clicked_route2 = false;
    bool clicked_maison2 = false; 
    bool clicked_colonie2 = false;
    MyArea objArea;

};

////////////////////////// class de la fenêtre principale ///////////////////////////////////////

/**
  * Fenetre principale contenant la grid
*/

class Fenetre : public Gtk::Window

{

public:
    Fenetre();
    virtual ~Fenetre(); // Setup window

protected:
    //Member widgets:
    
    MyGrid welcome;

};


#endif //CATANE_PROJECT_H


