#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<string> record = {"Enter uid1234 Muzi", "Enter uid4567 Prodo", "Leave uid1234", "Enter uid1234 Prodo",
                             "Change uid4567 Ryan"};
    unordered_map<string, string> um;
    vector<string> answer;
    for (string s: record) {
        stringstream st(s);
        string s1, s2, s3;
        st >> s1 >> s2 >> s3;
        if (s1 != "Leave") {
            um[s2] = s3;
        }
    }
    for (string s: record) {
        stringstream st(s);
        string s1, s2, s3;
        st >> s1 >> s2 >> s3;
        string str;
        if (s1 == "Change") continue;
        if (s1 == "Leave") {
            str = um[s2] + "님이 나갔습니다.";
        } else if (s1 == "Enter") {
            str = um[s2] + "님이 들어왔습니다.";

        }
        answer.push_back(str);
    }
    for (string s: answer) {
        cout << s << '\n';
    }
}