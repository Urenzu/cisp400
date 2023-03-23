#ifndef TOKEN_GUARD
#define TOKEN_GUARD

#include "../std_lib_facilities.h"

// Token "kind" values:

const char number = '8'; // a floating-point number
const char quit = 'q'; // an exit command
const char print = ';'; // a print command
// User interaction strings, used in main:
const string prompt = "> ";
const string result = "= "; // indicate that a result follows

struct Token {          // user-defined type called Token
    char kind;          // what kind of token
    double value;       // used for numbers (only): a value 
};

class Token_stream {
public:
                        // user interface:
    Token get();        // get a Token
    void putback(Token);// put a Token back into the Token_stream
    void ignore(char c);// discard tokens up to and including c
private:
                        // representation: not directly accessible to users:
    bool full {false};  // is there a Token in the buffer?
    Token buffer;       // here is where we keep a Token put back using putback()
};

#endif

