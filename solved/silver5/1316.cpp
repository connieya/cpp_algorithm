#include "stdio.h"
#include "cstring"

int main()
{
    int n ,cnt =0;
    scanf("%d",&n);
    char str[101];
    while (n--) {
        scanf("%s",str);
        int alpha[26] = {0,};
        int len = strlen(str);
        bool flag = true;
        for (int i=0; i<len-1; i++){
            alpha[str[i]-'a']++;
            if(str[i] != str[i+1] && str[i+1] > 0){
                flag = false;
                break;
            }
        }
        if(flag){
            cnt++;
        }
    }
    printf("%d",cnt);
}