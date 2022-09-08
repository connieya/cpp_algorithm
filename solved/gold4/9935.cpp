#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string a ,b;
    cin >> a >> b;
    int len = b.size();
    stack<char> s;
    for(auto ch : a){
        s.push(ch);
        if(s.size() >= len){
            string str = "";
            int tmp = len;
            while (tmp){
                str += s.top();
                s.pop();
                tmp--;
            }
            reverse(str.begin() , str.end());
            if(str != b){
                for(auto ch : str){
                    s.push(ch);
                }
            }
        }
    }
    string answer ="";
    while (!s.empty()){
        answer += s.top();
        s.pop();
    }
    reverse(answer.begin() , answer.end());
    cout << (answer.size() ? answer : "FRULA");
}