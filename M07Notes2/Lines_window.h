#include "GUI.h"

using namespace Graph_lib;

struct Lines_window : Graph_lib::Window 
{
    Lines_window(Point xy, int w, int h, const string& title);

private:
    // data:
    Open_polyline lines;
    // widgets:
    Button next_button; // add (next_x,next_y) to lines
    Button quit_button; // end program
    In_box next_x;
    In_box next_y;
    Out_box xy_out;

    void next();
    void quit();

    static void cb_next(Address, Address window);
    static void cb_quit(Address, Address window);

};