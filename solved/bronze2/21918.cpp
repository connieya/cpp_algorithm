#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m,a,b,c;
    bool light[4000];
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> light[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        if(a == 1){
            light[b-1] = c;
        }else if(a==2){
            for (int j = b-1; j <c; ++j) {
                light[j] = !light[j];
            }
        }else if(a==3){
            for (int j = b-1; j < c; ++j) {
                light[j] = 0;
            }
        }else {
            for (int j = b-1; j < c; ++j) {
                light[j] = 1;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << light[i] << ' ';
    }
}