#include "bits/stdc++.h"

#define t true
#define f false
using namespace std;
int n, k, p, target;

bool LED[10][8] = {
        {t, t, t, t, t, t, f}, // 0 -> 1111110
        {f, f, t, t, f, f, f}, // 1  -> 0011000
        {f, t, t, f, t, t, t}, // 2
        {f, t, t, t, t, f, t}, //3
        {t, f, t, t, f, f, t}, // 4
        {t, t, f, t, t, f, t}, // 5
        {t, t, f, t, t, t, t}, // 6
        {f, t, t, t, f, f, f}, // 7
        {t, t, t, t, t, t, t}, // 8
        {t, t, t, t, t, f, t} // 9
};

//int led[] = {
//        0b1111110, // 0
//        0b0011000, // 1
//        0b0110111, // 2
//        0b0111101, // 3
//        0b1011001, //4
//        0b1101110, // 5
//        0b1101111, // 6
//        0b0111000, // 7
//        0b1111111, // 8
//        0b1111101 //  9
//};

int diff_one(int floor , int target){
    int res =0; // 한 자리 수 층 끼리 비교
    for (int i = 0; i < 7; ++i) {
        res += (LED[floor][i] != LED[target][i]);

    }
    if (res > p) return -1;
    return res;
}

int diff(int floor , int target){ // 각 자리수 비교함  ex ) 456 층이랑 3층
    int res = 0;
    for (int i = 1; i <=k; ++i) { // 디스플레이 최대 k 자리 수
        int cnt = diff_one(floor%10,target%10);
        if (cnt == -1) return -1;
        res += cnt; // 자리수 마다 다 비교
        floor /= 10;
        target /=10;
    }
    return res;
}

void solve(){
    int ans = 0;
    for (int floor = 1; floor <= n; ++floor) {
        if (floor == target) continue;
        int cnt = diff(floor,target);
        if (cnt == -1) continue;
        if (cnt <= p) ans++; // target 을 x 로 바꿀 수 있는가?
        // 그리고 그 횟수가 p 이하로 가능한가?
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k >> p >> target;
    solve();
}