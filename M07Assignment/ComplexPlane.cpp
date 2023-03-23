#include "ComplexPlane.h"

///helper functions to be unit tested
///map from pixels to complex plane
double mapRange(double n, double fromLow, double fromHigh, double toLow, double toHigh)
{
    return ((n - fromLow) / (fromHigh - fromLow)) * (toHigh - toLow) + toLow;
}
///write rgb values into one dimensional FLTK output buffer
void writePixel(unsigned char* buf, int xPixels, int row, int col, unsigned char r, unsigned char g, unsigned char b)
{
    buf[(row*xPixels + col)*3] = r;
    buf[(row*xPixels + col)*3 + 1] = g;
    buf[(row*xPixels + col)*3 + 2] = b;

}
///count the number of Mandelbrot iterations for a given point on the complex plane, used to determine pixel color
int countIterations(double re, double im, int maxIterations)
{
    complex<double> c(re,im);
    complex<double> z(0,0);
    int i = 0;
    for(i = 0; i < maxIterations && abs(z) < 2.0; i++)
    {
        z = z*z + c;
    }

    return i;
}

///Called repeatedly by graphics engine
///do not change buf here, just draw its current value
void ComplexPlane::draw_lines() const
{
    fl_draw_image(buf, 0, y_pixel_offset, xPixels, yPixels);
}

///this function creates the pixel buffer for FLTK to display
///call on construction and whenever the pixels change
///for each pixel, map it to a point on the complex plane
///count the number of Mandelbrot iterations for that point
///assign its iteration count to a color
///use writePixel to write the color for that pixel to the output buffer
void ComplexPlane::createBuffer()
{
    double zoomedReRange = reRange * zoomLevel;
    double zoomedImRange = imRange * zoomLevel;

    for(int i = 0; i < yPixels; i++)
    {
        for(int j = 0; j < xPixels; j++)
        {
            int iterations = countIterations(mapRange(j, 0, xPixels, center.real() - zoomedReRange/2, center.real() + zoomedReRange/2),
                                             mapRange(i, yPixels, 0, center.imag() - zoomedImRange/2, center.imag() + zoomedImRange/2),
                                             maxIterations);
            unsigned char r,g,b;
            Fl::get_color(maxIterations - iterations, r, g, b);
            writePixel(buf, xPixels, i, j, r, g, b);

        }
    }
}