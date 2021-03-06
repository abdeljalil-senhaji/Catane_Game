#include "catane_header.h"


///////////////////////////////////////// main window class /////////////////////////////////////////////


//------------ Window class constructor ----------------//

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


//------------ Window class destructor ----------------//
Fenetre::~Fenetre()
{
}



////////////////////////////////// class image drawing ///////////////////////////////////////////

//------------ constructor class MyArea (drawing)----------------//

MyArea::MyArea(MyGrid & parent_win)  : parent(parent_win)
{
  
  // Shelf image storage 
  m_image = Gdk::Pixbuf::create_from_file("images/plateau.png", 3650, 3650);
  // Image scale adjustment
  m_image = m_image->scale_simple(m_image->get_width()*0.15, (m_image->get_height()*0.15), Gdk::INTERP_BILINEAR);

  // Gamer 1
  // Road image storage
  route1_image = Gdk::Pixbuf::create_from_file("images/Route_Bleue.png");
  // Image scale adjustment
  route1_image = route1_image->scale_simple(route1_image->get_width()*0.5, (route1_image->get_height()*0.5), Gdk::INTERP_BILINEAR);
 
  // House image storage  
  maison1_image = Gdk::Pixbuf::create_from_file("images/Maison_Bleue.png");
  // Image scale adjustment
  maison1_image = maison1_image->scale_simple(maison1_image->get_width()*0.5, (maison1_image->get_height()*0.5), Gdk::INTERP_BILINEAR);
  
  // Image storage of the colony
  colonie1_image = Gdk::Pixbuf::create_from_file("images/Colonie_Bleue.png");
  // Image scale adjustment
  colonie1_image = colonie1_image->scale_simple(colonie1_image->get_width()*0.5, (colonie1_image->get_height()*0.5), Gdk::INTERP_BILINEAR);
  
  //Gamer 2

  // Road image storage
  route2_image = Gdk::Pixbuf::create_from_file("images/Route_Marron.png");
  // Image scale adjustment
  route2_image = route2_image->scale_simple(route2_image->get_width()*0.4, (route2_image->get_height()*0.4), Gdk::INTERP_BILINEAR);
  
  // House image storage 
  maison2_image = Gdk::Pixbuf::create_from_file("images/Maison_Marron.png");
  // Image scale adjustment
  maison2_image = maison2_image->scale_simple(maison2_image->get_width()*0.5, (maison2_image->get_height()*0.5), Gdk::INTERP_BILINEAR);

  // Image storage of the colony
  colonie2_image = Gdk::Pixbuf::create_from_file("images/Colonie_Marron.png");
  // Image scale adjustment
  colonie2_image = colonie2_image->scale_simple(colonie2_image->get_width()*0.4, (colonie2_image->get_height()*0.4), Gdk::INTERP_BILINEAR);
  
  if (m_image) {
        this->signal_draw().connect(sigc::mem_fun(*this, &MyArea::on_draw));}
        // Set masks for mouse events
        add_events(Gdk::BUTTON_PRESS_MASK);
        //startvalues
        first_click=false;
        second_click=false;
}




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
          first_click=true;
          queue_draw();

    //Gamer 1
    // Add a condition when the button is activated:

    if (parent.get_clicked_route() == true)
    {
      X.push_back(event->x);
      Y.push_back(event->y);
      parent.set_clicked_route(false);
    }

    if (parent.get_clicked_maison() == true)
    {
      X1.push_back(event->x);
      Y1.push_back(event->y);
      parent.set_clicked_maison(false);
    }
    
    if (parent.get_clicked_colonie() == true)
    {
      X2.push_back(event->x);
      Y2.push_back(event->y);
      parent.set_clicked_colonie(false);
    }

    //Gmaer 2 : 

    if (parent.get_clicked_route2() == true)
    {
      X3.push_back(event->x);
      Y3.push_back(event->y);
      parent.set_clicked_route2(false);
    }

    if (parent.get_clicked_maison2() == true)
    {
      X4.push_back(event->x);
      Y4.push_back(event->y);
      parent.set_clicked_maison2(false);
    }
    
    if (parent.get_clicked_colonie2() == true)
    {
      X5.push_back(event->x);
      Y5.push_back(event->y);
      parent.set_clicked_colonie2(false);
    }
    
  }
  // The event has been handled.
    return true;
}





