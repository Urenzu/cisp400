#include "../std_lib_facilities.h"
#include "calculator.h"
#include "Token_stream.h"

Token_stream ts;  //Declare a global variable so functions can use the Token_stream
int main(){
    try {
        calculate(); //Prompt, call expression, loop
        keep_window_open("~~"); // function in std_lib_facilities.  Hold window open until user types "~~"
        return 0;
    }
    catch (...){   //any uncaught exceptions, don't try to recover
        cerr << "exception \n";
        keep_window_open("~~");
        return 2;
    }
    keep_window_open("~~");
}
