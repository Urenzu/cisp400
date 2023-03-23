#include "RSA.h"

bool isPrime(unsigned long long n)
{
    if(n == 1) return false;
    if(n % 2 == 0 && n!= 2) return false;
    for(unsigned long long i = 3; i <= sqrt(n); i+=2)
    {
        if(n % i == 0) return false;
    }
    return true;
}

unsigned long long getPrime(unsigned long long min, unsigned long long max)
{
    unsigned long long x = rand() % (max - min + 1) + min;
    while(!isPrime(x)) x = rand() % (max - min + 1) + min;
    return x;
}

unsigned long long gcd(unsigned long long x, unsigned long long y)
{
    if(x == 0) return y;
    if(y == 0) return x;
    if(x > y) return gcd(y, x%y);
    return gcd(x, y%x);
}

unsigned long long lcm(unsigned long long x, unsigned long long y)
{
    return (x*y) / gcd(x,y);
}

unsigned long long modInverse(unsigned long long e, unsigned long long lam)
{
    for(unsigned long long d = 1; d <= lam; d++)
    {
        if((d*e) %lam == 1) return d;
    }
    return -1;
}

unsigned long long modExp(unsigned long long base,unsigned long long exp,unsigned long long n)
{
    unsigned long long ans = 1;
    for(unsigned long long i = 0; i < exp; i++)
        ans = (ans * base) % n;
    return ans;
    
}