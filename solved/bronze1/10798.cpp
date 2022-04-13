#include "bits/stdc++.h"

using namespace std;

char blackboard[5][15];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int i = 0; i < 5; ++i) {
        cin >> blackboard[i];
    }
    for (int i = 0; i < 15; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (blackboard[j][i]){
                cout << blackboard[j][i];
            }

        }
    }
}