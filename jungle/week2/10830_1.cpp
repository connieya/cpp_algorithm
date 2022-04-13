#include "bits/stdc++.h"

#define MOD 1000

using namespace std;
int arr[6][6];
int temp[6][6];
int ans[6][6];

void multiple_matrix(int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            temp[i][j] = arr[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int sum = 0;
            for (int k = 0; k < n; ++k) {
                sum += temp[i][k] * temp[k][j];
                sum %= MOD;
            }
            arr[i][j] = sum;
        }
    }
}

void multiple_matrix_ans(int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            temp[i][j] = ans[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int sum = 0;
            for (int k = 0; k < n; ++k) {
                sum += arr[i][k] * temp[k][j];
                sum %= MOD;
            }
            ans[i][j] = sum;
        }
    }

}

void input(int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                ans[i][j] = 1;
            }
        }
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    input(n);
    while (m > 0) {
        if (m % 2) {
            multiple_matrix_ans(n);
        }
        multiple_matrix(n);
        m /= 2;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }

}