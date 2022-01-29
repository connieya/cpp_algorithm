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
        answer.push_back(tmp[k]);
    }
    return answer;
}