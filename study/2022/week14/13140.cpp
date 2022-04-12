#include "bits/stdc++.h"

using namespace std;
int alpha[8];
bool visited[8];

void dfs(int L, int n) {
    if (L == 7) {
        int a = alpha[0] * 10000 + alpha[6] * 1000 + alpha[4] * 100 + alpha[4] * 10 + alpha[2];
        int b = alpha[1] * 10000 + alpha[2] * 1000 + alpha[5] * 100 + alpha[4] * 10 + alpha[3];
        if (a + b == n) {
            printf("%7d\n", a);
            printf("+%6d\n", b);
            printf("-------\n");
            printf("%7d\n", n);;
            exit(0);
        }


        return;
    }
    for (int i = 0; i < 10; ++i) {
        if ((L == 0 || L == 1) && i == 0) continue;
        if (L == 4 && (alpha[2] + alpha[3]) % 10 != n % 10) continue;
        if (L == 5 && (alpha[4] * 2 % 10) + (alpha[2] + alpha[3]) / 10 != (n / 10) % 10) continue;
        if (!visited[i]) {
            visited[i] = true;
            alpha[L] = i;
            dfs(L + 1, n);
            visited[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    dfs(0, n);
    cout << "No Answer";
}