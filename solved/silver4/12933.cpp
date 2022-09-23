#include "bits/stdc++.h"

using namespace std;

bool checked[2501];
int cnt[2501];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string str;
    cin >> str;
    int n = str.size();
    int ans = 0;
    bool flag = false;
    string duck = "quack";
    for (int i = 0; i < n; ++i) {
        if(str[i] != 'q') continue;
        int idx1 = i;
        int idx2 = 0;
        while (idx1 < n && idx2< 5){
            if(!checked[idx1] && duck[idx2] == str[idx1]){
                checked[idx1] = 1;
                idx2++;
            }
            idx1++;
        }
        if(idx2 != 5) flag = true;
        for (int j = i; j < idx1; ++j) {
            cnt[j]++;
        }
    }
    for (int i = 0; i < n; ++i) {
        ans = max(ans, cnt[i]);
        if(!cnt[i]) flag = true;
    }
    cout << (flag ? -1 : ans);
}