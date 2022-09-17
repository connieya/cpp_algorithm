# 프로그래머스 Lv.2 N-Queen 

## solution 1

```c++
#include <bits/stdc++.h>

using namespace std;

bool v1[13];
bool v2[30];
bool v3[30];

int dfs(int L, int n) {
    if(L == n){
        return 1;
    }
    int cnt = 0;
    for(int i=0; i<n; i++){
        if(v1[i] || v2[L+i] || v3[L-i+n-1]) continue;
        v1[i] = v2[L+i] = v3[L-i+n-1] = true;
        cnt += dfs(L+1,n);
        v1[i] = v2[L+i] = v3[L-i+n-1] = false;
        
    }
    return cnt;
}

int solution(int n) {
    return dfs(0,n);
}
```