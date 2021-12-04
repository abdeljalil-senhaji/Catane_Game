#include "catane_header.h"
#include "logicGame.h"
#include <cairomm/context.h>
#include <gdkmm/general.h> // set_source_pixbuf()
#include <glibmm/fileutils.h>
#include <iostream>
#include <gtkmm/window.h>
#include <cairomm/surface.h>
using namespace std ;
#include <string>     // std::string, std::to_string


///////////////////////////////////////// classe fenetre principal /////////////////////////////////////////////



Fenetre::Fenetre()
{
  //Sets the border width of the window.
  set_title("Game CATANE"); //titre de l'interface
  set_icon_from_file("images/catane.png");
  //set_border_width(10);
  set_position(Gtk::WIN_POS_CENTER);
  resize(1000, 600);
  set_border_width(4);
  
  //add instance de la classe Mygrid
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
  m_image = Gdk::Pixbuf::create_from_file("images/plateau.png", 3650, 3650);
  m_image = m_image->scale_simple(m_image->get_width()*0.15, (m_image->get_height()*0.15), Gdk::INTERP_BILINEAR);
  if (m_image) {
        this->signal_draw().connect(sigc::mem_fun(*this, &MyArea::on_draw));}
  // Set masks for mouse events
  add_events(Gdk::BUTTON_PRESS_MASK);
  //startvalues
  firstclick=false;
  secondclick=false;
  //add_events(Gdk::BUTTON1_MOTION_MASK | Gdk::BUTTON_PRESS_MASK);
  
}





//   signal_button_press_event().connect([&](GdkEventButton *e) {
//       this->beginPoint_x = e->x;
//       this->beginPoint_y = e->y;
//       if(isDrawRectangle) {
//           this->signal_draw().connect(sigc::mem_fun(*this, &MyArea::draw_rectangle));
//           queue_draw();
//       }
//       else {
//           this->signal_draw().connect(sigc::mem_fun(*this, &MyArea::draw_circle));
//           queue_draw();
//       }
//       return true;
//   });

//   signal_motion_notify_event().connect([&](GdkEventMotion *e) {
//       this->endPoint_x = e->x;
//       this->endPoint_y = e->y;
//       width = endPoint_x - beginPoint_x;
//       height = endPoint_y - beginPoint_y;

//       if(isDrawRectangle) {
//           this->signal_draw().connect(sigc::mem_fun(*this, &MyArea::draw_rectangle));
//           queue_draw();
//       }
//       else {
//           this->signal_draw().connect(sigc::mem_fun(*this, &MyArea::draw_circle));
//           queue_draw();
//       }

//       return true;
//   });
  
// }

// Mouse button press event
bool MyArea::on_button_press_event(GdkEventButton *event)
{
  // Check if the event is a left(1) button click.
  if( (event->type == GDK_BUTTON_PRESS) && (event->button == 1) )
  {
      //check whether this is the first click
          //the first coordinate
          x1=event->x;
          std::cout << "Premiere coordonner \n" << x1 << std::endl;
          y1=event->y;
          std::cout << "Deuxieme coordonner \n" << y1 << std::endl;
          firstclick=true;
          queue_draw();
      // }
      
  }
  // The event has been handled.
    return true;
}

// methode pour le reglage de l'image :
bool MyArea::on_draw(const Cairo::RefPtr<Cairo::Context>& cr)
{
  std::cout << "signal img" << std::endl;
  if (m_image) {
    cr->save();
    Gdk::Cairo::set_source_pixbuf(cr, m_image, 160, 0);
    //Gdk::Cairo::set_source_pixbuf(cr, m_image);
    cr->rectangle(0, 0, get_width(), get_height());
    cr->fill();
    cr->restore();
  }
  return false;
}

