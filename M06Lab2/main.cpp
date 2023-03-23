#include "Simple_window.h"

int main()
{
    using namespace Graph_lib;

    Simple_window win(Point(800,1000),800,800,"Canvas");     // make a window

    
    int x_size = win.x_max();
    int y_size = win.y_max();
    int x_grid = 100; // make cells 80 pixels wide
    int y_grid = 100; // make cells 40 pixels high
    
    Lines grid;

    for (int x=x_grid; x<x_size; x+=x_grid) // veritcal lines
        grid.add(Point(x,0),Point(x,y_size));
    for (int y = y_grid; y<y_size; y+=y_grid) // horizontal lines
        grid.add(Point(0,y),Point(x_size,y));
    
    win.attach(grid);

    Rectangle border(Point(0,0), 800, 800);
    win.attach(border);


    Rectangle r1(Point(0,0), 100, 100);
    win.attach(r1);
    r1.set_fill_color(Color::red);

    Rectangle r2(Point(100,100), 100, 100);
    win.attach(r2);
    r2.set_fill_color(Color::red);

    Rectangle r3(Point(200,200), 100, 100);
    win.attach(r3);
    r3.set_fill_color(Color::red);

    Rectangle r4(Point(300,300), 100, 100);
    win.attach(r4);
    r4.set_fill_color(Color::red);

    Rectangle r5(Point(400,400), 100, 100);
    win.attach(r5);
    r5.set_fill_color(Color::red);

    Rectangle r6(Point(500,500), 100, 100);
    win.attach(r6);
    r6.set_fill_color(Color::red);

    Rectangle r7(Point(600,600), 100, 100);
    win.attach(r7);
    r7.set_fill_color(Color::red);

    Rectangle r8(Point(700,700), 100, 100);
    win.attach(r8);
    r8.set_fill_color(Color::red);

    Rectangle r9(Point(800,800), 100, 100);
    win.attach(r8);
    r8.set_fill_color(Color::red);             

    Image i(Point(600,0),"img1.jpg"); // open an image file
        win.attach(i);
        win.set_label("Canvas #1");

    Image ii(Point(0,400),"img2.jpg"); // open an image file
        win.attach(ii);
        win.set_label("Canvas #2");

    Image iii(Point(0,600),"img3.jpg"); // open an image file
        win.attach(iii);
        win.set_label("Canvas #3");

    Image iv(Point(0,0),"img4.jpg"); // open an image file
        win.attach(iv);
        win.set_label("Canvas #4");

    win.wait_for_button();

    int counter = 1;
    while(true)
    {
        
        if(counter % 64 == 0 && counter != 0)
        {
            counter = 0;
            iv.move(-700, -700);
        }
        else if(counter % 8 == 0 && counter != 0)
        {
            iv.move(-700, 100);
        }
        else
        {
            iv.move(100, 0);
        }
        counter++;
        win.wait_for_button();
    }
}
