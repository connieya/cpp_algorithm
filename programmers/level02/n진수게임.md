# 프로그래머스 Lv.2 n진수 게임


## Solution 1

```c
#include <bits/stdc++.h>

using namespace std;

string str = "";
string init = "0123456789ABCDEF";

void toNotation(int num , int n){
    if(num == 0) return;
    toNotation(num/n, n);
    str += init[num%n];
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    str += "0";
    for(int i=0; i<=t*m*p; i++){
        toNotation(i,n);
    }
    int len = str.size();
    
    for(int i = p-1; i < len; i += m){
        answer.push_back(str[i]);
        if(answer.length() == t) break;
    }
    return answer;
}
```