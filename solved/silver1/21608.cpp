#include "bits/stdc++.h"

#define INF 401

using namespace std;

typedef struct Student {
    int number;
    int favorite[4];
} Student;

Student student_list[INF];
int arr[21][21];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int n;

int calcFriend(int x, int y, int num) {
    int cnt = 0;
    for (int i = 0; i < 4; ++i) {
        int nx = dx[i] + x;
        int ny = dy[i] + y;
        if (nx < 1 || nx > n || ny < 1 || ny > n) continue;
        Student s = student_list[num];
        if (arr[nx][ny] == s.favorite[0] || arr[nx][ny] == s.favorite[1] || arr[nx][ny] == s.favorite[2] ||
            arr[nx][ny] == s.favorite[3]) {
            cnt++;
        }
    }
    return cnt;

}

void calcEmptyArea(vector<pair<int, int>> adjacent_list, int num) {
    int len = adjacent_list.size();
    int max = 0;
    vector<pair<int, int>> empty;
    int X, Y;
    for (int i = 0; i < len; ++i) {
        X = adjacent_list[i].first;
        Y = adjacent_list[i].second;
//        cout << X << ' ' << Y;
        int cnt = 0;
        for (int j = 0; j < 4; ++j) {
            int nx = X + dx[j];
            int ny = Y + dy[j];
            if (nx < 1 || nx > n || ny < 1 || ny > n) continue;
            if (arr[nx][ny] == 0) {
                cnt++;
            }
        }
//        cout << "  cnt =  " << cnt << '\n';
        if (cnt > max) {
            max = cnt;
            empty.clear();
            empty.push_back({X, Y});
        } else if (cnt == max) {
            empty.push_back({X, Y});
        }
    }
//    cout << "empty list ==============  " << '\n';
    for (int i = 0; i < empty.size(); ++i) {
//        cout << empty[i].first << ' ' << empty[i].second << '\n';
    }
    if (empty.size() == 1) {
        arr[empty[0].first][empty[0].second] = num;
        return;
    }
    arr[empty[0].first][empty[0].second] = num;


}

void solve(int n, int num) {
    int max = 0;
    vector<pair<int, int>> adjacent_list;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (arr[i][j] != 0) continue;
            int cnt = calcFriend(i, j, num);
            if (cnt > max) {
                max = cnt;
                adjacent_list.clear();
                adjacent_list.push_back({i, j});
            } else if (cnt == max) {
                adjacent_list.push_back({i, j});
            }
        }

    }
    for (int i = 0; i < adjacent_list.size(); ++i) {
//        cout << adjacent_list[i].first << ' ' << adjacent_list[i].second << '\n';
    }
    if (adjacent_list.size() == 1) {
        int X = adjacent_list[0].first;
        int Y = adjacent_list[0].second;
        arr[X][Y] = num;
        return;
    }
    // 2번 조건 ㄱㄱ
//    cout << "number 2 condition ~~ !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << '\n';
    calcEmptyArea(adjacent_list, num);

}

int calcScore(int x, int y, int num) {
    int cnt = 0;
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 1 || nx > n || ny < 1 || ny > n) continue;
        Student s = student_list[num];
        if (arr[nx][ny] == s.favorite[0] || arr[nx][ny] == s.favorite[1] || arr[nx][ny] == s.favorite[2] ||
            arr[nx][ny] == s.favorite[3]) {
            cnt++;
        }
    }
    if (cnt == 1) {
        return 1;
    }
    if (cnt == 2) {
        return 10;
    }
    if (cnt == 3) {
        return 100;
    }
    if (cnt == 0) return 0;
    return 1000;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int t = n * n;
    for (int i = 0; i < t; ++i) {
        int a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;
        student_list[a].number = a;
        student_list[a].favorite[0] = b;
        student_list[a].favorite[1] = c;
        student_list[a].favorite[2] = d;
        student_list[a].favorite[3] = e;
        solve(n, a);
//        cout << "**************************88" << '\n';
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int cnt =calcScore(i, j, arr[i][j]);
            ans += cnt;
        }
    }
    cout << ans;
}