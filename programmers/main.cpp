#include "bits/stdc++.h"

using namespace std;

int dist[104][104];


void func(int dist[]){
    for (int i = 0; i <=4 ; ++i) {
        dist[i] = -1;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    set<string> s;
    s.insert("Dd");

    func(dist[1]);
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }

}