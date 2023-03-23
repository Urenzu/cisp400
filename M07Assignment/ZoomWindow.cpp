#include "ZoomWindow.h"

    ZoomWindow::ZoomWindow(Point xy, int w, int h, const string& title):
    Simple_window(xy, w, h, title),
    plane(PLANE_Y_OFFSET, complex<double>(0,0),1.0,w,h - PLANE_Y_OFFSET),
    next_i(Point(w-170,0), 100, 20, "Center i:"),
    next_r(Point(w-350,0), 100, 20, "Center r:"),
    next_zoom(Point(w-525,0), 100, 20, "Zoom Lvl:")
    {
        attach(plane);;
        attach(next_i);
        attach(next_r);
        attach(next_zoom);
        plane.createBuffer();
    }

    double ZoomWindow::getCenter_r() const
    {
        return plane.getCenter().real();
    }

    double ZoomWindow::getCenter_i() const
    {
        return plane.getCenter().imag();
    }

    double ZoomWindow::getZoom() const
    {
        return plane.getZoomLevel();
    }

    bool ZoomWindow::wait_for_button()
    {
        Simple_window::wait_for_button();
        istringstream ss;
        string s = next_r.get_string();
        ss.str(s);
        double real, imag, zoom;
        ss >> real;
        ss.clear();
        s = next_i.get_string();
        ss.str(s);
        ss >> imag;
        ss.clear();
        s = next_zoom.get_string();
        ss.str(s);
        ss >> zoom;
        ss.clear();

        plane.setCenter(complex<double>(real, imag));
        plane.setZoomLevel(zoom);
        plane.createBuffer();
        return true;
    }