// method for picture adjustment:
bool MyArea::on_draw(const Cairo::RefPtr<Cairo::Context>& cr)
{
  
  std::cout << "Coordonner click" << std::endl;
  if (m_image) {
    cr->save();
    Gdk::Cairo::set_source_pixbuf(cr, m_image, 160, 0);
    cr->rectangle(0, 0, get_width(), get_height());
    cr->fill();
    cr->restore();
  }
  // add tiles randomly using the rand method

  std::vector<int> T ={2,10,7,3,11,5,6,7,11,3,6,5,6,2,10,3,11,8,7,2,6,9,10,4,11,6,7,8,10};
  for (int i=0, j=0 ; i<X_tuille.size() ,j <T.size();i++ , j++ )
  {
    cr->save();
    int num = rand() % 10 +2;
  
    tuile_image = Gdk::Pixbuf::create_from_file("images/"+std::__cxx11::to_string(T[j])+".png");
    tuile_image = tuile_image->scale_simple(tuile_image->get_width()*0.35, (tuile_image->get_height()*0.35), Gdk::INTERP_BILINEAR);
    Gdk::Cairo::set_source_pixbuf(cr, tuile_image, X_tuille[i]-14, Y_tuille[i]-14);
  
    cr->rectangle(0, 0, get_width(), get_height()); 
    cr->fill();
    cr->restore();
  }

  // Loop to avoid image-to-image overlap and ensure the correct location of the image

  //Gamer 1

  for (int i=0 ; i<X.size();i++ )
    {

    if (route1_image) {
    cr->save();
    Gdk::Cairo::set_source_pixbuf(cr, route1_image, X[i]-10, Y[i]-10);
    cr->rectangle(0, 0, get_width(), get_height()); 
    cr->fill();
    cr->restore();}
    }

  for (int i=0 ; i<X1.size();i++ )
    {
    if (maison1_image) {
    cr->save();
    Gdk::Cairo::set_source_pixbuf(cr, maison1_image, X1[i]-10, Y1[i]-10);
    cr->rectangle(0, 0, get_width(), get_height()); 
    cr->fill();
    cr->restore();}
    } 
     
  for (int i=0 ; i<X2.size();i++ )
    {
    if (colonie1_image) {
    cr->save();
    Gdk::Cairo::set_source_pixbuf(cr, colonie1_image, X2[i]-10, Y2[i]-10);
    cr->rectangle(0, 0, get_width(), get_height()); 
    cr->fill();
    cr->restore();}
    }
  
  // gamar 2 :

  for (int i=0 ; i<X3.size();i++ )
    { 
    if (route2_image) {
    cr->save();
    Gdk::Cairo::set_source_pixbuf(cr, route2_image, X3[i]-10, Y3[i]-10);
    cr->rectangle(0, 0, get_width(), get_height()); 
    cr->fill();
    cr->restore();}
    }

  for (int i=0 ; i<X4.size();i++ )
    {
    if (maison2_image) {
    cr->save();
    Gdk::Cairo::set_source_pixbuf(cr, maison2_image, X4[i]-10, Y4[i]-10);
    cr->rectangle(0, 0, get_width(), get_height()); 
    cr->fill();
    cr->restore();}
    }
    
  for (int i=0 ; i<X5.size();i++ )
    {
    if (colonie2_image) {
    cr->save();
    Gdk::Cairo::set_source_pixbuf(cr, colonie2_image, X5[i]-10, Y5[i]-10);
    cr->rectangle(0, 0, get_width(), get_height()); 
    cr->fill();
    cr->restore();}
    }

    


  return false;
}




//------------ deconstructeur class MyArea (dessin)----------------//

MyArea::~MyArea()
{
}




////////////////////////////////////// class grid ///////////////////////////////////////////////////



/**
  * Grid constructor, will set the different fonts, set parameters for the first page, connect all signals
*/

MyGrid::MyGrid() : objArea(*this)
{
    // Clean widgets
  for (Widget *element : this->get_children ())
      this->remove (*element);

  font.set_size(17000);
  font.set_family("Arial");
  this->set_row_spacing(5);
  nextButton.override_font(font);
  nextButton.set_label("start Game");
  nextButton.signal_clicked().connect(sigc::mem_fun(*this, &MyGrid::Page2));
  message.set_label("Welcome on the Catane");
  message.override_font(font);
  nextButton.set_size_request(100,50);
  Page1(); 
}



