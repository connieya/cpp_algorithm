#include "bits/stdc++.h"

using namespace std;

int parent[3001];
int arr[3001][3];

int find(int a) {
    if (a==parent[a]) return a;
    return parent[a] = find(parent[a]);
}

void Union(int a, int b){
    a = find(a);
    b = find(b);
    if (a != b) {
        parent[a] = b;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        }
        for (int i = 1; i <= n; ++i) {
            cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
        }
        int ans = n;
        for (int i = 1; i <= n; ++i) {
            for (int j = i+1; j <= n; ++j) {
                int R = (arr[i][2]+arr[j][2])*(arr[i][2]+arr[j][2]);
                int distance = (arr[i][1]-arr[j][1])*(arr[i][1]-arr[j][1])+ (arr[i][0]-arr[j][0])*(arr[i][0]-arr[j][0]);
                if (R >= distance && find(i)!= find(j)){
                    ans--;
                    Union(i,j);
                }
            }
        }
        cout << ans << '\n';
    }
}