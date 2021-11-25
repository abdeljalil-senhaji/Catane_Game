#ifndef GTKMM_EXAMPLEWINDOW_H
#define GTKMM_EXAMPLEWINDOW_H

#include <gtkmm.h>

class DrawHelper : public Gtk::Layout
{

public:

    DrawHelper();
    ~DrawHelper();

private:

    bool draw_image(const Cairo::RefPtr<::Cairo::Context>& p_context);
    bool draw_rectangle(const Cairo::RefPtr<::Cairo::Context>& p_context);
    bool add_current_shape(const Cairo::RefPtr<::Cairo::Context>& p_context);

    Glib::RefPtr<Gdk::Pixbuf> m_buffer;

    double m_startX;
    double m_startY;

    double m_endX;
    double m_endY;

    double m_width;
    double m_height;

    sigc::connection m_drawConnection;
};

class MyWindow : public Gtk::Window
{

public:

    MyWindow();

private:

    DrawHelper m_drawHelper;

};


#endif //GTKMM_EXAMPLEWINDOW_H