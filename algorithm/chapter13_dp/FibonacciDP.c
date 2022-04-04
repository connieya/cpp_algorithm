#include "stdio.h"
#include "stdlib.h"

typedef unsigned long ll;

ll Fibonacci(int n)
{
    int i;
    ll result;
    ll* fibonacciTable;

    if( n == 0 || n == 1){
        return n;
    }

    fibonacciTable = (ll*) malloc(sizeof(ll)*(n+1));

    fibonacciTable[0] = 0;
    fibonacciTable[1] = 1;

    for (i=2; i<=n; i++) {
        fibonacciTable[i] = fibonacciTable[i-1] + fibonacciTable[i-2];
    }

    result = fibonacciTable[n];
    free(fibonacciTable);
    return result;
}

int main(void)
{
    int n = 46;
    ll result = Fibonacci(n);
    printf("fibonacci(%d) =  %lu \n", n, result);
}