#include "bits/stdc++.h"
#define INF 10001

using namespace std;

int n1[INF],n2[INF];
vector<int> v;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string a,b;
    cin >> a >> b;
    for (int i = 0; i < a.length(); ++i) {
        n1[i] = a[i]-'0';
    }
    for (int i = 0; i < b.length(); ++i) {
        n2[i] = b[i]-'0';
    }
    int a_len = a.length();
    int b_len = b.length();
    a_len-- , b_len--;
    while (a_len>=0 && b_len>=0){
        v.push_back(n1[a_len]+n2[b_len]);
        a_len--, b_len--;
    }
    while (a_len >= 0){
        v.push_back(n1[a_len]);
        a_len--;
    }
    while (b_len >= 0){
        v.push_back(n2[b_len]);
        b_len--;
    }
    int v_size = v.size();
    for (int i = 0; i < v_size; ++i) {
        if (i == v_size-1)continue;
        v[i+1] += v[i]/10;
        v[i] = v[i]%10;
    }
    reverse(v.begin(),v.end());
    for (int a : v) {
        cout << a;
    }
}