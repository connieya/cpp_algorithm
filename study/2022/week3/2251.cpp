#include "bits/stdc++.h"

using namespace std;

const int MX = 201;
int A, B, C;

bool check[MX][MX][MX];

vector<int> BFS(void) {
    queue<pair<pair<int, int>, int>> q; //A, B, C
    q.push(make_pair(make_pair(0, 0), C));
    vector<int> result;
    while (!q.empty()) {
        int a = q.front().first.first;
        int b = q.front().first.second;
        int c = q.front().second;
        q.pop();
        if (check[a][b][c])
            continue;
        check[a][b][c] = true;
        if (a == 0)
            result.push_back(c);
        //a->b

        if (a + b > B) //넘치면 안되므로
            q.push(make_pair(make_pair(a + b - B, B), c));
        else
            q.push(make_pair(make_pair(0, a + b), c));

        //a->c
        if (a + c > C)
            q.push(make_pair(make_pair(a + b - C, b), C));
        else
            q.push(make_pair(make_pair(0, b), a + c));
        //b->a
        if (b + a > A)
            q.push(make_pair(make_pair(A, b + a - A), c));
        else
            q.push(make_pair(make_pair(b + a, 0), c));
        //b->c
        if (b + c > C)
            q.push(make_pair(make_pair(a, b + c - C), C));
        else
            q.push(make_pair(make_pair(a, 0), b + c));
        //c->a
        if (c + a > A)
            q.push(make_pair(make_pair(A, b), c + a - A));
        else
            q.push(make_pair(make_pair(c + a, b), 0));
        //c->b
        if (c + b > B)
            q.push(make_pair(make_pair(a, B), c + b - B));
        else
            q.push(make_pair(make_pair(a, c + b), 0));
    }
    return result;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> A >> B >> C;
    vector<int> ans = BFS();
    sort(ans.begin(), ans.end());
    for (int a: ans) {
        cout << a << ' ';
    }
}