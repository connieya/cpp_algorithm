#include "bits/stdc++.h"

using namespace std;

bool isPrime(int num) {
    if (num <= 1) return false;
    if (num == 2) {
        return true;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;

}

long long reverse(long long num) {
    long long res = 0;
    while (num) {
        res = res * 10 + num % 10;
        num /= 10;
    }
    return res;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n;
    cin >> n;
    while (1) {
        if (n == reverse(n) && isPrime(n)) {
            cout << n;
            return 0;
        }
        n++;
    }

}