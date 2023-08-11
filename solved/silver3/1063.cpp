#include "bits/stdc++.h"

using namespace std;

string dir[8] = {"R", "L", "T", "B", "RT", "LT", "RB", "LB"};
char b[8] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};

int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};

int getIdx(string s) {
    for (int i = 0; i < 8; i++) {
        if (dir[i] == s) return i;
    }
}

int getDir(char ch) {
    for (int i = 0; i < 8; ++i) {
        if (ch == b[i]) return i + 1;
    }
}

bool OOP(int nx, int ny) {
    return nx <= 0 || nx > 8 || ny <= 0 || ny > 8;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string king, stone;
    int n;
    cin >> king >> stone >> n;
    pair<int, int> king_d, stone_d;
    king_d.first = king[1] - '0';
    king_d.second = getDir(king[0]);

    stone_d.first = stone[1] - '0';
    stone_d.second = getDir(stone[0]);

    unordered_map<int, char> mp;
    mp[1] = 'A';
    mp[2] = 'B';
    mp[3] = 'C';
    mp[4] = 'D';
    mp[5] = 'E';
    mp[6] = 'F';
    mp[7] = 'G';
    mp[8] = 'H';


    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        int idx = getIdx(s);

        if (OOP(king_d.first + dx[idx], king_d.second + dy[idx])) continue;
        if (king_d.first + dx[idx] == stone_d.first && king_d.second + dy[idx] == stone_d.second) {
            if(!OOP(stone_d.first+dx[idx], stone_d.second+dy[idx])){
                king_d.first = king_d.first + dx[idx];
                king_d.second = king_d.second + dy[idx];
                stone_d.first = stone_d.first + dx[idx];
                stone_d.second = stone_d.second + dy[idx];
            }
        } else {
            king_d.first = king_d.first + dx[idx];
            king_d.second = king_d.second + dy[idx];
        }
        //
    }
    cout << mp[king_d.second] << king_d.first << '\n';
    cout << mp[stone_d.second] << stone_d.first;

}