#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string str = "abcdeddsfsds";
    str.erase(2); // 인덱스 2 뒤로 모두 다 지움
    cout << str << '\n'; // => ab
    str = "abcdeddsfsds";
    str.erase(2,1); // 인덱스 2 부터 1개 지움
    cout << str << '\n'; // => abdeddsfsds
    str = "abcdeddsfsds";
    str.erase(4,3); //  인덱스 4부터 3개 지움
    cout << str << '\n'; // => abcdsfsds
}