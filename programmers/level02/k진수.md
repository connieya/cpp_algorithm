# 프로그래머스 Lv.2 k진수에서 소수 개수 구하기

## solution 1

## stringstream

```c
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

string a = "";


void translate(int n , int k){
    if(n == 0) return ;
    translate(n/k,k);
    a += to_string(n%k);
}

bool isPrime(ll num){
    if(num <= 1) return false;
    if(num == 2) return true;
    for(ll i=2; i*i <= num; i++){
        if(num % i == 0) return false; 
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    translate(n,k);
    for(auto &ch : a){
        if(ch == '0') ch = ' ';
    }
    stringstream iss(a);
    string str;
    while(iss >> str){
        string tmp = str;
        if(!tmp.size()) continue;
        answer += isPrime(stoll(tmp));
    }
    return answer;
}
```

## solution 2

## 찐 구현


```c
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


bool isPrime(ll n){
    if(n < 2) return false;
    for(ll i = 2; i*i <= n; i++){
        if(n % i == 0) return false;
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    string str;
    while(n){
        str += n%k+'0';
        n /= k;
    }
    reverse(str.begin() , str.end());
    str += '0';
    ll res = 0;
    for(int i=0; i< str.size(); i++){
        if(str[i] == '0'){
            answer += isPrime(res);
            res = 0;
            continue;
        }
        res = res * 10 + str[i]-'0';
    }
    
    return answer;
}
```

## solution 3

```c
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


bool isPrime(ll n){
    if(n < 2) return false;
    for(ll i = 2; i*i <= n; i++){
        if(n % i == 0) return false;
    }
    return true;
}

string conv(int n, int k){
    string temp;
    for(; n; n /= k) temp.push_back(n % k | 48);
    reverse(temp.begin(), temp.end());
    return temp;
}

int solution(int n, int k) {
    int answer = 0;
    string s = conv(n,k);
    for(auto &i : s) if(i=='0') i = ' ';
    stringstream iss(s);
    for(ll t; iss >> t; answer += isPrime(t));
    
    return answer;
}
```
