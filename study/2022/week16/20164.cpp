#include "bits/stdc++.h"

using namespace std;

int mn =INT_MAX , mx;

int getOddCount(int num){
    int res =0;
    while (num){
        res += num%2;
        num /= 10;
    }
    return res;
}


void dfs(int num , int cnt)
{
    cnt += getOddCount(num);
    if (num < 10){
        mn = min(mn,cnt);
        mx = max(mx,cnt);
        return;
    }
    if (num< 100){
        dfs(num%10+num/10 ,cnt);
    }else {
        string str = to_string(num);
        for (int i = 1; i < str.size()-1;  ++i) {
            for (int j = i+1; j < str.size(); ++j) {
                string l = str.substr(0,i);
                string m = str.substr(i,j-i);
                string r = str.substr(j);
                dfs(stoi(l)+ stoi(m)+ stoi(r),cnt);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int num;
    cin >> num;
    dfs(num,0);
    cout << mn << ' ' << mx;
}