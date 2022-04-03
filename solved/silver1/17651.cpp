#include "bits/stdc++.h"

using namespace std;

int solve(int n , string str) {
    int len = str.size();
    int cnt = 0;
    bool flag = false;
    if (n == 0) { // 빨간색을 왼쪽으로 모으는 경우
        for (int i = 0; i < len; ++i) {
            if (str[i] == 'B'){
                flag = true;
            }else {
                if (flag){
                    cnt++;
                }
            }
        }
        return cnt;
    }
    if (n == 1) { // 빨간색을 으론쪽으로 모으는 경우
        for (int i = len-1; i >=0; --i) {
            if (str[i] == 'B'){
                flag = true;
            }else {
                if (flag){
                    cnt++;
                }
            }
        }
        return cnt;
    }
    if (n == 2) { // 파란색을 왼쪽으로 모으는 경우
        for (int i = 0; i < len; ++i) {
            if (str[i] == 'R'){
                flag = true;
            }else {
                if (flag){
                    cnt++;
                }
            }
        }
        return cnt;
    }
    if (n == 3) { // 파란색을 오른쪽으로 모으는 경우
        for (int i = len; i >= 0; --i) {
            if (str[i] == 'R'){
                flag = true;
            }else {
                if (flag){
                    cnt++;
                }
            }
        }
        return cnt;
    }

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    string str;
    cin >> str;
    int ans = 500001;
    for (int i = 0; i < 4; ++i) {
        ans = min(ans, solve(i,str));
    }
    cout << ans;

}