#include "bits/stdc++.h"

using namespace std;


int clock_num(int value) {
    int min = value;
    for (int i = 0; i < 3; ++i) {
        value = value % 1000 * 10 + value / 1000;
        if (min > value) {
            min = value;
        }
    }
    return min;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    int target = clock_num(a*1000+b*100+c*10+d);
    int ans = 0;
    for(int i = 1111; i <= target; i++){
        ans += clock_num(i) == i;
    }
    cout << ans;
}