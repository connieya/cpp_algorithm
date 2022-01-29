#include "bits/stdc++.h"

using namespace std;

vector<int> solution(vector<int> answers) {
    int student_1[] = {1, 2, 3, 4, 5};  // 5개
    int student_2[] = {2, 1, 2, 3, 2, 4, 2, 5}; // 8개
    int student_3[] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}; // 10개
    int students[3] = {0,};

    vector<int> answer;
    int len = answers.size();
    int MX = -1;
    for (int i = 0; i < len; ++i) {
        int ans = answers[i];
        if (ans == student_1[i % 5]) {
            students[0]++;
        }
        if (ans == student_2[i % 8]) {
            students[1]++;
        }
        if (ans == student_3[i % 10]) {
            students[2]++;
        }
        MX = max({students[0], students[1], students[2]});

    }
    for (int i = 0; i < 3; ++i) {
        if (MX == students[i]) {
            answer.push_back(i+1);
        }
    }
    return answer;
}