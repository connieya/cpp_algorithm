#include "bits/stdc++.h"

using namespace std;

int solve(int n, string question) {
    int ans = 1;
    bool flag = false;
    for (int i = 0; i < n; ++i) { // 빨간색 전부 칠한 뒤 파란색 찾기
        if (question[i] == 'B' && !flag) {
            flag = true;
            ans++;
            continue;
        }
        if (question[i] == 'R'){
            flag = false;
        }
    }
    int cnt =1;
    flag = false;
    for (int i = 0; i < n; ++i) { // 파란색 전부 칠한 뒤 빨간색 찾기
        if (question[i] == 'R' && !flag) {
            flag = true;
            cnt++;
            continue;
        }
        if (question[i] == 'B'){
            flag = false;
        }
    }
    return min(ans,cnt);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    string question;
    cin >> n >> question;
    cout << solve(n,question);

}