#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t,n;
    string ans;
    char ch;
    cin >> t;
    deque<char> q;
    while (t--) {
        cin >> n;
        cin >> ch;
        q.push_back(ch);
        for (int i = 1; i < n; ++i) {
            cin >> ch;
            if(ch <= q.front()){
                q.push_front(ch);
            }else {
                q.push_back(ch);
            }
        }
        while (!q.empty()){
            cout << q.front();
            q.pop_front();
        }
        cout <<  '\n';
    }


}