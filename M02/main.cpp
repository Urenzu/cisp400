#include "RSA.h"

int main()
{
    unsigned long long p, q, n, lambda, d, e, m, c;
    unsigned int seed;
    cout << "Enter a seed: ";
    cin >> seed;
    cout << endl;
    srand(seed);
    p = getPrime(UCHAR_MAX, USHRT_MAX);
    q = getPrime(UCHAR_MAX, USHRT_MAX);
    n = p*q;
    cout << "P: " << p << endl;
    cout << "q: " << q << endl;
    cout << "n: " << n << endl;
    lambda = lcm(p-1, q-1);
    cout << "lambda: " << lambda << endl;
    e = getPrime(2, lambda - 1);
    while(lambda % e ==0) e = getPrime(2, lambda - 1);
    cout << "e: " << e << endl;
    d = modInverse(e, lambda);
    cout << "d: " << d << endl;
    cout << "Public key: n = " << n << " e = " << e << endl;
    cout << "Private key: n = " << n << " d = " << d << endl;
    cout << "Enter a positive number less than " << n << ": ";
    cout << endl;
    cin >> m;
    c = modExp(m, e, n);
    cout << "Cipher: " << c << endl;
    cout << "Decrypted cipher: " << modExp(c, d, n) << endl;


}