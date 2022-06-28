#include "bits/stdc++.h"

using namespace std;

int n;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    map<string, int> m =
            {
                    {"####.##.##.####", 0},
                    {"###..#####..###", 2},
                    {"###..####..####", 3},
                    {"#.##.####..#..#", 4},
                    {"####..###..####", 5},
                    {"####..####.####", 6},
                    {"###..#..#..#..#", 7},
                    {"####.#####.####", 8},
                    {"####.####..####", 9}
            };
    string str;
    cin >> n;
    cin >> str;
    int len = n / 5;
    vector<string> num;
    for (int i = 0; i < n; i += len) {
        num.push_back(str.substr(i, len));
    }
    for (int i = 0; i < len; ++i) {
        if (num[0][i] == '#') {
            if (i == len - 1 || (num[0][i + 1] == '.' && num[3][i] == '#')) {
                cout << 1;
                continue;
            }
            string tmp = "";
            for (int j = 0; j < 5; ++j) {
                tmp += num[j].substr(i, 3);
            }

            if (m.find(tmp) != m.end()) {
                cout << m[tmp];
                i += 3;
            }
        }
    }
}