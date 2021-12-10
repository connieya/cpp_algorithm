#include "stdio.h"

int main(void) {
    int t;
    char coin[8][4] = {"TTT", "TTH", "THT", "THH", "HTT", "HTH", "HHT", "HHH"};
    char result[41];
    scanf("%d", &t);
    while (t--) {
        int answer[8] = {0};
        scanf("%s", result);
        for (int i = 0; i < 38; i++) {
            for (int j = 0; j < 8; ++j) {
                if ((result[i] == coin[j][0]) && (result[i + 1] == coin[j][1]) && (result[i + 2] == coin[j][2])) {
                    answer[j]++;
                }
            }
        }
        for (int i=0; i<8; i++){
            printf("%d ",answer[i]);
        }
        printf("\n");
    }
}