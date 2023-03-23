#include "calculator.h"

void calculate()
{
    while (cin)   // Loop until cin fails.  Only EOF (Ctrl + d) will cause this.
    try {
        cout << prompt;
        Token t = ts.get(); // get next token to check for quit
        while (t.kind == print) t=ts.get(); // discard all "prints", in case user types ;;;
            if (t.kind == quit) return; // quit
                ts.putback(t); // put t back, it must be part of expression
        cout << result << expression() << endl;
    }
    catch (exception& e) {
        cerr << e.what() << endl; // write error message
        clean_up_mess(); // Bad input, clear out the stream
    }
}

void clean_up_mess()
{ 
    ts.ignore(print);
} 

double expression() // read and evaluate: 1   1+2.5   1+2+3.14  etc.
{
    double left = term();  // get the Term
    while (true) {
        Token t = ts.get(); // get the next token...
        switch (t.kind) { // ... and do the right thing with it
        case '+':     left += term(); break;
        case '-':     left -= term(); break;
        default:
            ts.putback(t);  // put the unused token back      
            return left; // return the value of the expression
        }
    }
}

double term() // exactly like expression(), but for * and  /
{
    double left = primary();  // get the Primary
    while (true) {
        Token t = ts.get(); // get the next Token
        switch (t.kind) {
        case '*':
            left *= primary();
            break;
        case '/':
                {  //if declaring variables inside a case, we need {}
            double d = primary();
            if  (d==0) error("divide by zero");
            left /= d;
            break;
                }
        default:
            ts.putback(t);  // put the unused token back
            return left; // return the value
        }
    }
}

double primary() // Number or '(' Expression ')'
{
    Token t = ts.get();
    switch (t.kind) {
    case '(':        // handle '('expression ')'
        { double d = expression();
        t = ts.get();
        if (t.kind != ')') error("')' expected");
        return d;
        }
    case '-':  return -primary();
    case number: // we use '8' to represent the "kind" of a number
        return t.value;// return the number's value
    default:
        error("primary expected");
    }
    return -1;
}