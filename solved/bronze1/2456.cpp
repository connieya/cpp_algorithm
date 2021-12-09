#include "stdio.h"

int main(void) {
    int n, max = -1, a, b, c ,answer , square_max = -1;
    int sum[3] = {0};
    int square_sum[3] = {0};
    scanf("%d", &n);
    while (n--) {
        scanf("%d %d %d", &a, &b, &c);
        sum[0] +=a;
        sum[1] +=b;
        sum[2] +=c;
        square_sum[0] += a*a;
        square_sum[1] += b*b;
        square_sum[2] += c*c;
    }
    for (int i=0; i<3; i++){
        if(sum[i] > max){
            max = sum[i];
            square_max = square_sum[i];
            answer = i+1;
        } else if(sum[i] == max){
            if(square_sum[i] > square_max){
                answer = i+1;
                square_max = square_sum[i];
            }else if(square_sum[i] == square_max) {
                answer = 0;
            }
        }
    }
    printf("%d %d",answer,max);
}