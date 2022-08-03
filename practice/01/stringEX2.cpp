#include "bits/stdc++.h"

using namespace std;

int main() {
    string a = "it is time to study";
    string res;
    int pos;
    int max = -1;
    cout << a.find(' ') << '\n'; // 2번 인덱스
    cout << a.find('k') << '\n'; // 쓰레기값???
    cout << a.find('s') << '\n'; // 4번 인덱스
    cout << a.substr(2) << '\n';

    cout << (a.find('t') != string ::npos) << '\n'; // true   => t 가 포함되어 있니
    cout << (a.find('t') == string ::npos) << '\n'; // false => t가 없니?
    cout << (a.find('s') == string ::npos) << '\n'; // false => s가 없니?

    cout << "************************************" << '\n';
    while ((pos = a.find(' ')) != string::npos) {
        string tmp = a.substr(0,pos);
//        cout << tmp << '\n';
        if (int(tmp.size()) > max){
            max = int(tmp.size());
            res = tmp;
        }
        a = a.substr(pos+1);
    }
//    cout << a << '\n';
    if (a.size() > max) {
        res = a;
    }
    cout << "res => " << res << '\n';
}
