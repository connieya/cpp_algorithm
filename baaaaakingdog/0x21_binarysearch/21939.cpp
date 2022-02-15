#include "bits/stdc++.h"

using namespace std;

int arr[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    priority_queue<pair<int, int>> mx_pq;
    priority_queue<pair<int, int>> mn_pq;
    int n ,num ,rank , v;
    cin >> n;
    while (n--) {
        cin >> num >> rank;
        arr[num] = rank;
        mx_pq.push({rank, num});
        mn_pq.push({-rank, -num});
    }
    cin >> n;
    while (n--) {
        string command;
        cin >> command;
        if (command == "recommend") {
            cin >> v;
            if (v == 1) {
                while (arr[mx_pq.top().second] != mx_pq.top().first) {
                    mx_pq.pop();
                }
                cout << mx_pq.top().second << '\n';
            }else {
                while (arr[-mn_pq.top().second] != -mn_pq.top().first) {
                    mn_pq.pop();
                }
                cout << -mn_pq.top().second << '\n';
            }

        } else if (command == "add") {
            cin >> num >> rank;
            arr[num] = rank;
            mx_pq.push({rank, num});
            mn_pq.push({-rank, -num});
        } else {
             cin >> num;
             arr[num] = 0;
        }
    }
}