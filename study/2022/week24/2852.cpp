﻿//
// Created by 82109 on 2022-06-20.
//

#include "bits/stdc++.h"

using namespace std;

int to_time(string str) {
    return ((str[0] - '0') * 10 + (str[1] - '0')) * 60 + (str[3] - '0') * 10 + (str[4] - '0');
}

string to_min(int num) {
    string m = to_string(num / 60);
    string s = to_string(num % 60);
    if (m.length() == 1) m = '0' + m;
    if (s.length() == 1) s = '0' + s;
    return m + ":" + s;
}

int arr[3];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, v = 0, num, a_tmp, b_tmp;
    string clock;
    cin >> n;
    while (n--) {
        cin >> num >> clock;
        int minute = to_time(clock);
        v += (num == 1) ? 1 : -1;
        if (v == 1 && num == 1) a_tmp = minute;
        if (v == -1 && num == 2) b_tmp = minute;
        if (v == 0) (num == 2) ? arr[1] += minute - a_tmp : arr[2] += minute - b_tmp;
    }
    int mx = to_time("48:00");
    if (v > 0) arr[1] += mx - a_tmp;
    if (v < 0) arr[2] += mx - b_tmp;
    cout << to_min(arr[1]) << '\n';
    cout << to_min(arr[2]) << '\n';

}

