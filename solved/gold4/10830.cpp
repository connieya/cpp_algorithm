#include "bits/stdc++.h"
#define MOD 1000
using namespace std;

int arr[6][6];
int tmp[6][6];
int ans[6][6];

void matrix(int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            tmp[i][j] = arr[i][j];
        }
    }


    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int sum = 0;
            for (int k = 0; k < n; ++k) {
                sum += tmp[i][k]*tmp[k][j];
            }
            sum %= MOD;
            arr[i][j] = sum;
        }
    }
}

void matrix_answer(int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            tmp[i][j] = ans[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int sum = 0;
            for (int k = 0; k < n; ++k) {
                sum += arr[i][k]*tmp[k][j];
            }
            sum %= MOD;
            ans[i][j] = sum;
        }

    }
}

void input(int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> arr[i][j];
            arr[i][j] %= MOD;
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
    int n;
    long long b;
    cin >> n >> b;
    input(n);
    while (b > 0) {
        if (b % 2) {
            matrix_answer(n);
        }
        matrix(n);
        b /= 2;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
}