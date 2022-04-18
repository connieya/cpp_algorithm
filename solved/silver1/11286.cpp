#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    priority_queue<int> pq1; // 음수를 저장하는 pq;
    priority_queue<int> pq2; // 양수를 저장하는 pq;
    while (n--) {
        int value;
        cin >> value;
        if (value > 0){
            pq2.push(-value);
        }else if (value < 0) {
            pq1.push(value);
        }else {
            if (!pq1.empty() && pq2.empty()){
                cout << pq1.top() << '\n';
                pq1.pop();
            } else if (pq1.empty() && !pq2.empty()) {
                cout << -pq2.top() << '\n';
                pq2.pop();
            }else if(!pq1.empty() && !pq2.empty()){
                if (pq1.top() >= pq2.top()){
                    cout << pq1.top() << '\n';
                    pq1.pop();
                }else {
                    cout << -pq2.top() << '\n';
                    pq2.pop();
                }
            }else{
                cout << 0 << '\n';
            }
        }
    }

}