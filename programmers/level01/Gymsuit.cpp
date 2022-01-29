#include "bits/stdc++.h"

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n;
    int students[n+2];
    fill(students,students+n+2,1);
    for (int l : lost) {
        students[l]--;
    }
    for (int r: reserve) {
        students[r]++;
    }
    for (int i = 1; i <= n; ++i) {
        if (students[i] == 0){
            if (students[i-1] == 2){
                students[i-1] = 1;
                students[i] = 1;
                continue;
            }
            if (students[i+1] == 2) {
                students[i+1] = 1;
                students[i] =1;
                continue;
            }
        }
    }
    for (int i = 1; i <= n ; ++i) {
        if(students[i] == 0) {
            answer--;
        }
    }
    return answer;
}