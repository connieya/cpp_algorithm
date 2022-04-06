#include "bits/stdc++.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // 1. modular operation
    cout << " 1. modular operation " << '\n';
    cout << (17 & ((1 << 4) - 1)) << '\n'; // 17 % 16 = 1
    for (int i = 0; i < 10; ++i) {
        cout << (i & 3) << ' '; // i % 4
    }
    cout << '\n';
    for (int i = 0; i < 10; ++i) {
        cout << (i & 1) << ' '; // i % 2
    }
    cout << '\n';
    for (auto i: {33, 37, 42, 45}) {
        cout << (i & 31) << ' ';
    }
    cout << '\n';

    // 2. multiplication
    cout << " 2. multiplication " << '\n';
    cout << (14 << 3) << '\n'; // 14 * 8 = 112
    cout << (1 << 5) << '\n';

    // 3. division
    cout << " 3. division " << '\n';

    cout << (100 >> 2) << '\n'; // 100 / 4;
    cout << (128 >> 7) << '\n'; // 128 / 128

}