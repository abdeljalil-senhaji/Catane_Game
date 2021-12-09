

//classe 2
class DrawingArea : public Gtk::DrawingArea
{
public:
    DrawingArea();

protected:
    // Override default signal handler:
    virtual bool on_draw(const Cairo::RefPtr<Cairo::Context> &cr);

    // Override mouse events
    bool on_button_press_event(GdkEventButton *event);

    //Override default signal handler:
    //virtual bool on_draw(const Cairo::RefPtr & cr);
        //Member widgets:

private:
    //display Pixbuf
    Glib::RefPtr<Gdk::Pixbuf> display;
    //Glib::RefPtr < Gdk::Pixbuf > image;

    //two coordinates
    int x1;
    int y1;
    int x2;
    int y2;
    //two bools for the clicks
    bool firstclick;
    bool secondclick;
};





















//---------------------------------------events-------------------------------------------------------//

void Dessin::updateRoute(GdkEventButton *event)
{
	// Check if the event is a left(1) button click.
	if ((event->type == GDK_BUTTON_PRESS) && (event->button == 1))
	{
		// check whether this is the first click
		if (!firstclick && !secondclick)
		{
			// the first coordinate
			x1 = event->x;
			y1 = event->y;

			firstclick = true;
		}
		// check whether this is the second click, and not on the same point as the previous
		if (firstclick && !secondclick && (int)event->x != x1 && (int)event->y != y1)
		{
			// the second coordinate
			x2 = event->x;
			y2 = event->y;
			secondclick = true;
			// refresh the screen
		}

		// check whether it was clicked two times in order to save values
		if (firstclick && secondclick)
		{
			
			vx1.push_back(x1);
			vy1.push_back(y1);
			vx2.push_back(x2);
			vy2.push_back(y2);
			// reinitialize firstclick and secondclick to false and
			firstclick = false;
			secondclick = false;
			set_add_route_pressed(false);
			ReafficheDessin();
		}
		// The event has been handled.
	}
}

//---------------------------------------click in image-------------------------------------------------------//

//file.h

class ExampleWindow : public Gtk::Window //class de la fenêtre principale
{
public:
      void Page1();
      void Page2();
      ExampleWindow(); //constructeur
      virtual ~ExampleWindow(); //destructeur
protected:        
      //****** Page 2 ************/
      Gtk::Label  m_Label_2, m_Label_3;
      //Gtk:: ComboBoxText nature;
      Gtk::Button m_button, submit_button;
      Gtk::Grid mainGrid1, mainGrid2 ;
      Pango::FontDescription myfont, myfont2;
      /**** Page 1 ***/
      Gtk::Label message;
      Gtk::Image coverCatane;
      Gtk::Button nextButton;
};

//file.cpp


ExampleWindow::ExampleWindow() //
{
    myfont.set_size(16000);
    myfont.set_family("Arial");
    myfont2.set_size(13000);
    myfont2.set_family("Arial");
    //this->set_row_spacing(10);
    nextButton.override_font(myfont);
    nextButton.set_label("Catane game over.");
    //nextButton.signal_clicked().connect(sigc::mem_fun(*this,&ExampleWindow::Page2));
    message.set_label("Welcome on the Catane Game.");
    message.override_font(myfont);
    nextButton.set_size_request(100,50);
    //Page1();

}

ExampleWindow::~ExampleWindow() //destructeur
{
}
void ExampleWindow::Page1()
{
    /*
     Display first page
    */
    coverCatane.set("catane.png");
    //this->attach(message, 0, 0, 1, 1);
    mainGrid2.attach(coverCatane,0,1,1,1);
    mainGrid2.attach(nextButton,0,2,2,1);
    // This packs the button into the Window (a container);
    show_all();
}
void ExampleWindow::Page2() //
{
	// set_title("Catane Interface"); // Titre de l'interface
    // set_border_width(5);
    // set_position(Gtk::WIN_POS_CENTER);
    // resize(800, 500); 
    // :
    // mainGrid1.override_background_color (	Gdk::RGBA("white"), Gtk::STATE_FLAG_NORMAL );
	// m_Label_2.override_color (Gdk::RGBA("black"), Gtk::STATE_FLAG_NORMAL);
    // m_Label_3.override_color (Gdk::RGBA("black"), Gtk::STATE_FLAG_NORMAL);
	// //  : 
    m_Label_3.set_markup(" <b> Catane </b>");
    m_Label_3.set_alignment(Gtk::ALIGN_CENTER);
    mainGrid1.attach(m_Label_3, 5, 0, 5, 1);
    // :
    //Gtk::MessageDialog dialog(*this, "Warning");    //pop-up qui s'affiche si la condition n'est pas respectée
    //dialog.set_secondary_text("hhhhhhhhhhhhhh");
    //dialog.run();       
    //submit_button.add_label("Catane Game"); //bouton de validation
    //submit_button.signal_clicked().connect(sigc::mem_fun(*this, &ExampleWindow::dialog));
    //mainGrid1.attach(submit_button, 10, 55, 5, 1);
    //Selector.append_page(mainGrid1, "Start Game");
    //ajout du note book à la fenetre 
    //show_all_children();

}



////////////////////////file_main.cpp


int main(int argc, char *argv[])
{
    auto app = Gtk::Application::create(argc, argv);
    ExampleWindow window;

    app->run(window);
   
    return 0;
}


/*--------------------------------------------------------------------------------------------*/


class my_window : public Gtk::Window
{
public:
	my_window();
	virtual ~my_window(){};
	void button_add_house();
	void button_add_path();
	void button_add_route();

protected:
	Dessin dessin;
	Gtk::VBox mainLayout, board_box, buttons_box;
	Gtk::Label m_label;
	Gtk::Frame board_Frame, action_buttons_frame;
	Gtk::HButtonBox buttons_Hbox;
	Gtk::Grid mainGrid, buttons_Grid;
	Gtk::Button button_house, button_route;
	Gtk::MenuBar menuBar;
	Gtk::MenuItem menuFiles;
	Gtk::Menu subMenuFiles;
	Gtk::MenuItem open, close, quit;
	Gtk::SeparatorMenuItem hline;
	Gtk::MenuItem menuEdit;

private:
	void set_my_menu();
};


/////// pour image :

Gdk::Cairo::set_source_pixbuf(cr, pic_board, board_x, board_y); //(width, hight)
	cr->save();
	cr->rectangle(0, 0, board_width, board_height); // on ne peut pas suprimer
	cr->fill();
	cr->restore();

/**********************************************************************************************/


/*---------board box---------------*/
        board_Frame.set_label("Game Board");
        board_Frame.add(dessin);    
        board_box.set_size_request(1000, 900); // (width,hight) (1000,900)
        board_box.add(board_Frame);
