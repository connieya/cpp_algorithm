#include "bits/stdc++.h"

using namespace std;

void to_binary(int num) {
    if (num == 0) {
        cout << '\n';
        return;
    }
    to_binary(num / 2);
    cout << num % 2;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    to_binary(4095);
    to_binary(4095*2);
    to_binary(4095*4);
    to_binary(4095*8);
    to_binary(4095*16);
    to_binary(4095*32);
    to_binary(4095*4095);
}