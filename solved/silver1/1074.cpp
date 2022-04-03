#include "bits/stdc++.h"

using namespace std;


int cnt;

void recursive(int n) {
    if (n==1) return;
    recursive(n/2);
    for (int i = 0; i < ; ++i) {
        
    }
    cout << n << '\n';
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,r,c;
    cin >> n >> r >> c;
    int g = 1;
    for (int i = 0; i < n; ++i) {
        g *= 2;
    }
    cout << g << '\n';
    recursive(g);

}