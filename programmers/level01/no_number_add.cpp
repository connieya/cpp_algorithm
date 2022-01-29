#include "bits/stdc++.h"

using namespace std;

int solution(vector<int> numbers) {
    int answer =45;

    return answer - accumulate(numbers.begin(),numbers.end(),0);
}