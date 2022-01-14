#include "bits/stdc++.h"

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string init;
    cin >> init;
    list<char> L;
    for (auto c : init) {
        L.push_back(c);
    }
    auto cursor = L.end();
    int q;
    cin >> q;
    while (q--) {
        char op;
        cin >> op;
        if(op == 'P'){
            char add;
            cin >> add;
            L.insert(cursor,add);
            continue;
        }
        if(op == 'L'){
            if(cursor != L.begin()){
                cursor--;
            }
            continue;
        }
        if(op == 'D'){
            if(cursor != L.end()){
                cursor++;
            }
            continue;
        }
        if (op == 'B') {
            if (cursor != L.begin()){
                cursor--;
                cursor = L.erase(cursor);
            }
            continue;
        }
    }
    for (auto c : L){
        cout << c;
    }
}