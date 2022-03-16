#include "bits/stdc++.h"

using namespace std;

struct Student {
    int index, power;
    char team;

    Student(int i, char t, int p) {
        index = i;
        team = t;
        power = p;
    }

    bool operator<(const Student &s) const {
        return power < s.power;
    }
};

int ans[200001];
int team[26];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, power;
    char t;
    cin >> n;
    vector<Student> st;
    for (int i = 0; i < n; ++i) {
        cin >> t >> power;
        st.push_back(Student(i, t, power));
    }
    sort(st.begin(), st.end());
    int j = 0;
    int sum = 0;
    for (int i = 1; i < n; ++i) {
        for (; j < n; j++) {
            if (st[i].power > st[j].power){
                sum += st[j].power;
                team[st[j].team-'a'] += st[j].power;
            }else {
                break;
            }
        }
        ans[st[i].index] = sum - team[st[i].team- 'a'];
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << '\n';
    }
}