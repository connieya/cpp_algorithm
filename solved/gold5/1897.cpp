#include "bits/stdc++.h"

using namespace std;

vector<string> words;
string ans;

void bfs(string first) {
    queue<string> Q;
    Q.push(first);
    while (!Q.empty()) {
        string target = Q.front();
        ans = target;
        Q.pop();
        for (int i = 0; i<words.size(); i++) {
            if (words[i].length() != target.length() + 1) continue;
            if (words[i].find(target) != string::npos) {
                Q.push(words[i]);
                continue;
            }
            int idx = 0;
            int t_idx = 0;
            while (idx < words[i].length()){
                if (words[i][idx] == target[t_idx]){
                    t_idx++;
                }
                idx++;
            }
            if (t_idx == target.length()) {
                Q.push(words[i]);
            }
        }
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    string str, input;
    cin >> n >> str;
    while (n--) {
        cin >> input;
        words.push_back(input);
    }
    sort(words.begin(),words.end());
    bfs(str);
    cout << ans;
}