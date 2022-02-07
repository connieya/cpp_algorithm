#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N,L ,x = -1,len = -1;
    cin >> N >> L;
    for (int i = L; i <= 100; ++i) {
        int tmp =  i*(i+1)/2;
        if((N-tmp ) %  i == 0 && (N-tmp)/i >= 0){
            x = (N-tmp)/i;
            len = i;
            cout << tmp << ' ' << x << ' ' << len << '\n';
            break;
        }
    }
    if(x ==-1){
        cout << -1;
    }else {
        for (int i = 0; i < len; ++i) {
            cout << x+i << ' ';
        }
    }

}