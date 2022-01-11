#include "bits/stdc++.h"

using namespace std;

int main(void) {
    string new_id = "...!@BaT#*..y.abcdefghijklm";
    string answer = "";
    for (char &ch: new_id) {
        if (ch >= 'a' && ch <= 'z') {
            answer += ch;
        }
        if (ch >= 'A' && ch <= 'Z') {
            ch += 32;
            answer += ch;
        }
        if (ch >= '1' && ch <= '9') {
            answer += ch;
        }
        if (ch == '-' || ch == '_' || ch == '.') {
            answer += ch;
        }
    }
    new_id = answer;
    answer.clear();
    for(char &ch : new_id) {
        if(!answer.empty() && answer.back()=='.' && ch == '.'){
            continue;
        }
        answer += ch;
    }

    cout << answer << '\n';
    if(answer.front() == '.') answer.erase(answer.begin());
    if(answer.back() == '.') answer.pop_back();
    if(answer.empty()) answer = "a";
    cout << answer << '\n';
    if(answer.length() >= 16) answer = answer.substr(0,15);
    cout << answer << '\n';
    if(answer.back() == '.') answer.pop_back();
        while(answer.length() <=2) {
            answer += answer.back();
        }

    cout << answer << '\n';


}