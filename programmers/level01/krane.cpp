#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<vector<int >> board = {
            {0,0,0,0,0},
            {0,0,1,0,3},
            {0,2,5,0,1},
            {4,2,4,4,2},
            {3,5,1,3,1}
    };
    cout << board[0][2] << '\n';
    cout << board[1][2] << '\n';
    cout << board[3][4] << '\n';
    int move = 2;
    int len = board.size();
    for(int i=0; i<len; i++) {
        board[i][move-1];
    }
    stack<int> s;
    s.empty();
    cout << s.top();

}