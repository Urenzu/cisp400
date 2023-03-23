#include "PolygonMatrix.h"

namespace Graph_lib
{
    ///used to map from pixels to Cartesian coordinates and back
    double mapRange(double n, double fromLow, double fromHigh, double toLow, double toHigh)
    {
        return ((n - fromLow) / (fromHigh - fromLow)) * (toHigh - toLow) + toLow;
    }

    PolygonMatrix::PolygonMatrix(int _xPixels, int _yPixels):pointMatrix(2,0)
    {
        xPixels = _xPixels;
        yPixels = _yPixels;
    }

    ///add a pixel vertex to the polygon
    ///call the parent add function with Point p
    ///use mapRange to map p.x and p.y to Cartesian coordinates
    ///use addCoordinate to add the mapped x and y values to pointMatrix
    void PolygonMatrix::add(Point p)
    {
        Polygon::add(p);
        pointMatrix.addCoordinate(mapRange(p.x, 0, xPixels, -xPixels/2, xPixels/2), mapRange(p.y, yPixels, 0, -yPixels/2, yPixels/2));

    }

    void PolygonMatrix::updatePixels()
    {
        for(int j = 0; j < pointMatrix.getCols(); j++)
        {
            double xVal = pointMatrix(0,j);
            double yVal = pointMatrix(1,j);
            set_point(j, Point{(int)mapRange(xVal, -xPixels/2, xPixels/2, 0, xPixels), (int)mapRange(yVal, -yPixels/2, yPixels/2, yPixels, 0 )});
        }
    }

        ///rotate polygon by theta radians counter-clockwise
    ///construct a RotationMatrix R, mulitply it by pointMatrix
    ///then call updatePixels
    void PolygonMatrix::rotate(double theta)
    {
        RotationMatrix R(theta);
        pointMatrix = R * pointMatrix;
        updatePixels();
    }

    ///Scale the size of the polygon by factor c
    ///construct a ScalingMatrix S, multiply it by pointMatrix
    ///then call updatePixels
    void PolygonMatrix::scale(double c)
    {
        ScalingMatrix S(c);
        pointMatrix = S * pointMatrix;
        updatePixels();
    }

    ///shift the polygon by (xShift, yShift) coordinates
    ///construct a TranslationMatrix T, add it to pointMatrix
    ///then call updatePixels
    void PolygonMatrix::translate(double xShift, double yShift)
    {
        TranslationMatrix T(xShift, yShift, pointMatrix.getCols());
        pointMatrix = T + pointMatrix;
        updatePixels();
    }

}