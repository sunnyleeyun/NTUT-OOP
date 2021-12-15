#ifndef GCD_H
#define GCD_H

// return the (positive) greatest common divisor of two integers
// a, b may be positive or negative
int gcd(int a, int b) 
{
    if (a < 0)
        return gcd(-a, b);
    if (b < 0)
        return gcd(a, -b);
    
    if (b > a)
        return gcd(b, a);
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

#endif