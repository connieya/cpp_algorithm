# 프로그래머스 Lv.2 H-Index


## solution 1

```c
#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> citations) {
    sort(citations.begin() , citations.end());
    int len = citations.size();
    for(int i=0; i<len; i++){
        int H_Index = len -i;
        if(citations[i] >= H_Index) return H_Index;
    }
    return 0;
}
```