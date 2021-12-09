#include "stdio.h"

char input[1001][1001];
char map[1001][1001];
int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};

int main(void) {
    int n = 0;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", input[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (input[i][j] != '.') {
                map[i][j] = '*';
                continue;
            }

            int cnt = 0;
            for (int k = 0; k < 8; ++k) {
                int nx = dx[k] + i;
                int ny = dy[k] + j;
                if(nx >=0 && nx < n && ny>=0 && ny < n && input[nx][ny] != '.') {
                    cnt += input[nx][ny]-'0';
                }
            }
            map[i][j] = (cnt > 9) ? 'M' : (cnt+'0');
        }
    }
    for (int i = 0; i < n; ++i) {
        printf("%s\n",map[i]);
    }
}