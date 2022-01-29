﻿#include "bits/stdc++.h"
using namespace std;

bool prime[3000];

void init() {
    fill(prime , prime+3000 ,true);
    prime[1] = false;
    for (int i = 2; i*i <=3000 ; ++i) {
        if (!prime[i]) continue;

        for (int j = i*i; j <= 3000; j+=i){
            prime[j] = false; // 소수가 아님
        }
    }

}

int solution(vector<int> nums) {
    int answer = 0;
    init();
    int len = nums.size();
    for (int i = 0; i < len - 2; ++i) {
        for (int j = i+1; j < len - 1; ++j) {
            for (int k = j+1; k < len; ++k) {
                int sum = nums[i]+nums[j] +nums[k];
                if (prime[sum]){
                    answer++;
                }
            }
        }
    }
    return answer;
}