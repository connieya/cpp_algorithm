﻿#include "bits/stdc++.h"


using namespace std;

string arr[251];

string calcBigNumber(string a, string b) {
    int len_a = a.length();
    int len_b = b.length();
    string str_a = a;
    string str_b = b;
    if (len_a > len_b) {
        int tmp = len_a;
        len_a = len_b;
        len_b = tmp;
        str_a = b;
        str_b = a;
    }
    int idx_a = len_a - 1;
    int idx_b = len_b - 1;
    string ans = "";
    int prev = 0;
    while (idx_a >= 0) {
        int x = str_a[idx_a] - '0';
        int y = str_b[idx_b] - '0';
        int add = (x + y + prev) % 10;
        prev = (x + y + prev) / 10;
        ans += to_string(add);
        idx_a--;
        idx_b--;
    }
    if (idx_b < 0 && prev > 0) {
        ans += to_string(prev);
    } else {
        while (idx_b >= 0) {
            int x = str_b[idx_b] - '0';
            int add = (x + prev) % 10;
            ans += to_string(add);
            idx_b--;
            prev = (x + prev) / 10;
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    arr[0] = "1";
    arr[1] = "1";
    arr[2] = "3";
    arr[3] = "5";
    for (int i = 4; i <= 250; ++i) {
        string add = calcBigNumber(arr[i - 2], arr[i - 2]);
        arr[i] = calcBigNumber(add, arr[i - 1]);
    }
    int n;
    while (cin >> n) {
        cout << arr[n] << '\n';
    }
}