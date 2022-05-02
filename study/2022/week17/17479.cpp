﻿#include "bits/stdc++.h"

using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    unordered_map<string, ll> food_price;
    unordered_map<string, string> menu;
    int a, b, c, price, n;
    ll o_price = 0, s_price = 0;
    string name;
    int flag = 0;
    cin >> a >> b >> c;
    for (int i = 0; i < a; ++i) {
        cin >> name >> price;
        food_price[name] = price;
        menu[name] = "a";
    }
    for (int i = 0; i < b; ++i) {
        cin >> name >> price;
        food_price[name] = price;
        menu[name] = "b";
    }
    for (int i = 0; i < c; ++i) {
        cin >> name;
        menu[name] = "c";
    }

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> name;
        string m = menu[name];
        if (m == "a") {
            o_price += food_price[name];
            continue;
        }
        if (m == "b") {
            s_price += food_price[name];
            continue;
        }
        if (m == "c") {
            flag++;
        }
    }
    if (o_price < 20000 && s_price > 0) {
        cout << "No";
    } else if (o_price + s_price < 50000 && flag > 0) {
        cout << "No";
    } else if (flag > 1) {
        cout << "No";
    } else {
        cout << "Okay";
    }

}