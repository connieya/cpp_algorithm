#include "bits/stdc++.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    priority_queue<int> max_q;
    priority_queue<int ,vector<int> , greater<int>> min_q;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        if (max_q.size() > min_q.size()) {
            min_q.push(num);
        } else {
            max_q.push(num);
        }
        if (!max_q.empty() && !min_q.empty()) {
            if (max_q.top() > min_q.top()) {
                int mx = max_q.top();
                int mn = min_q.top();
                max_q.pop();
                min_q.pop();
                max_q.push(mn);
                min_q.push(mx);
            }
        }

        cout << max_q.top() << '\n';
    }

}