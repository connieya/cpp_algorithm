#include "bits/stdc++.h"

using namespace std;

int a[2][2] = {{23,  45},
               {211, 233}};

void func(int b[2][2]) {
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            b[i][j] = 100;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    func(a);
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }

}