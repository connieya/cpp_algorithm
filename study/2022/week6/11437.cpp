#include "bits/stdc++.h"

using namespace std;

int arr[50001];

int find(int a);
void Union(int a , int b);

int find(int a){
    if (a == arr[a]){
        return a;
    }
    return arr[a] = find(arr[a]);
}

void Union(int a ,int b){
    int aa = find(a);
    int bb = find(b);
    arr[aa] = bb;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        arr[i] = i;
    }
    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        Union(a,b);
    }
    for (int i = 1; i <= n; ++i) {
        cout << i << ":" << arr[i] << ' ';
    }

}