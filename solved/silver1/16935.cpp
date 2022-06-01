#include "bits/stdc++.h"

using namespace std;

int arr[105][105];
int tmp[105][105];
int split_tmp[105][105];
int n, m, t;

void init() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            tmp[i][j] = arr[i][j];
        }
    }
}

void rotate_one() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
           arr[i][j] = tmp[n-1-i][j];
        }
    }
}

void rotate_two() {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            arr[i][j] = tmp[i][m-1-j];
        }
    }
}

void rotate_three() {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
           arr[i][j] = tmp[n-1-j][i];
        }
    }
    swap(n, m);

}

void rotate_four() {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            arr[i][j] = tmp[j][m - 1 - i];
        }
    }
    swap(n, m);

}

void rotate_five() {
    for (int i = n / 2; i < n; ++i) {
        for (int j = 0; j < m/2; ++j) {
            split_tmp[i][j] = arr[i][j];
        }
    }
    for (int i = n / 2; i < n; ++i) {
        for (int j = 0; j < m / 2; ++j) {
            arr[i][j] = arr[i][j + m / 2]; // 4  <- 3
        }
    }

    for (int i = 0; i < n / 2; ++i) {
        for (int j = m / 2; j < m; ++j) {
            arr[n / 2 + i][j] = arr[i][j]; // 3  <- 2
        }
    }

    for (int i = 0; i < n / 2; ++i) {
        for (int j = 0; j < m / 2; ++j) {
            arr[i][j + m / 2] = arr[i][j];// 2 <- 1
        }
    }
    for (int i = 0; i < n / 2; ++i) {
        for (int j = 0; j < m / 2; ++j) {
            arr[i][j] = split_tmp[i + n / 2][j]; //1 <- 4
        }
    }
}

void rotate_six() {
    for (int i = 0; i < n / 2; ++i) {
        for (int j = 0; j < m / 2; ++j) {
            split_tmp[i][j] = arr[i][j];
        }
    }

    for (int i = 0; i < n / 2; ++i) {
        for (int j = 0; j < m / 2; ++j) {
            arr[i][j] = arr[i][j+m/2]; // 1 <- 2
        }
    }

    for (int i = 0; i < n/2; ++i) {
        for (int j = m/2; j < m; ++j) {
            arr[i][j] = arr[i+n/2][j]; // 2 <- 3
        }
    }

    for (int i =n/2; i < n; ++i) {
        for (int j = 0; j < m/2; ++j) {
            arr[i][j+m/2] = arr[i][j]; // 3 <- 4;
        }
    }

    for (int i = 0; i < n/2; ++i) {
        for (int j = 0; j < m / 2; ++j) {
            arr[i+n/2][j] = split_tmp[i][j];
        }

    }
}

void rotate(int num) {
    if (num == 1) {
        rotate_one();
    } else if (num == 2) {
        rotate_two();
    } else if (num == 3) {
        rotate_three();
    } else if (num == 4) {
        rotate_four();
    } else if (num == 5) {
        rotate_five();
    } else {
        rotate_six();
    }

}

void output() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> t;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < t; ++i) {
        int num;
        cin >> num;
        init();
        rotate(num);
    }
    output();

}