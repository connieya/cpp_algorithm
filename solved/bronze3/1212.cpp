#include "bits/stdc++.h"

using namespace std;

void toBinary(int num) {
    if (num == 0) {
        return;
    }
    toBinary(num / 2);
    cout << num % 2;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string num;
    cin >> num;
    int len = num.length();
    for (int i = 0; i < len; ++i) {
        int n = num[i] - '0';
        if (i == 0) {
            if (n == 0){
                cout << "0"; continue;
            }
            toBinary(n);
            continue;
        }
        if (n == 0) {
            cout << "000";
        } else if (n == 1) {
            cout << "001";
        } else if (n == 2) {
            cout << "010";
        } else if (n == 3) {
            cout << "011";
        } else {
            toBinary(num[i] - '0');
        }
    }
}