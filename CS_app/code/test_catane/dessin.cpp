#include <iostream>
#include <gtkmm.h>
#include <gtkmm/window.h>
#include <vector>
#include <gtkmm.h>
#include <map> 
#include <gtkmm/application.h>

class Dessin : public Gtk::DrawingArea
{
public:
	Dessin();
	~Dessin();
	bool on_draw(const Cairo::RefPtr<Cairo::Context> &);
};
Dessin::Dessin() { set_size_request(600, 400); }
Dessin::~Dessin() {}
bool Dessin::on_draw(const Cairo::RefPtr<Cairo::Context> &cr)
{
	Gtk::Allocation allocation = get_allocation();
	int xc = allocation.get_width() / 2;
	int yc = allocation.get_height() / 2;
	int lesser = 2 * MIN(xc, yc);

	cr->set_line_width(lesser * 0.02);

	cr->save();
	cr->arc(2 * xc / 3.0, yc / 2.0, lesser / 4.0, -(M_PI / 5.0), M_PI);
	cr->close_path();
	cr->set_source_rgb(0.0, 0.8, 0.0);
	cr->fill_preserve();
	cr->restore();
	cr->stroke();

	cr->save();
	cr->arc(xc, yc, lesser / 4.0, 0.0, 2.0 * M_PI);
	cr->set_source_rgba(0.0, 0.0, 0.8, 0.6);
	cr->fill_preserve();
	cr->restore();
	cr->stroke();

	cr->save();
	cr->translate(xc, 3 * yc / 2);
	cr->scale(6.0 * xc / 8.0, yc / 3);
	cr->arc(0.0, 0.0, 1.0, 0.0, 2 * M_PI);
	cr->set_source_rgba(0.8, 0.0, 0.0, 0.7);
	cr->fill_preserve();
	cr->restore();
	cr->stroke();

	return true;
}

class Fenetre : public Gtk::Window
{
public:
	Fenetre();

protected:
	Dessin dessin;
	Gtk::ScrolledWindow m_ScrolledWindow;
};
Fenetre::Fenetre()
{
	set_title("DrawingArea");
	set_position(Gtk::WIN_POS_CENTER);

	m_ScrolledWindow.add(dessin);
	m_ScrolledWindow.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);
	m_ScrolledWindow.set_size_request(600, 400);

	add(m_ScrolledWindow);
	show_all_children();
}

int main(int argc, char *argv[])
{
	auto app = Gtk::Application::create(argc, argv);
	Fenetre opts;
	app->run(opts);
}
