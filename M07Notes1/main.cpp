#include "Simple_window.h"

double one(double x) { return 1; }  // y==1
double slope(double x) { return x/2; } // y==x/2
double square(double x) { return x*x; }  // y==x*x

double sloping_cos(double x) { return cos(x)+slope(x); }

///this return value should be unsigned long long or double
unsigned long long fac(int n) { return n <= 1 ? 1 : n * fac(n - 1);} // factorial

double term(double x, int n)  // xn/n!
{
    return pow(x,n)/fac(n);
}

int expN_number_of_terms = 6; // nasty sneaky argument to expN

double expN(double x) // sum of n terms of Taylor series for ex
{
    double sum = 0;
    for (int i = 0; i<expN_number_of_terms; ++i) sum+=term(x,i);
    return sum;
}

int main()
{
    Simple_window win0(Point(100,100),600,400,"Function graphing");

    const int xmax = win0.x_max(); // window size (600 by 400)
    const int ymax = win0.y_max();

    const int xlength = xmax-40;
    const int ylength = ymax-40;

    const int x_orig = xmax/2; 
    const int y_orig = ymax/2;
    const Point orig(x_orig, y_orig);   // position of Cartesian (0,0) in window

    const int r_min = -10; // range [-10:11) 
    const int r_max = 11;

    const int n_points = 400; // number of points used in range

    const int x_scale = 20; // scaling  factors
    const int y_scale = 20;

    Function s(one,          -10,11,   orig,   n_points,x_scale,y_scale);  
    Function s2(slope,     -10,11,   orig,   n_points,x_scale,y_scale);    
    Function s3(square,  -10,11,   orig,   n_points,x_scale,y_scale); 
    
    win0.attach(s);
    win0.attach(s2);
    win0.attach(s3);

    Text ts(Point(100,y_orig-30),"one");
    Text ts2(Point(100,y_orig+y_orig/2-10),"x/2");
    Text ts3(Point(x_orig-90,20),"x*x");

    win0.attach(ts);
    win0.attach(ts2);
    win0.attach(ts3);

    Axis x(Axis::x, Point(20,y_orig), xlength, xlength/x_scale, "one notch == 1");
    Axis y(Axis::y, Point(x_orig,ylength+20), ylength, ylength/y_scale, "one notch == 1");

    win0.attach(x);
    win0.attach(y);

    x.set_color(Color::red);
    y.set_color(Color::red);

    Function s4(cos,-10,11,orig,400,20,20);
    s4.set_color(Color::blue);
    Function s5(sloping_cos,-10,11,orig,400,20,20);

    win0.attach(s4);
    win0.attach(s5);

    win0.wait_for_button( );

    Simple_window win(Point(100,100),xmax,ymax,"");
    // the real exponential :
    Function real_exp(exp,r_min,r_max,orig,500,x_scale,y_scale);
    real_exp.set_color(Color::blue);
    win.attach(real_exp);

    win.attach(x);
    win.attach(y);
    x.set_color(Color::red);
    y.set_color(Color::red);

    win.wait_for_button( );

    for (int n = 0; n<50; ++n) {
        ostringstream ss;
        ss << "exp approximation; n==" << n ;
        win.set_label(ss.str().c_str());
        expN_number_of_terms = n; // nasty sneaky argument to expN

        // next approximation:
        Function e(expN,r_min,r_max,orig,200,x_scale,y_scale); 

        win.attach(e);
        win.wait_for_button(); // give the user time to look
        win.detach(e);
    }

}