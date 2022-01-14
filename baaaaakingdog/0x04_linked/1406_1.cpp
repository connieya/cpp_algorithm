#include "bits/stdc++.h"

using namespace std;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string init;
    cin >> init;
    list<char> editor;
    for (auto s: init) {
        editor.push_back(s);
    }
    auto cursor = editor.end();
    int q;
    cin >> q;
    while (q--) {
        char op;
        cin >> op;
        if(op == 'P'){
            char add;
            cin >> add;
            editor.insert(cursor,add);
            continue;
        }
        if (op == 'L' && cursor != editor.begin()) {
            cursor--;
            continue;
        }
        if (op == 'D' && cursor != editor.end()){
            cursor++;
            continue;
        }
        if (op == 'B' && cursor != editor.begin()) {
            cursor--;
            cursor = editor.erase(cursor);
        }
    }
    for (auto s: editor) {
        cout << s;
    }
}