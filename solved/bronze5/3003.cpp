#include "bits/stdc++.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int chess[] = {1, 1, 2, 2, 2, 8};
    int arr[6];
    for (int i = 0; i < 6; ++i) {
        cin >> arr[i];
        arr[i] = chess[i]-arr[i];
    }
    for (int i = 0; i < 6; ++i) {
        cout << arr[i] << ' ';
    }
}