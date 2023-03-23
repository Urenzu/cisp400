#include "../std_lib_facilities.h"

int main()
{
    try
    {
    
        vector<int> v(10);
        for(size_t i = 0; i < v.size(); ++i) v[i] = i;
        for(int i = 0; i <= 10; ++i)
            cout << "v[" << i << "] == " << v[i] << endl;
    }
    catch(out_of_range&)
    {
        cerr << "Vector index out of range\n";
    }
    catch(...)
    {
        cerr << "Sp,e exception\n";
    }
}


/*int area(int length, int width)
{
    if(length <= 0 || width <= 0) error("Bad Area");
    return length * width;
}

int main()
{
    int x, y;

    cout << "x: ";
    cin >> x;
    cout << "y:";
    cin >> y;

    try
    {
        int z = area(x,y);
        cout << "Area: " << z << endl;
    }
    catch(runtime_error& e)
    {
        cerr << e.what() << endl;
    }
    
}
*/