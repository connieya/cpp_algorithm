#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s = "abcabcabcabcdededededede";
    int answer = s.length();
    cout << s.length() <<' ' << s.size() << '\n';
    cout << s.substr(4,2) << '\n';
    for (int i = 1; i < s.size(); ++i) { // 문자열 1개 부터 하나씩 압축 시작
        int cnt = 1;
        string prev = s.substr(0,i); // 문자열 압축 시작
        string compress = "";
        for (int j = i; j < s.size(); j+=i) {
            if (prev == s.substr(j,i)) {
                cnt++;
                prev = s.substr(j,i);
            }else {
                compress += (cnt >= 2) ? to_string(cnt)+prev : prev;
                cnt = 1;
                prev = s.substr(j,i);
            }
        }
        compress += (cnt >= 2) ? to_string(cnt)+prev : prev;
        answer = min(answer, (int)compress.length());
    }
    cout << answer;
}