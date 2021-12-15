#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        bool isReverse = false, isError = false;
        deque<int> deque;
        string p;
        int num;
        string arr;
        cin >> p >> num >> arr;
        int res = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] >= '0' && arr[i] <= '9') {
                res = res * 10 + (arr[i] - '0');
            } else {
                if (res != 0) {
                    deque.push_back(res);
                    res = 0;
                }
            }
        }
        for (int i = 0; i < p.size(); ++i) {
            if (p[i] == 'R') {
                isReverse = !isReverse;
            } else {
                if (deque.empty()) {
                    isError = true;
                    break;
                }else if(isReverse){
                    deque.pop_back();
                }else if(!isReverse){
                    deque.pop_front();
                }
            }
        }
        if (isError) {
            cout << "error\n";
        }else {
            if (isReverse){
                reverse(deque.begin(),deque.end());
            }
            cout << '[';
            for(int i = 0; i < deque.size(); i++)
            {
                cout << deque[i];
                if(i+1 != deque.size())
                    cout << ',';
            }
            cout << "]\n";
        }
    }
}