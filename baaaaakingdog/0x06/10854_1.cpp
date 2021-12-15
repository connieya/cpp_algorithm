#include "bits/stdc++.h"

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<int> queue;
    int n;
    cin >> n;
    while (n--) {
        string q;
        cin >> q;
        if(q=="push"){
            int val;
            cin >> val;
            queue.push(val);
            continue;
        }
        if(q=="pop"){
            if (queue.empty()){
                cout << -1 <<'\n';
            }else{
                cout << queue.front() <<'\n';
                queue.pop();
            }
            continue;
        }
        if (q=="empty"){
            cout << queue.empty() << '\n';
            continue;
        }
        if (q=="size"){
            cout << queue.size()<<'\n';
            continue;
        }
        if (q=="front"){
            if(queue.empty()){
                cout << -1 <<'\n';
            }else{
                cout << queue.front() << '\n';
            }
            continue;
        }
        if (q=="back"){
            if(queue.empty()){
                cout << -1 <<'\n';
            }else{
                cout << queue.back() << '\n';
            }
            continue;
        }
    }
}