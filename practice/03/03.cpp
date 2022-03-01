#include "bits/stdc++.h"

using namespace std;

struct student {
    int index;
    char team;
    int power;

    student(int i , char t , int p){
        index = i;
        team = t;
        power = p;
    }
    bool operator<(const student &s)const {
        return power - s.power;
    }
};

int ans[200001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<student> st;
    for (int i = 0; i < n; ++i) {
        char team;
        int power;
        cin >> team >> power;
        st.push_back(student(i, team, power));
    }
    sort(st.begin(),st.end());
    for (student s: st) {
        cout << s.index << ' ' << s.team << ' ' << s.power << '\n';
    }
}