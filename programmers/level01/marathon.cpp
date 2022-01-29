#include "bits/stdc++.h"

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    sort(participant.begin(),participant.end());
    sort(completion.begin(),completion.end());
    int len = completion.size();
    for (int i = 0; i < len; ++i) {
        if(participant[i] != completion[i]){
            return participant[i];
        }
    }
    return participant[len];
}