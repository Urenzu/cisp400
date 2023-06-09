#include "calculator.h"

unsigned long long factorial(int n)
{
    if(n<=2) return n;
    else return n * factorial(n-1);
}

double factExp(double x, int n)
{
    double product = 1;
    for(int i = n; i>= 1; i--)
    {
        product *= (x/i);
    }
    return product;
}

double sin(double x, int nTerms)
{
    double sum = 0.0;
    double alternator = -1;
    for(int i = 0; i < nTerms; i++)
    {
        alternator *= -1;
        sum += alternator * factExp(x, 2*i + 1);
    }
    return sum;
}

double sqrt(double x, int nTerms)
{
    double next = 0.0;
    double prev = 1.0;
    for(int i = 0; i < nTerms; i++)
    {
        next = prev - (prev * prev - x) / (2*prev);
        prev = next;
    }
    return next;
}

double primary()	// Number or �(� Expression �)�
{
    Token t = ts.get();
    switch (t.kind)
    {
    case '(':			       // handle �(�expression �)�
    {
        double d = expression();
        t = ts.get();
        if (t.kind != ')')
            error("')' expected");


        ///Look ahead for a fact Token here before returning d
        ///don't forget to put the Token back if it is not fact
        ///fix me

        Token t2 = ts.get();
        if(t2.kind == '!')
        {
            d = factorial(d);
        }
        else
        {
            ts.putback(t2);
        }

        return d;	// return the number�s value

    }

    case '-':
        return -primary();

    case number:	// rather than case '8':
    {
        ///Look ahead for a fact Token here before returning t's value
        ///don't forget to put the Token back if it is not fact

        Token t2 = ts.get();
        if(t2.kind == '!')
        {
            t.value = factorial(t.value);
        }
        else
        {
            ts.putback(t2);
        }
        return t.value;	// return the number�s value

    }

    ///if the token is of type sine, then
    ///call for a new primary
    ///pass that into the sin function
    ///use nTerms = 1000
    case sine:
    {
        double x = primary();
        return sin(x, 1000);
    }
    ///if the token is of type root, then
    ///call for a new primary
    ///pass that into the sqrt function
    ///use nTerms = 1000
    case root:
    {
        double x = primary();
        return sqrt(x, 1000);
    }
    default:
        error("primary expected");
    }
    return 0.0;
}

///The code below this line does not need to be changed at all

double expression()	// read and evaluate: 1   1+2.5   1+2+3.14  etc.
{
    double left = term(); 			// get the Term
    while (true)
    {
        Token t = ts.get();		// get the next token�
        switch (t.kind)  			// � and do the right thing with it
        {
        case '+':
            left += term();
            break;
        case '-':
            left -= term();
            break;
        default:
            ts.putback(t);

            return left;		// return the value of the expression
        }
    }
}
double term()	// exactly like expression(), but for * and  /
{
    double left = primary(); 		// get the Primary
    while (true)
    {
        Token t = ts.get();	// get the next Token
        switch (t.kind)
        {
        case '*':
            left *= primary();
            break;
        case '/':
        {
            double d = primary();
            if  (d==0)
                error("divide by zero");
            left /= d;
            break;
        }
        default:
            ts.putback(t);
            return left;	// return the value
        }
    }
}


void clean_up_mess()
{
    ts.ignore(print);
}


void calculate()
{
    while (cin)
        try
        {
            cout << prompt;
            Token t = ts.get();
            while (t.kind == print)
                t=ts.get();	// first discard all �prints�
            if (t.kind == quit)
                return;		// quit
            ts.putback(t);
            cout << result << expression() << endl;
        }
        catch (exception& e)
        {
            cerr << e.what() << endl;		// write error message
            clean_up_mess();		// <<< The tricky part!
        }
}
