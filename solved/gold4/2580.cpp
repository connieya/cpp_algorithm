#include "bits/stdc++.h"

using namespace std;

vector<pair<int,int>> V;
bool row[9][10];
bool column[9][10];
bool group[9][10];
int arr[10][10];

int find_group(int x ,int y) {
    return x/3*3 + y/3;
}

void dfs(int L , int len){
    if (L == len) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                cout << arr[i][j] << ' ';
            }
            cout << '\n';
        }
        exit(0);
    }
    int r = V[L].first;
    int c = V[L].second;
    int g = find_group(r,c);
    for (int i = 1; i <= 9; ++i) {
        if (!row[r][i] && !column[c][i] && !group[g][i]){
            arr[r][c] = i;
            row[r][i] = column[c][i] = group[g][i] = true;
            dfs(L+1,len);
            row[r][i] = column[c][i] = group[g][i] = false;
        }

    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            int num;
            cin >> num;
            arr[i][j] = num;
            if (num == 0) {
                V.push_back({i,j});
            }else {
                int idx = find_group(i,j);
                row[i][num] = column[j][num] = group[idx][num] = true;
            }
        }
    }
    int len = V.size();
    dfs(0,len);
}