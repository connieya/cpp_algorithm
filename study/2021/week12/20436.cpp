#include "bits/stdc++.h"

char keyboard[3][11] = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};


int main(void) {
    char hand[2];

    char str[101];
    scanf("%c %c", &hand[0], &hand[1]);
    int pos[2][2], ans = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; keyboard[i][j]; ++j) {
            for (int k = 0; k < 2; ++k) {
                if (keyboard[i][j] == hand[k]) {
                    pos[k][0] = i;
                    pos[k][1] = j;
                }
            }
        }
    }
    scanf("%s", str);
    for (int s = 0; str[s]; ++s, ans++) {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; keyboard[i][j]; ++j) {
                if (keyboard[i][j] == str[s]) {
                    int x = j > 4 || (j == 4 && i == 2);
                    ans += abs(pos[x][0] - i) + abs(pos[x][1] - j);
                    pos[x][0] = i;
                    pos[x][1] = j;
                }
            }
        }
    }
    printf("%d", ans);
}