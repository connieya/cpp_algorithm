﻿#include "bits/stdc++.h"

using namespace std;

int arr[1001][1001];
string A ,B;
string answer = "";

void traceBack(int a , int b ){
    if (a == 0 || b == 0 ) return;
    if (arr[a][b] > arr[a-1][b-1] && arr[a][b] > arr[a-1][b] && arr[a][b] > arr[a][b-1]){
        answer += A[a-1];
        traceBack(a-1,b-1);
    }else if(arr[a][b] > arr[a-1][b] && arr[a][b] == arr[a][b-1]){
        traceBack(a,b-1);
    }else {
        traceBack(a-1,b);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> A >> B;
    int len_A = A.length();
    int len_B = B.length();

    for (int i = 1; i <=len_A ; ++i) {
        for (int j = 1; j <= len_B; ++j) {
            if (A[i-1] == B[j-1]){
                arr[i][j] = arr[i-1][j-1] +1;
            }else {
                arr[i][j] = max(arr[i][j-1], arr[i-1][j]);
            }
        }
    }
    traceBack(len_A,len_B);
    reverse(answer.begin(),answer.end());
    cout << arr[len_A][len_B] << '\n';
    if (answer.length() >1){
        cout << answer;
    }
}