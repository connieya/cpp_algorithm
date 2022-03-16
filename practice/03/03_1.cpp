#include "bits/stdc++.h"

using namespace std;

int ans[200000];
int team[26];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<pair<int,pair<int,char>>> students;
    int n , attack;
    char t;
    cin >> n;
    for (int i = 0; i < n; ++i) {
       cin >> t >> attack;
       students.push_back({attack,{i,t}});
    }
    sort(students.begin(),students.end());
    int len = students.size();
    int sum = 0 , j= 0;
    for (int i = 1; i < len; ++i) {
        for (; j < n;  j++) {
            if (students[i].first > students[j].first){
                sum += students[j].first;
                team[students[j].second.second-'a'] += students[j].first;
            }else {
                break;
            }
        }
        ans[students[i].second.first] = sum - team[students[i].second.second - 'a'];
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << '\n';
    }
}