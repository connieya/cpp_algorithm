#include "bits/stdc++.h"

#define MOD 1000

using namespace std;
int n, m;
vector<vector<int>> matrix;

vector<vector<int>> multiple_matrix(vector<vector<int>> a, vector<vector<int>> b) {
    vector<vector<int>> res;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int sum = 0;
            for (int k = 0; k < n; ++k) {
                sum += a[i][k] * b[k][j];
                sum %= MOD;
            }
            res[i][j] = sum;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << res[i][j] << ' ';
        }
        cout << '\n';
    }
    return res;
}

vector<vector<int>> matrix_power(int b) {
    if (b == 1) {
        return matrix;
    }
    vector<vector<int >> v = matrix_power(b / 2);
    v = multiple_matrix(v, v);
    if (b % 2 == 1) {
        return multiple_matrix(matrix, v);
    } else {
        return v;
    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << ' ';
        }
        cout << '\n';
    }
//    multiple_matrix(matrix, matrix);

//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < n; ++j) {
//            cout << ans[i][j] << ' ';
//        }
//        cout << '\n';
//    }

}