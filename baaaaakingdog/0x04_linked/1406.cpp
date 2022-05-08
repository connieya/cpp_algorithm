#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string str;
    int n;
    cin >> str >> n;
    list<char> editor(str.begin() , str.end());
    auto it = editor.end();
    while (n--){
        char cmd , x;
        cin >> cmd;
        if (cmd == 'L' && it != editor.begin()){
            it--;
        }else if (cmd == 'D' && it != editor.end()){
            it++;
        }else if (cmd == 'B' && it != editor.begin()){
            it = editor.erase(prev(it));
        }else if (cmd == 'P'){
            cin >> x;
            editor.insert(it,x);
        }
    }

    cout << string(editor.begin() , editor.end());
}