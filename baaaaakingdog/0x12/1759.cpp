#include "stdio.h"
#include "algorithm"

using namespace std;
int L, C, index;
char alpha[16];
int mask[16];
char str[16];

bool isPossiblePassword() {
    int cnt = 0;
    for (int i = 0; i < L; ++i) {
        if (str[i] == 'a') {
            cnt++;
        } else if (str[i] == 'e') {
            cnt++;
        } else if (str[i] == 'i') {
            cnt++;
        } else if (str[i] == 'o') {
            cnt++;
        } else if (str[i] == 'u') {
            cnt++;
        }
    }
    if (cnt >=1 && L-cnt >=2){
        return true;
    }
    return false;
}

int main() {
    scanf("%d %d", &L, &C);
    getchar();
    for (int i = 0; i < C; ++i) {
        scanf(" %c", &alpha[i], C);
    }
    for (int i = L; i < C; ++i) {
        mask[i] = 1;
    }
    sort(alpha, alpha + C);
    do {
        index = 0;
        for (int i = 0; i < C; ++i) {
            if (!mask[i]) {
                str[index++] = alpha[i];
            }
        }
        if (isPossiblePassword()) {
            for (int i = 0; i < L; ++i) {
                printf("%c", str[i]);
            }
            printf("\n");
        }

    } while (next_permutation(mask, mask + C));
}