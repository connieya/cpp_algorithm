﻿#include "bits/stdc++.h"

using namespace std;
int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 0;
    int len = absolutes.size();
    for (int i = 0; i < len; ++i) {
        answer += (signs[i] == true) ? absolutes[i] : -absolutes[i];
    }
    return answer;
}