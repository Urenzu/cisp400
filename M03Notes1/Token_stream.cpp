#include "Token_stream.h"

void Token_stream::putback(Token t){
    if (full) error("putback() into a full buffer");
    buffer=t;
    full=true;
}

void Token_stream::ignore(char c){
    if (full && c==buffer.kind) { // first look in buffer:
        full = false;
        return;
    }
    full = false; // discard the contents of buffer, then search input:
    char ch = 0;
    while (cin>>ch)
        if (ch==c) return;
}

Token Token_stream::get()  // read a Token from the Token_stream
{
    if (full) { full=false; return buffer; }  // check if we already have a Token ready

    char ch;
    cin >> ch; // note that >> skips whitespace (space, newline, tab, etc.)

    switch (ch) {
    case '(': case ')': case print: case quit: case '+': case '-': case '*': case '/': 
        return Token{ch}; // let each character represent itself
    case '.':
    case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
        {
        cin.putback(ch); // put digit back into the input stream
        double val;
        cin >> val; // read a floating-point number
        return Token{number,val}; // let '8' represent "a number"
        }
        default:
        error("Bad token");
    }
    return Token{0};
}



