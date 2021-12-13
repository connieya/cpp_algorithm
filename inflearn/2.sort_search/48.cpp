#include "stdio.h"
#include "iostream"
#define max(a,b) a > b ? a :b;
int arr[9][9];
int average[9];

int main()
{
    double sum;
    for (int i = 0; i < 9; ++i) {
        sum = 0;
        for (int j = 0; j < 9; ++j) {
            scanf("%d",&arr[i][j]);
            sum += arr[i][j];
        }
        average[i] = (sum / 9)+0.5;
    }
    for (int i = 0; i < 9; ++i) {
        int min = 215700000;
        int answer =0;
        for (int j = 0; j < 9; ++j) {
            int sub = abs(average[i]-arr[i][j]);
            if(min > sub) {
                min = sub;
                answer = arr[i][j];
            }else if(min == sub){
                answer = max(arr[i][j], answer);
            }
        }
        printf("%d %d\n",average[i],answer);
    }

}