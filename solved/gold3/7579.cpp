#include "bits/stdc++.h"

using namespace std;

int memory[101];
int cost[101];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> memory[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> cost[i];
    }
}