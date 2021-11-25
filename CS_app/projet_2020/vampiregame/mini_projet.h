#ifndef myLibrairie_H_INCLUDED
#define myLibrairie_H_INCLUDED
#include <iostream>
#include <gtkmm.h>

#include <string.h>
#include <map>
#include <iterator> 
#include <vector> 
#include <fstream>


#include <gdkmm/pixbuf.h>
#include <gtkmm/drawingarea.h>




using namespace std;


class Dessin : public Gtk::DrawingArea //class Dessin qui va remplir la 1ere page spécéfique à l'attribution des pts
{ 
    public:
        Dessin(); //constructeur
        ~Dessin(); //destructeur
        bool on_draw(const Cairo::RefPtr<Cairo::Context>& ); //fonction qui remplie les pts dans la 1ere page
        void draw_text(const Cairo::RefPtr<Cairo::Context>& cr, int , int ,string); //fonction qui remplie la 1ere page avc du texte 



};
class Page2: public Gtk::DrawingArea  //class qui s'occupe de remplir la 2eme page
{

    public:
        Page2(); //constructeur 
        ~Page2(); //destructeur 
        bool on_draw(const Cairo::RefPtr<Cairo::Context>& );    //fonction qui remplie les pts dans la 2eme page
        void draw_text(const Cairo::RefPtr<Cairo::Context>& cr, int , int ,string);  //fonction qui remplie la 2eme page avc du texte 



};
class Page3: public Gtk::DrawingArea  //class qui s'occupe de remplir la 3eme page
{

    public:
        Page3(); //constructeur
        ~Page3(); //desctructeur
        bool on_draw(const Cairo::RefPtr<Cairo::Context>& );   //fonction qui remplie les pts dans la 3eme page
        void draw_text(const Cairo::RefPtr<Cairo::Context>& cr, int , int ,string);  //fonction qui remplie la 3eme page avc du texte 



};
class Page4: public Gtk::DrawingArea //class qui s'occupe de remplir la 4eme page
{

    public:
        Page4();  // constructeur 
        ~Page4();  //destructeur 
        bool on_draw(const Cairo::RefPtr<Cairo::Context>& );  // //fonction qui remplie les pts dans la 4eme page
        void draw_text(const Cairo::RefPtr<Cairo::Context>& cr, int , int ,string);  //fonction qui remplie la 4eme page avc du texte 



};
class ExampleWindow : public Gtk::Window //class de la fenêtre principale
{
public:
  ExampleWindow(); //constructeur

  virtual ~ExampleWindow(); //destructeur

protected:
        Dessin dessin;
        Page2 page2;
        Page3 page3;
        Page4 page4;

        //Child widgets:
        Gtk::Button start_button;
        void GetAllValues();
        void export_to_pdf();

        void on_button_clicked() ;
        void display_page2();
        Gtk::Box VBox1;
        Gtk::Box VBox2;
        Gtk::Box VBox3;
        Gtk::Label  abilities, advantages, attribut, m_Label_1, m_Label_2, m_Label_3,
         m_Label_4, m_Label_5, m_Label_6, m_Label_7,
         m_Label_8,m_Label_9 ,m_Label_10, m_Label_11,
         m_Label_12, m_Label_13, m_Label_14, m_Label_15,
         m_Label_16, m_Label_17, m_Label_18, m_Label_19,
         m_Label_20, m_Label_21, m_Label_22, m_Label_23,
        m_Label_24, m_Label_25, m_Label_26, m_Label_27,
        m_Label_28,m_Label_29 ,m_Label_30, m_Label_31,
        m_Label_32,m_Label_33 ,m_Label_34, m_Label_35,
        m_Label_36,m_Label_37 ,m_Label_38, m_Label_40,
        m_Label_41,m_Label_42 ,m_Label_43, m_Label_44,
        m_Label_45,m_Label_46 ,m_Label_47, m_Label_48;

        Gtk::ComboBoxText c;
        Gtk::ComboBoxText nature;
        Gtk::ComboBoxText attribute_physical;
        Gtk::ComboBoxText attribute_physical1;
        Gtk::ComboBoxText attribute_social;
        Gtk::ComboBoxText attribute_social1;
        Gtk::ComboBoxText attribute_social2;
        Gtk::ComboBoxText attribute_mental;
        Gtk::ComboBoxText abilities_talents;
        Gtk::ComboBoxText abilities_talents1;
        Gtk::ComboBoxText abilities_talents2;
        Gtk::ComboBoxText abilities_skills;
        Gtk::ComboBoxText abilities_knowledges;
        Gtk::ComboBoxText advantages_disciplines;
        Gtk::ComboBoxText advantages_backgrounds;
        Gtk::ComboBoxText advantages_virtues;
        Gtk::ComboBoxText advantages_virtues1;
        Gtk::ComboBoxText MertisFlows_physical;
        Gtk::ComboBoxText MertisFlows_physical1;
        Gtk::ComboBoxText MeritsFlows_mental;
        Gtk::ComboBoxText MeritsFlows_mental1;
        Gtk::ComboBoxText MeritsFlows_social;
        Gtk::ComboBoxText MeritsFlows_social1;
        Gtk::ComboBoxText MeritsFlows_supernatural;
        Gtk::ComboBoxText MeritsFlows_supernatural1;
        Gtk::Button submit_button, button_page2, button_page3, button_page4;
        Gtk::Entry inputEntry1;
        Gtk::Entry inputEntry2;
        Gtk::Entry inputEntry3;
        Gtk::Entry inputEntry4;
        Gtk::Entry inputEntry5;
        Gtk::Entry inputEntry6;
        Gtk::Entry inputEntry7;
        Gtk::Entry inputEntry8;
        Gtk::Entry inputEntry9;
        Gtk:: Entry social2, social3, physical2,virtues2, talent2;    
        Gtk::Button m_button;
        Gtk::ScrolledWindow m_ScrolledWindow;
        Gtk::Grid mainGrid1;
        Gtk::Grid mainGrid2;
        Gtk::Grid mainGrid3;
        Gtk::Grid mainGrid4;
        Gtk::Notebook  Selector;


};


#endif //GTKMM_EXAMPLE_BUTTONS_H
