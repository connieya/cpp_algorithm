#include "bits/stdc++.h"

using namespace std;

void to_binary(int num) {
    if (num == 0) {
        cout << '\n';
        return;
    }
    to_binary(num / 2);
    cout << num % 2;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<string> v;
    v.push_back("sdsd");
    v.push_back("sssdsd");
    v.push_back("11sdsd");
    v.push_back("s33sssdsd");

    for(auto s : v){
        cout << s << ' ';
    }


}