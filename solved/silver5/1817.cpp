#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, v , ans = 0 , weight;
    cin >> n >> v;
    int box = v;
    for (int i = 0; i < n; ++i) {
        cin >> weight;
        if (box + weight > v){
                ans++;
                box = weight;
        }else {
            box += weight;
        }
    }
    cout << ans;

}