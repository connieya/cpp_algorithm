#include "stdio.h"

typedef unsigned long long ULONG;

ULONG Power(int Base, int Exponent) {
    if (Exponent == 1) {
        return Base;
    } else if (Base == 0) {
        return 1;
    }

    if (Exponent % 2 == 0) {
        ULONG newBase = Power(Base, Exponent / 2);
        return newBase * newBase;
    }else {
        ULONG newBase =Power(Base, (Exponent-1)/2);
        return newBase*newBase*Base;
    }
}


int main()
{
    int Base = 2;
    int Exponent = 30;
    printf("%d ^ %d = %lu\n ",Base,Exponent, Power(Base,Exponent));
}