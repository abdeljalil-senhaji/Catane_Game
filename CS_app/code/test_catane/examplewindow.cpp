/* gtkmm example Copyright (C) 2002 gtkmm development team
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2
 * as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#include <iostream>
#include "examplewindow.h"
#include <gtkmm.h>

DrawHelper::DrawHelper()
{
    // Create a pixel buffer containing the background image:
    m_buffer = Gdk::Pixbuf::create_from_file("Board.png", 1000, 1000);
    signal_draw().connect(sigc::mem_fun(*this, &DrawHelper::draw_image));

    // Enable signals:
    add_events(Gdk::BUTTON1_MOTION_MASK | Gdk::BUTTON_PRESS_MASK | Gdk::BUTTON_RELEASE_MASK);

    // Save initial pointer position when clicked:
    signal_button_press_event().connect(
        [this](GdkEventButton* p_event)
        {
            m_startX = p_event->x;
            m_startY = p_event->y;

            return true;
        });

    // Update rectangle when mouse is dragged:
    signal_motion_notify_event().connect(
        [this](GdkEventMotion* p_event)
        {
            m_endX = p_event->x;
            m_endY = p_event->y;

            m_width  = m_endX - m_startX;
            m_height = m_endY - m_startY;

            signal_draw().connect(sigc::mem_fun(*this, &DrawHelper::draw_rectangle));
            queue_draw();

            return true;
        });

    // Change background so it includes the shape just drawn by
    // the user:
    signal_button_release_event().connect(
        [this](GdkEventButton* p_event)
        {
            // Notice we save to connection to later disconnect it:
            m_drawConnection = signal_draw().connect(sigc::mem_fun(*this, &DrawHelper::add_current_shape));

            return true;
        });
}

DrawHelper::~DrawHelper() = default;

bool DrawHelper::draw_image(const Cairo::RefPtr<::Cairo::Context>& p_context)
{
    Gdk::Cairo::set_source_pixbuf(p_context, m_buffer, 0, 0);

    p_context->paint();

    return false;
}

bool DrawHelper::draw_rectangle(const Cairo::RefPtr<::Cairo::Context>& p_context)
{
    p_context->save();

    p_context->set_line_width(2);
    p_context->rectangle(m_startX, m_startY, m_width, m_height);
    p_context->stroke();

    p_context->restore();

    return false;
}

bool DrawHelper::add_current_shape(const Cairo::RefPtr<::Cairo::Context>& p_context)
{
    // Save the current drawing, including the last drawn
    // shape. This will become the new background (which will
    // visually preserve the last drawn shape).
    m_buffer = Gdk::Pixbuf::create(p_context->get_target(), 0, 0, 1000, 1000);
    Gdk::Cairo::set_source_pixbuf(p_context, m_buffer, 0, 0);

    p_context->paint();

    // We disconnect the signal because we do not want it
    // to keep getting called:
    m_drawConnection.disconnect();

    return false;
}

MyWindow::MyWindow()
{
    set_default_size(1000, 1000);

    // Add draw helper:
    add(m_drawHelper);

    // Show all widgets:
    show_all();
}

