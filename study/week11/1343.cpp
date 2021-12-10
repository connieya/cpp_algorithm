#include "stdio.h"

int main(void) {
    char board[55];
    int cnt = 0, idx = 0, flag = 1;
    scanf("%s", board);
    while (board[idx]) {
        if (board[idx] == 'X') {
            cnt++;
            if (cnt == 4) {
                board[idx] = board[idx - 1] = board[idx - 2] = board[idx - 3] = 'A';
                cnt = 0;
            }
        } else {
            if (cnt == 2) {
                board[idx - 1] = board[idx - 2] = 'B';
            } else if (cnt == 0) {
            } else {
                printf("-1\n");
                return 0;
            }
            cnt = 0;
        }

        idx++;
    }
    if (cnt == 2) {
        board[idx - 1] = board[idx - 2] = 'B';
    } else if(cnt !=0){
        flag = 0;
    }
    if (flag) {
        printf("%s",board);
    } else {
        printf("%d", -1);
    }
}