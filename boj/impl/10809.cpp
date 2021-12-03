#include "stdio.h"
int main(void){
    int i;
    char input[101];
    int alpha[26] = {-1,};
    for (int i =0; i<26; i++){
        alpha[i] = -1;
    }
    scanf("%s",input);
    for (i = 0; input[i] !='\0'; i++){
        if(alpha[input[i]-'a'] == -1){
            alpha[input[i]-'a'] = i;
        }
    }
    for (i =0; i<26; i++){
        printf("%d ",alpha[i]);
    }
}