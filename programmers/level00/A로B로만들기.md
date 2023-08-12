# 프로그래머스 Lv.0 A로 B로 만들기

## solution 1 unordered_map 

```c++
#include "bits/stdc++.h"

using namespace std;

int solution(string before, string after) {
    unordered_map<char, int> b;
    unordered_map<char, int> a;
    for(auto be : before) b[be]++;
    for(auto af : after) a[af]++;
    if(a == b) return 1;
    return 0;
}
```