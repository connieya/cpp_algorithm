#include "bits/stdc++.h"

using namespace std;

string str;
bool checked[51];
vector<int> V;
void printShortLen(string input) {
    int len = input.length();
    for (int i = 0; i < len; ++i) {
        cout << input[i] << ' ';
    }
}

void dfs(int start, int maxNum) {
    string s  = "";
    for (int i = start; i < str.length(); ++i) {
        s  = s + str[i];
        cout << s << '\n';
        int num = stoi(s);
        if (num <= maxNum && !checked[num]){
            V.push_back(num);
            dfs(i+1,maxNum);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string input;
    cin >> input;
    int len = input.length();
    if (len < 10) {
        printShortLen(input);
    } else {
        len = (len - 9) / 2;
        int maxNum = len + 9;
        str = input;
        dfs(0, maxNum);
        for (int i = 0; i < V.size(); ++i) {
            cout << V[i] << ' ';
        }
    }
}