// bool MyArea::draw_rectangle(const Cairo::RefPtr<::Cairo::Context> &cr) {
//     std::cout << "signal square" << std::endl;
//     cr->save();
//     cr->set_line_width(10);
//     cr->set_source_rgba(0., 0., 1., 1.);
//     cr->rectangle(beginPoint_x, beginPoint_y, width, height);
//     cr->stroke();
//     cr->save();
//     cr->restore();

//     return false;
// }

// bool MyArea::draw_circle(const Cairo::RefPtr<::Cairo::Context> &cr) {
//     std::cout << "signal square" << std::endl;

//     cr->save();
//     cr->set_line_width(10);
//     cr->set_source_rgba(0., 0., 1., 1.);
//     cr->arc(beginPoint_x, beginPoint_y, width, 0, 2 * M_PI);
//     cr->stroke();
//     cr->restore();

//     return false;
// }
// void MyArea::switch_to_circle() {
//     isDrawRectangle = false;

// }

// void MyArea::switch_to_rectangle() {
//     isDrawRectangle = true;
// }


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

  font.set_size(17000);
  font.set_family("Arial");
  this->set_row_spacing(5);
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

    cover.set("images/Catan-3D.jpg");
    

    this->attach(message, 0, 0, 1, 1);
    this->attach(cover, 0,1,1,1);
    this->attach(nextButton, 0,2,1,1);
  
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



    ////--------- Create barre menu ---------//// 
  
    menuFiles.set_label("GAME");
    menuBar.append(menuFiles);
    // // Create a sub menu in files
    menuFiles.set_submenu(subMenuFiles);
    open.set_label("OPEN");
    subMenuFiles.append(open);
    close.set_label("CLOSE");
    subMenuFiles.append(close);
    subMenuFiles.append(hline); // Add a separator
    quit.set_label("QUIT");
    subMenuFiles.append(quit);

    //on fait l'appel de l'instance de la classe Myarea
    close.signal_activate().connect(sigc::mem_fun(*this, &MyGrid::on_button_info_clicked));
    //
    open.signal_activate().connect(sigc::mem_fun(*this, &MyGrid::on_button_info_clicked));
    quit.signal_activate().connect(sigc::ptr_fun(&Gtk::Main::quit));
    menuLayout.pack_start(menuBar, Gtk::PACK_SHRINK); //nous voulions que tous les widgets aient la même taille.

    menuLayout.set_hexpand(true);
    this->attach(menuLayout,0, 0, 1, 1);

    ////-----Game1-----////

    etiquette.set_text("Gamer_1");
    etiquette.set_justify(Gtk::JUSTIFY_RIGHT);
    gridGame1.attach(etiquette, 0, 1, 1, 1);
  

    buttonRoute.add_label("Road");
    gridGame1.attach(buttonRoute, 0, 2, 1, 1);
   

    buttonHouse.add_label("House");
    gridGame1.attach(buttonHouse, 0,3, 1, 1);
    

    buttonClan.add_label("Clan");
    gridGame1.attach(buttonClan, 0, 4, 1, 1);
    

    gridGame1.set_row_spacing(2);
    gridGame1.set_border_width(2);
    this->attach(gridGame1, 0, 1, 1, 1);
    

     ////-----Gamer 2------////


    etiquette1.set_text("Gamer_2");
    etiquette1.set_justify(Gtk::JUSTIFY_RIGHT);
    gridGame2.attach(etiquette1, 0, 1, 1, 1);

    buttonRoute1.add_label("Road");
    gridGame2.attach(buttonRoute1, 0, 2, 1, 1);
  
    buttonHouse1.add_label("House");
    gridGame2.attach(buttonHouse1, 0, 3, 1, 1);
    
    buttonClan1.add_label("Clan");
    gridGame2.attach(buttonClan1, 0, 4, 1, 1);
    
    gridGame2.set_row_spacing(2);
    gridGame2.set_border_width(2);
    this->attach(gridGame2, 2, 1, 1, 1);    
    

    ////-------- Des --------////
   
    LabelDice.set_text("Dice game :");
    LabelDice.set_justify(Gtk::JUSTIFY_RIGHT);
    LabelDice.set_text("Dice game is "+ to_string(2*(rand()%6+1)));

    gridDe.attach(LabelDice, 0, 0, 1, 1);

    buttonDes.add_label("DICE");
    buttonDes.signal_clicked().connect(sigc::mem_fun(*this,&MyGrid::lancerDe));
    gridDe.attach(buttonDes, 0, 1, 1, 1);

    //// Next part game 
    LabelBuild.set_text("Build game");
    LabelBuild.set_justify(Gtk::JUSTIFY_RIGHT);
    gridDe.attach(LabelBuild, 1, 0, 1, 1);
    buttonBuild.add_label("Next Part Game");
    gridDe.attach(buttonBuild, 1, 1, 1, 1);

    gridDe.set_hexpand(true);
    gridDe.set_vexpand(true);
    gridDe.set_row_spacing(10);
    gridDe.set_column_spacing(250);
    gridDe.set_border_width(40);
    this->attach(gridDe, 1, 1, 1, 1);

  

    ////----- Plateau Image---------////

    imageBox.set_size_request(800,500);
    imageBox.add(obj1);
    m_Frame.add(imageBox);
    m_Frame.set_hexpand(true);
    

    this->attach(m_Frame, 1, 5, 1,1);
    //imageBox.set_size_request(100,580);
    // buttonBox.pack_start(rectangleButton);
    // buttonBox.pack_start(circleButton);
    // circleButton.signal_clicked().connect([&] {obj1.switch_to_circle();});
    // rectangleButton.signal_clicked().connect([&] {obj1.switch_to_rectangle();});
    // this->attach(buttonBox, 0,2,1,1);
    //this->set_size_request(1250,550);


   

    /////-------images resources-------/////

    LabelRess.set_text("Ressources ");
    LabelRess.set_justify(Gtk::JUSTIFY_RIGHT);
    gridRessource.attach(LabelRess, 0, 0, 1, 1);

    imageBle.set("images/Ble.png");
    eventBle.add(imageBle);
    gridRessource.attach(eventBle, 0, 1, 1, 1);

    imageBois.set("images/Bois.png");
    eventBois.add(imageBois);
    gridRessource.attach(eventBois, 0, 2, 1, 1);

    imageBrique.set("images/Brique.png");
    eventBrique.add(imageBrique);
    gridRessource.attach(eventBrique, 0, 3, 1, 1);


    imageMouton.set("images/Mouton.png");
    eventMouton.add(imageMouton);
    gridRessource.attach(eventMouton, 0, 4, 1, 1);

    imagePierre.set("images/Pierre.png");
    eventPierre.add(imagePierre);
    gridRessource.attach(eventPierre, 0, 5, 1, 1);


    gridRessource.set_row_spacing(5);
    gridRessource.set_border_width(20);
    gridRessource.set_hexpand(true);
    this->attach(gridRessource, 0, 5, 1, 1);


    ////----- Attach all------////

    this->override_background_color(Gdk::RGBA("#fceeee"));
    this->show_all();
    this->show_all_children(); 

}


//////---------- Methode pour le lancement de dés ----------//////

void MyGrid::lancerDe() {
	
  LabelDice.set_text("Dice game is "+ to_string((rand()%6+1) + (rand()%6+1)));
}

// tkharbi9aaa
void MyGrid::on_action1_event()
{
  std::cout << "A menu item was selected." << std::endl;
}



/////-------- Message d'information ---------/////

void MyGrid::on_button_info_clicked()
{
  Gtk::Window f;
  Gtk::MessageDialog dialog(f, "This is an INFO MessageDialog");
  dialog.set_secondary_text("And this is the secondary text that explains things.");
  dialog.run();
}



////------- Destructeur --------////

MyGrid::~MyGrid()
{
}


