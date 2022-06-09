#include "bits/stdc++.h"

using namespace std;

int c, num, ans;
int arr[101];

int tetris_one() {
    ans += c;
    for (int i = 0; i <= c - 4; ++i) {
        ans += (arr[i] == arr[i + 1] && arr[i + 1] == arr[i + 2] && arr[i + 2] == arr[i + 3]);
    }
    return ans;
}

int tetris_two() {
    for (int i = 0; i <= c - 2; ++i) {
        ans += (arr[i] == arr[i + 1]);
    }
    return ans;
}

int tetris_three() {
    for (int i = 0; i <= c - 3; ++i) {
        if (arr[i] == arr[i + 1] && arr[i + 1] + 1 == arr[i + 2]) {
            ans++;
            i++;
        }
    }
    for (int i = 0; i < c - 1; ++i) {
        if (arr[i] == arr[i + 1] + 1) {
            ans++;
        }
    }
    return ans;
}

int tetris_four() {
    for (int i = 0; i <= c - 3; ++i) {
        if ((arr[i] == arr[i + 1] + 1) && (arr[i + 1] == arr[i + 2])) {
            ans++;
            i++;
        }
    }
    for (int i = 0; i < c - 1; ++i) {
        if (arr[i] + 1 == arr[i + 1]) {
            ans++;
        }
    }
    return ans;
}

int tetris_five() {
    for (int i = 0; i <= c - 3; i++) {
        ans += (arr[i] == arr[i + 1] && arr[i + 1] == arr[i + 2]);
    }
    for (int i = 0; i < c - 1; ++i) {
        ans += (arr[i] + 1 == arr[i + 1]);
    }
    for (int i = 0; i < c - 1; ++i) {
        ans += (arr[i] == arr[i + 1] + 1);
    }
    for (int i = 1; i < c - 1; ++i) {
        ans += (arr[i] + 1 == arr[i - 1] && arr[i - 1] == arr[i + 1]);
    }
    return ans;
}

int tetris_six() {
    for (int i = 0; i <= c - 3; ++i) {
        ans += (arr[i] == arr[i + 1] && arr[i + 1] == arr[i + 2]);
    }
    for (int i = 0; i <= c - 2; ++i) {
        ans += (arr[i] == arr[i + 1]);
    }

    for (int i = 0; i <= c - 3; ++i) {
        if ((arr[i] + 1 == arr[i + 1]) && (arr[i + 1] == arr[i + 2])) {
            ans++;
        }
    }

    for (int i = 0; i <= c - 2; ++i) {
        ans += (arr[i] == arr[i + 1] + 2);
    }

    return ans;
}

int tetris_seven() {
    for (int i = 0; i <= c - 3; ++i) {
        ans += (arr[i] == arr[i + 1] && arr[i + 1] == arr[i + 2]);
    }

    for (int i = 0; i <= c - 2; ++i) {
        ans += ((arr[i] + 2) == arr[i + 1]);
    }

    for (int i = 0; i <= c - 3; ++i) {
        if ((arr[i] == arr[i + 1]) && (arr[i + 1] == arr[i + 2] + 1)) {
            ans++;
        }
    }
    for (int i = 0; i <= c - 2; ++i) {
        ans += (arr[i] == arr[i + 1]);
    }
    return ans;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> c >> num;
    for (int i = 0; i < c; ++i) {
        cin >> arr[i];
    }
    if (num == 1) {
        cout << tetris_one();
    } else if (num == 2) {
        cout << tetris_two();
    } else if (num == 3) {
        cout << tetris_three();
    } else if (num == 4) {
        cout << tetris_four();
    } else if (num == 5) {
        cout << tetris_five();
    } else if (num == 6) {
        cout << tetris_six();
    } else if (num == 7) {
        cout << tetris_seven();
    }
}