/**
  *  Display first page, with Vampire cover and the create character button
*/

void MyGrid::Page1(){
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




//----------------------  Gamer 1  ------------------------//
//------------ Method for the button gamer 1 who builds the road -------------//

void MyGrid::on_button_place_route()
{
  this->set_clicked_route(true);
}

void MyGrid::set_clicked_route(bool N_val)
{
  this->clicked_route = N_val; //road
}

bool MyGrid::get_clicked_route()
{
    return clicked_route ;
}




//------------ Method for the gamer button 1 that builds the house -------------//

void MyGrid::on_button_place_maison()
{
  this->set_clicked_maison(true);
}

void MyGrid::set_clicked_maison(bool N_val)
{
  this->clicked_maison = N_val; //house
}

bool MyGrid::get_clicked_maison()
{
    return clicked_maison ;
}





//////------------ Method for the gamer button 1 that builds the colony -------------//////



void MyGrid::on_button_place_colonie()
{
  this->set_clicked_colonie(true);
}

void MyGrid::set_clicked_colonie(bool N_val)
{
  this->clicked_colonie = N_val; //colony
}

bool MyGrid::get_clicked_colonie()
{
    return clicked_colonie ;
}





//----------------------  Gamer 2  ------------------------//

//------------ Method for the gamer button 2 that builds the  road -------------//

void MyGrid::on_button_place_route2()
{
  this->set_clicked_route2(true);
}

void MyGrid::set_clicked_route2(bool N_val)
{
  this->clicked_route2 = N_val; 
}

bool MyGrid::get_clicked_route2()
{
    return clicked_route2 ;
}






//------------ Method for the gamer button 2 that builds the house -------------//

void MyGrid::on_button_place_maison2()
{
  this->set_clicked_maison2(true);
}

void MyGrid::set_clicked_maison2(bool N_val)
{
  this->clicked_maison2 = N_val; 
}

bool MyGrid::get_clicked_maison2()
{
    return clicked_maison2 ;
}





//////------------ Method for the gamer button 2 that builds the colony -------------//////




void MyGrid::on_button_place_colonie2()
{
  this->set_clicked_colonie2(true);
}

void MyGrid::set_clicked_colonie2(bool N_val)
{
  this->clicked_colonie2 = N_val; 
}

bool MyGrid::get_clicked_colonie2()
{
    return clicked_colonie2 ;
}




/**
  * Initialization of page 2.create the labels, connect the buttons, and use the parser to fill in the menubar 
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
    open.set_label("Rules-Game-Catane");
    subMenuFiles.append(open);
    close.set_label("Concept-Catane");
    subMenuFiles.append(close);
    subMenuFiles.append(hline); // Add a separator
    quit.set_label("QUIT");
    subMenuFiles.append(quit);

    //  we call the instance of the Myarea class
    close.signal_activate().connect(sigc::mem_fun(*this, &MyGrid::on_button_info_clicked2));
    open.signal_activate().connect(sigc::mem_fun(*this, &MyGrid::on_button_info_clicked));
    quit.signal_activate().connect(sigc::ptr_fun(&Gtk::Main::quit));
    menuLayout.pack_start(menuBar, Gtk::PACK_SHRINK); //we wanted all widgets to be the same size.

    menuLayout.set_hexpand(true);
    this->attach(menuLayout,0, 0, 1, 1);

    ////-----Gamer 1-----////

    etiquette.set_text("Gamer_1");
    etiquette.set_justify(Gtk::JUSTIFY_RIGHT);
    gridGame1.attach(etiquette, 0, 1, 1, 1);
  

    buttonRoute.add_label("Road");
    buttonRoute.signal_clicked().connect(sigc::mem_fun(*this, &MyGrid::on_button_place_route));
    gridGame1.attach(buttonRoute, 0, 2, 1, 1);
   

    buttonHouse.add_label("House");
    buttonHouse.signal_clicked().connect(sigc::mem_fun(*this, &MyGrid::on_button_place_maison));
    gridGame1.attach(buttonHouse, 0,3, 1, 1);

    

    buttonClan.add_label("Clan");
    buttonClan.signal_clicked().connect(sigc::mem_fun(*this, &MyGrid::on_button_place_colonie));
    gridGame1.attach(buttonClan, 0, 4, 1, 1);
    

    gridGame1.set_row_spacing(2);
    gridGame1.set_border_width(2);
    this->attach(gridGame1, 0, 1, 1, 1);
    

     ////-----Gamer 2------////


    etiquette1.set_text("Gamer_2");
    etiquette1.set_justify(Gtk::JUSTIFY_RIGHT);
    gridGame2.attach(etiquette1, 0, 1, 1, 1);

    buttonRoute1.add_label("Road");
    buttonRoute1.signal_clicked().connect(sigc::mem_fun(*this, &MyGrid::on_button_place_route2));
    gridGame2.attach(buttonRoute1, 0, 2, 1, 1);
  
    buttonHouse1.add_label("House");
    buttonHouse1.signal_clicked().connect(sigc::mem_fun(*this, &MyGrid::on_button_place_maison2));
    gridGame2.attach(buttonHouse1, 0, 3, 1, 1);
    
    buttonClan1.add_label("Clan");
    buttonClan1.signal_clicked().connect(sigc::mem_fun(*this, &MyGrid::on_button_place_colonie2));
    gridGame2.attach(buttonClan1, 0, 4, 1, 1);
    
    gridGame2.set_row_spacing(2);
    gridGame2.set_border_width(2);
    this->attach(gridGame2, 2, 1, 1, 1);    
    

    ////-------- Dice --------////

    LabelDice.set_text("Dice game :");
    LabelDice.set_justify(Gtk::JUSTIFY_RIGHT);
    LabelDice.set_text("Dice game is "+ std::__cxx11::to_string(2*(rand()%6+1)));

    gridDe.attach(LabelDice, 0, 0, 1, 1);

    buttonDes.add_label("DICE");
    buttonDes.signal_clicked().connect(sigc::mem_fun(*this,&MyGrid::lancerDe));
    gridDe.attach(buttonDes, 0, 1, 1, 1);



    ////---- Next part game ----////

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
    imageBox.add(objArea);
    m_Frame.add(imageBox);
    m_Frame.set_hexpand(true);
    this->attach(m_Frame, 1, 5, 1,1);


    /////-------images resource-------/////

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


//////---------- Method for rolling dice ----------//////

void MyGrid::lancerDe() {
	// generates the sum of two random values 
  LabelDice.set_text("Dice game is "+ std::__cxx11::to_string((rand()%6+1) + (rand()%6+1)));
}



/////-------- Information message ---------/////

void MyGrid::on_button_info_clicked()
{
  Gtk::Window f;
  Gtk::MessageDialog dialog(f, "This is an INFO Catane Rules");
  dialog.set_secondary_text(
    " - Tous les joueurs poss??dant une colonie ou une ville sur une intersection touchant une tuile qui produit des ressources re??oivent : 1 carte de cette ressource par colonie et 2 cartes par ville." 
    " - Pour construire des routes, des colonies et des villes il est n??cessaire d???avoir les combinaisons de cartes Ressource (voir carte Co??t de Construction). Les cartes Ressource correspondantes au co??t de construction et utilis??es retournent dans les diff??rentes piles. "
    " - Des routes peuvent ??tre construites sur les chemins. Sur chaque Chemin (*) on ne peut construire qu???une seule route. "
    " - Une route peut uniquement ??tre construite sur une intersection voisine ??: une route, une colonie ou une ville de la m??me couleur. "
    " - Une colonie doit ??tre construite sur une intersection, par laquelle arrive au moins une route de la couleur du joueur."
    " - Une colonie ne peut ??tre construite que sur une Intersection (*) dont aucune des 3 intersections voisines ne poss??de de colonie ou de ville (quel que soit leur propri??taire"
    );
  dialog.run();
}

void MyGrid::on_button_info_clicked2()
{
  Gtk::Window f;
  Gtk::MessageDialog dialog(f, "Colonne de Catane ?");
  dialog.set_secondary_text("Les Colons de Catane (en allemand : Die Siedler von Catan), Les Colons de Katane1, Catane2 ou Catan3, est un jeu de societe de Klaus Teuber, edite en France en 1995 par Jeux Descartes, repris en 2002 par Tilsit Editions, puis en 2006 par la societe quebecoise Filosofia."
    );
  dialog.run();
}





////------- Destructive --------////

MyGrid::~MyGrid()
{
}


