#include "Lines_window.h"

Lines_window::Lines_window(Point xy, int w, int h, const string& title)
:Window(xy,w,h,title),  
// construct/initialize the parts of the window:
                                 // location        size          name            action
next_button(Point(x_max()-150,0), 70, 20, "Next point", cb_next),
quit_button(Point(x_max()-70,0), 70, 20, "Quit", cb_quit),       // quit button
next_x(Point(x_max()-310,0), 50, 20, "next x:"),               // io boxes
next_y(Point(x_max()-210,0), 50, 20, "next y:"),
xy_out(Point(100,0), 100, 20, "current (x,y):")
{
    attach(next_button); // attach the parts to the window
    attach(quit_button);
    attach(next_x);
    attach(next_y);
    attach(xy_out);
    attach(lines); // attach the open_polylines to the window
}

void Lines_window::cb_quit(Address, Address pw)
// Call Lines_window::quit() for the window located at address pw
{
  reference_to<Lines_window>(pw).quit(); // now call our function
} 

// The action itself is simple enough to write
void Lines_window::quit()
{
    // here we can do just about anything with the Lines_window
    hide(); // peculiar FLTK idiom for "get rid of this window"
}

void Lines_window::cb_next(Address, Address pw)
// Call Lines_window::quit() for the window located at address pw
{
  reference_to<Lines_window>(pw).next(); // now call our function
} 

// our action for a click ("push") on the next point button
void Lines_window::next()
{
    int x = next_x.get_int();
    int y = next_y.get_int();

    lines.add(Point(x,y));

    // update current position readout:
    stringstream ss;
    ss << '(' << x << ',' << y << ')';
    xy_out.put(ss.str());

    redraw();   // now redraw the screen
}   




