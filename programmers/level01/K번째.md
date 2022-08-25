# 프로그래머스 Lv.1 K번째 수

## solution 1

```c++
#include "bits/stdc++.h"

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> tmp;
    int len = commands.size();
    for (int i = 0; i < len; ++i) {
        int start = commands[i][0]-1;
        int end = commands[i][1];
        int k = commands[i][2]-1;
        tmp = array;
        sort(tmp.begin()+start,tmp.begin()+end);
        answer.push_back(tmp[commands[i][0] + commands[i][2]-2]);
    }
    return answer;
}
```

## solution 2

```c++
#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> tmp;
    for(auto command : commands){
        tmp = array;
        sort(tmp.begin()+command[0]-1 , tmp.begin()+command[1]);
        answer.push_back(tmp[command[0] + command[2]-2]);
    }
    return answer;
}
```