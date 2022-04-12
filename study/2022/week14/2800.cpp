#include "bits/stdc++.h"

using namespace std;

string str;
bool visited[202];
vector<pair<int, int>> bracket;
vector<string> ans;

void init(int n) {
    for (int i = 0; i < n; ++i) {
        visited[i] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> str;
    int len = str.size();
    stack<int> S;
    for (int i = 0; i < len; ++i) {
        if (str[i] == '(') {
            S.push(i);
        } else if (str[i] == ')') {
            bracket.push_back({S.top(), i});
            S.pop();
        }
    }
    int size = bracket.size();
    for (int i = 1; i < (1 << size); ++i) {
        init(len);
        for (int j = 0; j < size; ++j) {
            if (i & (1 << j)) {
                visited[bracket[j].first] = true;
                visited[bracket[j].second] = true;
            }
        }
        string tmp = "";
        for (int j = 0; j < len; ++j) {
            if (!visited[j]) {
                tmp += str[j];
            }
        }
        ans.push_back(tmp);
    }
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    for (string a: ans) {
        cout << a << '\n';
    }
}