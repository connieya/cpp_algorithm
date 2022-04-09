#include "bits/stdc++.h"

using namespace std;

vector<pair<pair<int,int> ,string>> question;

bool duplicate_number(int num) {
    return num/100 == (num/10)%10 || num/100 == num%10 || (num/10)%10 == num%10;
}

bool checkBallCount(string think_num , string check_num ,int s ,int b){
    int strike = 0 , ball = 0;
    for (int i = 0; i < think_num.length(); ++i) {
        for (int j = 0; j < check_num.length(); ++j) {
            if (think_num[i] == check_num[j] && i == j){
                strike++;
            }else if (think_num[i] == check_num[j] && i !=j){
                ball++;
            }
        }
    }
    if (strike == s && ball == b) return true;
    return false;

}

bool solve(int n) {
    int len = question.size();
    for (int i = 0; i < len; ++i) {
        if(!checkBallCount(to_string(n), question[i].second ,question[i].first.first,question[i].first.second)){
            return false;
        }

    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,strike,ball ,ans = 0;
    string num;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> num >> strike >> ball;
        question.push_back({{strike,ball},num});
    }
    for (int i = 123; i <=987 ; ++i) {
        if (i%10 == 0 || (i/10)%10 == 0) continue;
        if (duplicate_number(i)) continue;
        if (solve(i)) ans++;
    }
    cout << ans;

}