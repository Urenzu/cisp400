#include "Simple_window.h"
#include "Graph.h"

using namespace Graph_lib;  // use our graphics interface library

int main()
{
    try
    {
        Simple_window win(Point(100,100),600,400,"Canvas"); // make a simple window 

        ///win.wait_for_button();  // give control to the display engine

        Axis xa(Axis::x, Point(20,300), 280, 10, "x axis");
        // make an Axis
        // an axis is a kind of Shape
        // Axis::x means horizontal
        // starting at (20,300)
        // 280 pixels long
        // 10 "notches" ("tick marks")
        // text "x axis"
        win.set_label("Canvas #2"); 
        win.attach(xa); // attach axis xa to the window
        ///win.wait_for_button();

        win.set_label("Canvas #3");
        Axis ya(Axis::y, Point(20,300), 280, 10, "y axis");
        ya.set_color(Color::cyan); // choose a color for the axis
        ya.label.set_color(Color::dark_red);// choose a color for the text
        win.attach(ya);
        ///win.wait_for_button();

        win.set_label("Canvas #4"); 
        Function sine(sin,0,100,Point(20,300),1000,28,28);  // sine curve
        // plot sin() in the range [0:100)
        // with (0,0) at (20,150) 
        // using 1000 points
        // scale x values *50, scale y values *50
        win.attach(sine);
        ///win.wait_for_button();

        win.set_label("Canvas #5"); 
        sine.set_color(Color::blue); // I changed my mind about sine's color

        Polygon poly; // make a shape (a polygon, obviously)
        poly.add(Point(300,200)); // add three points to the polygon
        poly.add(Point(350,100));
        poly.add(Point(400,200));
        poly.set_color(Color::red); // make the polygon red (obviously)
        win.attach(poly);
        poly.set_style(Line_style::dash);// change the line style
        ///win.wait_for_button();

        win.set_label("Canvas #6"); 
        Rectangle r(Point(200,200), 100, 50); // top left point, width, height
        win.attach(r);

        Closed_polyline poly_rect;
        poly_rect.add(Point(100,50));
        poly_rect.add(Point(200,50));
        poly_rect.add(Point(200,100));
        poly_rect.add(Point(100,100));
        win.set_label("Canvas #6.1");
        win.attach(poly_rect);


        poly_rect.add(Point(50,75)); // now poly_rect has 5 points

        win.set_label("Canvas #6.2");
    
        r.set_fill_color(Color::yellow); // color the inside of the rectangle
        poly.set_style(Line_style(Line_style::dash,4));   //make the triangle fat
        poly_rect.set_fill_color(Color::green);
        poly_rect.set_style(Line_style(Line_style::dash,2));
        win.set_label("Canvas #7");

        Text t(Point(100,150),"Hello, graphical world!");  // add text
            // point is lower left corner of text
        win.attach(t);
        win.set_label("Canvas #8");
        ///win.wait_for_button();

        ///t.set_font(Graph_lib::Font::times_bold);//Graph_lib:: name conflict?
        t.set_font_size(20);   // height in pixels
        win.set_label("Canvas #9");
        ///win.wait_for_button();

        Image ii(Point(100,50),"image.jpg"); // open an image file
        win.attach(ii);
        win.set_label("Canvas #10");
        win.wait_for_button();

        ii.move(100,200); // move 100 pixels to the right 
        // move 200 pixels down 
        win.set_label("Canvas #11");
        win.wait_for_button();

        Circle c(Point(100,200),50); // center, radius
        Ellipse e(Point(100,200), 75,25); // center, horizontal radius, vertical radius 
        e.set_color(Color::dark_red);
        Mark m(Point(100,200),'x');
        ostringstream oss;
        oss << "screen size: " << x_max() << "*" << y_max()
        << "; window size: " << win.x_max() << "*" << win.y_max();
        Text sizes(Point(100,20),oss.str());
        Image cal(Point(225,225), "snow_cpp.gif"); // 320*240 pixel gif
        cal.set_mask(Point(40,40),200,150); // display center of image


        win.attach(c);
        win.attach(e);
        win.attach(m);
        win.attach(sizes);
        win.attach(cal);
        win.set_label("Canvas #12");
        win.wait_for_button();
    
    } 
    catch(exception& e) {
    cerr << "exception: " << e.what() << '\n';
    return 1;
    }
    catch (...) {
    cerr << "Some exception\n";
    return 2;
    }
}