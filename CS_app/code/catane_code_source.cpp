#include "catane_header.h"
#include <cairomm/context.h>
#include <gdkmm/general.h> // set_source_pixbuf()
#include <glibmm/fileutils.h>
#include <iostream>
#include <gtkmm/window.h>



///////////////////////////////////////// classe fenetre principal /////////////////////////////////////////////



Fenetre::Fenetre()
{
  //Sets the border width of the window.
  set_title("Game CATANE"); //titre de l'interface
  set_icon_from_file("gtk.png");
  //set_border_width(10);
  set_position(Gtk::WIN_POS_CENTER);
  resize(1000, 600);
  set_border_width(5);
  this->add(welcome);
}
 //destructeur
Fenetre::~Fenetre()
{

}

////////////////////////////////// classe image-dessin ///////////////////////////////////////////

MyArea::MyArea()
{
  // The fractal image.
  m_image = Gdk::Pixbuf::create_from_file("Board.png");
  m_image = m_image->scale_simple(m_image->get_width()*0.15, (m_image->get_height()*0.15), Gdk::INTERP_BILINEAR);
}


// methode pour le reglage de l'image :
bool MyArea::on_draw(const Cairo::RefPtr<Cairo::Context>& cr)
{
  //Gtk::Allocation allocation = get_allocation();
  //const int width = allocation.get_width();
  //const int height = allocation.get_height();
  Gdk::Cairo::set_source_pixbuf(cr, m_image,350, 60);
  cr->save();
  cr->rectangle(0, 0, 1000, 700);
  cr->fill();
  cr->restore();
  return true;
}
 //destructeur

MyArea::~MyArea()
{
}


////////////////////////////////////// classe grid ///////////////////////////////////////////////////


MyGrid::MyGrid()
{
    // Clean widgets
  for (Widget *element : this->get_children ())
      this->remove (*element);

  // set_title("Game CATANE"); //titre de l'interface
  // set_icon_from_file("gtk.png");
  // set_border_width(5);
  // set_position(Gtk::WIN_POS_CENTER);
  // resize(1300, 900);
  font.set_size(16000);
  font.set_family("Arial");
  // font2.set_size(13000);
  // font2.set_family("Arial");
  this->set_row_spacing(10);
  nextButton.override_font(font);
  nextButton.set_label("start Game");
  nextButton.signal_clicked().connect(sigc::mem_fun(*this,
                                                    &MyGrid::Page2));
  message.set_label("Welcome on the Catane");
  message.override_font(font);
  nextButton.set_size_request(100,50);
  Page1(); 
}


/*
  Methode d'affichage de la premiere page pour commancer le jeu
*/

void MyGrid::Page1(){
    /**
     *  Display first page, with catane cover and the create character button
     */
    // Clean widgets
    for (Widget *element : this->get_children ())
        this->remove (*element);

    cover.set("Catan-3D.jpg");
    //cover.set("catane.png");

    this->attach(message, 0, 0, 1, 1);
    this->attach(cover,0,1,1,1);
    this->attach(nextButton,0,2,1,1);
  
    // This packs the button into the Window (a container);
    this->show_all();
}


/*
  methode page2 pour l'affechage de la deuxieme grid ou il ya le plateau du jeu.
*/

void MyGrid::Page2()
{
  // Clean widgets
  for (Widget *element : this->get_children ())
      this->remove (*element);

  //font2.set_style("Game CATANE"); //titre de l'interface
  //font2.set_icon_from_file("gtk.png");
  //font2.set_border_width(5);
  //font2.set_variations(Gtk::WIN_POS_CENTER);
  //font2.set_size(16000);
  font.set_family("Arial");
    // Create barre menu : 
  menuFiles.set_label("Setting_game");
  menuBar.append(menuFiles);
  // Create a sub menu in files
  menuFiles.set_submenu(subMenuFiles);
  open.set_label("OPEN");
  subMenuFiles.append(open);
  close.set_label("CLOSE");
  subMenuFiles.append(close);
  subMenuFiles.append(hline); // Add a separator
  quit.set_label("QUIT");
  subMenuFiles.append(quit);
  // ::: Create the event for MenuItem :::
  open.signal_activate().connect(sigc::mem_fun(*this, &MyGrid::Page1));
  quit.signal_activate().connect(sigc::ptr_fun(&Gtk::Main::quit));
  menuEdit.set_label("Game");
  menuBar.append(menuEdit);


  // Vbox de la barre menu :
  menuLayout.pack_start(menuBar, Gtk::PACK_SHRINK); //nous voulions que tous les widgets aient la même taille.
  mainGrid.attach(menuLayout,0,0,1,1);

  // le vbox pour mettre l'image : 
  board_box.add(obj1);
  //la taille du vbox ou il y a la photo 
  board_box.set_size_request(1000,700);
  mainGrid.attach(board_box, 0,1,1,1);
  //board_box.set_size_request(1000,900);
  mainGrid.set_size_request(1000,800);


  // les Vbox pour les 4 jours mettre 


  

  // Show Fenetre itens
  //this->set_row_spacing(5);
  show_all();
  add(mainGrid);
  show_all_children(); 

}




// tkharbi9aaa
void MyGrid::on_action1_event()
{
  std::cout << "A menu item was selected." << std::endl;
}


// Destructeur

MyGrid::~MyGrid()
{
}

