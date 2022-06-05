# 프로그래머스 Lv.3 N으로 표현

## solution 1

```c
#include <bits/stdc++.h>

using namespace std;

int solution(int N, int number) {
    if(N == number ) return 1;
    vector<unordered_set<int>> dp(8);
    dp[0].insert(N);
    
    int res = N;
    for(int i=1; i<8; i++) {
        res = res*10 + N;
        dp[i].insert(res);
        for(int j=0; j<i; j++){
            for(int k=0; k<i; k++){
                if(j+k+1 != i) continue;
                
                for(int num1 : dp[j]){
                    for(int num2 : dp[k]) {
                        dp[i].insert(num1+num2);
                        if(num1-num2 > 0){
                            dp[i].insert(num1-num2);
                        }
                        dp[i].insert(num1*num2);
                        if(num1/num2) {
                            dp[i].insert(num1/num2);
                        }
                    }
                }
                
            }
        }
        if(dp[i].find(number) != dp[i].end()) return i+1;
    }
    
    return -1;
}
```

## solution 2

```c
#include <bits/stdc++.h>

using namespace std;

unordered_set<int> cache[10];

int solution(int N, int number) {
    int res = N;
    for(int i=1; i<=8; i++) {
        cache[i].insert(res);
        
        for(int j=1; j<i; j++){
            int k = i-j;
            for(auto num1 : cache[j]){
                for(auto num2 : cache[k]){
                    cache[i].insert(num1+num2);
                    cache[i].insert(num1*num2);
                    if(num1/num2) cache[i].insert(num1/num2);
                    if(num1-num2 > 0) cache[i].insert(num1-num2);
                }
            }
        }
        
        if(cache[i].find(number) != cache[i].end()) return i;
        res = res*10 +N;
    }
    return -1;
}
```