#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a,b,c;
    cin >>a>>b>>c;
    int t = a*b*c;
    int d[10] = {};
    while (t>0){
        d[t%10]++;
        t /=10;
    }
    for(int n : d){
        cout << n <<'\n';
    }
}