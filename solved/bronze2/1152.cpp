#include "bits/stdc++.h"

using namespace std;

char a[1000001];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin.getline(a,1000000);
    int cnt = 0,i;
    for ( i = 0; a[i]; ++i) {
        if (a[i] == ' ') cnt++;
    }
    if (a[0] != ' '){
        cnt++;
    }
    if(a[i-1] == ' '){
        cnt--;
    }
    cout << cnt;

}