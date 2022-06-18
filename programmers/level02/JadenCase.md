# 프로그래머스 Lv.2 JadenCase 문자열 만들기

## solution 1

```c
#include <bits/stdc++.h>

using namespace std;

string solution(string s) {
    for(auto &ch : s){
        ch = tolower(ch);
    }
    s[0] = toupper(s[0]);
    for(int i=1; i<s.size(); i++){
        if(s[i-1] == ' '){
            s[i] = toupper(s[i]);
        }
    }
    return s;
}
```