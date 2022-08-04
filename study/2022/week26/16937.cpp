#include "bits/stdc++.h"

using namespace std;
int h,w,n;

int stick(int x ,int y , vector<pair<int,int>> &v){
    auto a = v[x];
    auto b = v[y];
    int x1 = a.first , y1 = a.second;
    int x2 = b.first , y2 = b.second;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            if((x1+x2 <= h && max(y1,y2) <= w )|| (x1+x2 <= w && max(y1,y2) <= h) ){
               return x1*y1+x2*y2;
            }
            swap(x1,y1);
        }
        swap(x2,y2);
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> h >> w >> n;
    vector<pair<int,int>> v;
    for (int i = 0; i < n; ++i) {
        int a,b;
        cin >> a >> b;
        v.push_back({a,b});
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            ans = max(ans ,stick(i,j,v));
        }
    }
    cout << ans;
}