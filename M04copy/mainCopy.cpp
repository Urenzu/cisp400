#include "MatricesCopy.h"
using namespace Matrices;

int main()
{
    Matrix a(2,2);
    Matrix b(2,4);

    a(0,0) = 0;
    a(0,1) = -1;
    a(1,0) = 1;
    a(1,1) = 0;

    b(0,0) = 1;
    b(0,1) = 0.866025;
    b(0,2) = 1;
    b(0,3) = 0.5;
    b(1,0) = 0;
    b(1,1) = 0.5;
    b(1,2) = 1;
    b(1,3) = 0.866025;

    cout << "a:" << endl << a << endl;
    cout << "b:" << endl << b << endl;

    cout << "c = b + b:" << endl << (b + b) << endl;

    Matrix c(2,4);
    c = a * b;
    cout << "c = a * b:" << endl << c << endl;

}