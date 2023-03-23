#ifndef CALCULATOR_GUARD
#define CALCULATOR_GUARD

#include "../std_lib_facilities.h"
#include "Token_stream.h"

extern Token_stream ts;

void calculate();
void clean_up_mess();
double expression();    // deal with + and –
                        // return the sum (or difference)
double term();          // deal with *, /
                        // return the product (or ...)
double primary();       // deal with numbers and parentheses
                        //return the value
#endif