#include "bits/stdc++.h"

using namespace std;

int calcWatt(int money) {
    if (money <= 200) {
        return money / 2;
    }
    if (money <= 29900) {
        return (money - 200) / 3 + 100;
    }
    if (money <= 4979900) {
        return (money - 29900) / 5 + 10000;
    }
    return (money - 4979900) / 7 + 1000000;
}

int calcMoney(int watt){
    if (watt <= 100){
        return watt*2;
    }
    if (watt <= 10000){
        return (watt-100)*3 + 200;
    }
    if (watt <= 1000000) {
        return (watt-10000)*5 +9900*3+200;
    }
    return (watt-1000000)*7 +990000*5+ 9900*3+200;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a, b;
    while (1) {
        cin >> a >> b;
        if (!a && !b) break;
        int totalWatt = calcWatt(a);
        int lt = 0;
        int rt = totalWatt/2;
        while (lt <= rt) {
            int mid = (lt +rt)/2;
            int s_price = calcMoney(mid);
            int d_price = calcMoney(totalWatt-mid);
            int sub = abs(s_price-d_price);
            if (sub > b){
                lt = mid+1;
            }else if (sub < b){
                rt = mid-1;
            }else {
                cout << calcMoney(mid) << '\n';
                break;
            }
        }
    }
}