#include "bits/stdc++.h"
#define INF 1000000007
using namespace std;

typedef unsigned long ULONG;

typedef struct tagMatrix2x2 {
    ULONG Data[2][2];

} Matrix2x2;

Matrix2x2 multiply(Matrix2x2 a, Matrix2x2 b) {
    Matrix2x2 c;

    c.Data[0][0] = a.Data[0][0] * b.Data[0][0] + a.Data[0][1] * b.Data[1][0];
    c.Data[0][1] = a.Data[0][0] * b.Data[1][0] + a.Data[0][1] * b.Data[1][1];

    c.Data[1][0] = a.Data[1][0] * b.Data[0][0] + a.Data[1][1] * b.Data[1][0];
    c.Data[1][1] = a.Data[1][0] * b.Data[1][0] + a.Data[1][1] * b.Data[1][1];
    return c;
}

Matrix2x2 power(Matrix2x2 a, int n) {
    if (n > 1) {
        a = power(a, n / 2);
        a = multiply(a, a);

        if (n & 1) {
            Matrix2x2 b;
            b.Data[0][0] = 1;
            b.Data[0][1] = 1;
            b.Data[1][0] = 1;
            b.Data[1][1] = 0;

            a = multiply(a, b);
        }
    }
    return a;
}

ULONG fibo(int n) {
    Matrix2x2 a;
    a.Data[0][0] = 1;
    a.Data[0][1] = 1;
    a.Data[1][0] = 1;
    a.Data[1][1] = 0;

    a = power(a, n);
    return a.Data[0][1];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ULONG n;
    cin >> n;
    cout << fibo(n) % INF;
}