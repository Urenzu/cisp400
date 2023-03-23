#include "Lines_window.h"

int main()
try {
    Lines_window win(Point(100,100),600,400,"lines");
    return gui_main();
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
    keep_window_open();
}
catch (...) {
    cerr << "exception\n";
    keep_window_open();
}