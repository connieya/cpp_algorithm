#include "bits/stdc++.h"

using namespace std;

int main(void) {
    int n;
    cin >> n;
    int a = 1, b = 1, c = 1;
    while (n--) {
        c = (2 * a + b);
        b = a;
        a = c;
    }
    cout << a;
}